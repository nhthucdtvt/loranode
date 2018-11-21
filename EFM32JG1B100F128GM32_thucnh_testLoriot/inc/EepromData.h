#ifndef INC_EEPROMDATA_H_
#define INC_EEPROMDATA_H_

int joinedChecking();
void getStoredNwsKey(uint8_t *result);
void getStoredAppsKey(uint8_t *result);
uint16_t getStoredDevNonce();
uint32_t getStoredNetID();
uint32_t getStoredDevAddr();
uint32_t getStoredUplCounter();
uint32_t getStoredDownlCounter();

void setJoinedChecking();
void clearJoinedChecking();
void setStoredNwsKey(uint8_t *result);
void setStoredAppsKey(uint8_t *result);
void setStoredDevNonce(uint16_t inputDevNonce);
void setStoredNetID(uint32_t inputNetId);
void setStoredDevAddr(uint32_t inputDevAddr);
void setStoredUplCounter(uint32_t inputUplCounter);
void setStoredDownlCounter(uint32_t inputDownlCounter);

void convert32to8 (uint32_t inputNumber, uint8_t *result);
void convert16to8 (uint16_t inputNumber, uint8_t *result);
uint32_t reverse8BitsArrayTo32 (uint8_t *inputArray);
uint16_t reverse8BitsArrayTo16 (uint8_t *inputArray);

#endif
