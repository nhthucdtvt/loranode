/*
 * Compatible with:
 * SODAQ MBILI
 * SODAQ Autonomo
 * SODAQ ONE
 * SODAQ ONE BETA
 * SODAQ EXPLORER
 */

#include "Arduino.h"
#include <Sodaq_RN2483.h>
#include <Sodaq_LIS3DE.h>
#include <Sodaq_UBlox_GPS.h>

Sodaq_LIS3DE accelerometer;

// Print the debug information on the SerialUSB 
#define USB SerialUSB
#define debugSerial SERIAL_PORT_MONITOR

#define loraSerial Serial1

#define ARRAY_DIM(arr)  (sizeof(arr) / sizeof(arr[0]))

// The interrupt pin for the Accelerometer is attached to D4
#define ACC_INT_PIN 4

// Threshold for interrupt trigger
double threshold = -0.8;
int now = millis();
unsigned long sendIntervalTime = 0;
boolean sendActivate = true;
// List of interval values to be used in loop()
// to measure how long it takes to get a fix.
uint32_t intervals[] = 
{

        // Do a few tests with 1 minute delay
        1UL * 60 * 1000,
        1UL * 60 * 1000,
        1UL * 60 * 1000,

        // Try a few longer delays
        2UL * 60 * 1000,
        2UL * 60 * 1000,
        5UL * 60 * 1000,
        5UL * 60 * 1000,

        // Slowly increase the delays
        15UL * 60 * 1000,
        30UL * 60 * 1000,
        1UL * 60 * 60 * 1000,
        3UL * 60 * 60 * 1000,
        4UL * 60 * 60 * 1000,
        8UL * 60 * 60 * 1000,
};
size_t interval_ix = 0;

void find_fix(uint32_t delay_until);
void do_flash_led(int pin);

// OTAA
uint8_t DevEUI[8] = { 0x47, 0x45, 0x4f, 0x30, 0x30, 0x30, 0x31, 0x30 };
uint8_t AppEUI[8] = { 0x47, 0x45, 0x4f, 0x31, 0x31, 0x32, 0x31, 0x37 };
uint8_t AppKey[16] = { 0x44, 0x46, 0x4d, 0x47, 0x52, 0x4f, 0x55, 0x50, 0x47, 0x45, 0x4f, 0x31, 0x31, 0x32, 0x31, 0x37 };

void setupGPS()
{
    delay(3000);
    while (!SerialUSB) {
        // Wait for USB to connect
    }

    debugSerial.begin(57600);

    digitalWrite(LED_RED, HIGH);
    pinMode(LED_RED, OUTPUT);
    digitalWrite(LED_GREEN, HIGH);
    pinMode(LED_GREEN, OUTPUT);
    digitalWrite(LED_BLUE, HIGH);
    pinMode(LED_BLUE, OUTPUT);

    do_flash_led(LED_RED);
    do_flash_led(LED_GREEN);
    do_flash_led(LED_BLUE);

    debugSerial.println("SODAQ LoRaONE test_gps is starting ...");

    sodaq_gps.init(GPS_ENABLE);

    // This is for debugging to see more details, more messages
    // Use this in combination with setDiag()
    //sodaq_gps.setMinNumOfLines(10);

    // Uncomment the next line if you want to see the incoming $GPxxx messages
    //sodaq_gps.setDiag(MySerial);

    // First time finding a fix
    //find_fix(0);
}


void setupLIS3DE()
{  
      USB.begin(9600);
    while ((!USB) && (millis() < 10000)) {
        // Wait 10 seconds for the Serial Monitor
    }
    // Start the I2C bug
    Wire.begin();

    pinMode(ACCEL_INT1, INPUT);
    attachInterrupt(ACCEL_INT1, interrupt_event, CHANGE);

    // Configure EIC to use GCLK1 which uses XOSC32K, XOSC32K is already running in standby
    // This has to be done after the first call to attachInterrupt()
    GCLK->CLKCTRL.reg = GCLK_CLKCTRL_ID(GCM_EIC) |
        GCLK_CLKCTRL_GEN_GCLK1 |
        GCLK_CLKCTRL_CLKEN;

    accelerometer.enable(true,
        Sodaq_LIS3DE::NormalLowPower10Hz,
        Sodaq_LIS3DE::XYZ,
        Sodaq_LIS3DE::Scale8g,
        true);
    
    delay(100);

    accelerometer.enableInterrupt1(
        Sodaq_LIS3DE::XHigh | Sodaq_LIS3DE::XLow | Sodaq_LIS3DE::YHigh | Sodaq_LIS3DE::YLow | Sodaq_LIS3DE::ZHigh | Sodaq_LIS3DE::ZLow,
        20 * 8.0 / 100.0,
        0,
        Sodaq_LIS3DE::MovementRecognition);
}

void setupLoRaOTAA()
{
  if (LoRaBee.initOTA(loraSerial, DevEUI, AppEUI, AppKey, false))
  {
    debugSerial.println("Communication to LoRaBEE successful.");
  }
  else
  {
    debugSerial.println("OTAA Setup failed!");
  }
}

void setup() 
{
  // Configure the button as an input and enable the internal pull-up resistor
  pinMode(BUTTON, INPUT_PULLUP);
  pinMode(LED_GREEN, OUTPUT);

  // setup accelerometer
  setupLIS3DE();
  
  // setup GPS
  setupGPS();
  

  //Set baud rate
  debugSerial.begin(57600);
  loraSerial.begin(LoRaBee.getDefaultBaudRate());

  // Debug output from LoRaBee
  // LoRaBee.setDiag(debugSerial); // optional

  //connect to the LoRa Network
  setupLoRa();

  sendIntervalTime = millis();
  // Print out
  debugSerial.println();
  debugSerial.println("Setup is finished!!!");
  debugSerial.println("=====================================================");
}

void setupLoRa(){
  // OTAA
  setupLoRaOTAA();
  LoRaBee.setSpreadingFactor(9);
}

void sendPacket(String packet){
  switch (LoRaBee.send(1, (uint8_t*)packet.c_str(), packet.length()))
    {
    case NoError:
      debugSerial.println("Successful transmission.");
      sendActivate = false;
      delay(60000);
      sendIntervalTime = millis();
      break;
    case NoResponse:
      debugSerial.println("There was no response from the device.");
      setupLoRa();
      break;
    case Timeout:
      debugSerial.println("Connection timed-out. Check your serial connection to the device! Sleeping for 20sec.");
      delay(20000);
      break;
    case PayloadSizeError:
      debugSerial.println("The size of the payload is greater than allowed. Transmission failed!");
      break;
    case InternalError:
      debugSerial.println("Oh No! This shouldn't happen. Something is really wrong! Try restarting the device!\r\nThe network connection will reset.");
      setupLoRa();
      break;
    case Busy:
      debugSerial.println("The device is busy. Sleeping for 60 extra seconds.");
      delay(60000);
      break;
    case NetworkFatalError:
      debugSerial.println("There is a non-recoverable error with the network connection. You should re-connect.\r\nThe network connection will reset.");
      setupLoRa();
      break;
    case NotConnected:
      debugSerial.println("The device is not connected to the network. Please connect to the network before attempting to send data.\r\nThe network connection will reset.");
      delay(60000);
      setupLoRa();
      break;
    case NoAcknowledgment:
      debugSerial.println("There was no acknowledgment sent back!");
      // When you this message you are probaly out of range of the network.
      break;
    default:
      break;
    }
}

void read_AccMeter()
{
    USB.print("x = ");
    USB.print(accelerometer.getX());

    USB.print("\ty = ");
    USB.print(accelerometer.getY());

    USB.print("\tz = ");
    USB.println(accelerometer.getZ());
}

void interrupt_event()
{
    // Do not print in an interrupt event when sleep is enabled.
    sendActivate = true;
    debugSerial.println("Board flipped");
}

/*!
 * Find a GPS fix, but first wait a while
 */
void find_fix(uint32_t delay_until)
{
    debugSerial.println(String("delay ... ") + delay_until + String("ms"));
    delay(delay_until);

    uint32_t start = millis();
    uint32_t timeout = 900L * 1000;
    debugSerial.println(String("waiting for fix ..., timeout=") + timeout + String("ms"));
    if (sodaq_gps.scan(false, timeout)) {
        debugSerial.println(String(" time to find fix: ") + (millis() - start) + String("ms"));
        debugSerial.println(String(" datetime = ") + sodaq_gps.getDateTimeString());
        debugSerial.println(String(" lat = ") + String(sodaq_gps.getLat(), 7));
        debugSerial.println(String(" lon = ") + String(sodaq_gps.getLon(), 7));
        debugSerial.println(String(" num sats = ") + String(sodaq_gps.getNumberOfSatellites()));
    } else {
        debugSerial.println("No Fix");
    }
}

void do_flash_led(int pin)
{
    for (size_t i = 0; i < 2; ++i) {
        delay(100);
        digitalWrite(pin, LOW);
        delay(100);
        digitalWrite(pin, HIGH);
    }
}


void loop() 
{

  // Button pressed
  if (digitalRead(BUTTON) == HIGH) {
    digitalWrite(LED_GREEN, HIGH);
  } else {
    digitalWrite(LED_GREEN, LOW);
    debugSerial.println("I'm here");
    sendActivate = true; 
  }

  // Schedule Tx every 1 hour
  if (millis() - sendIntervalTime > 3600000) {
    sendActivate = true;
    sendIntervalTime = millis();
  }
  
  if (sendActivate == true) {
    // Print sensor readings
    read_AccMeter();

    // Get GPS value
    find_fix(0);

    delay(10000); 
    
    String packet = String(" lat = ") + String(sodaq_gps.getLat(), 7) + String(" lon = ") + String(sodaq_gps.getLon(), 7);
    sendPacket(packet);
  }
}

