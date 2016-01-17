#include <EEPROM.h>

// the setup routine runs once when you press reset:
void setup() {
  Serial.begin(9600);
}

// the loop routine runs over and over again forever:
void loop() {
  while(Serial.available()) {
    String command = Serial.readString();
    Serial.println(command);
    if(command.startsWith("read")){
      performRead(command);
    }else if(command.startsWith("write")) {
      performWrite(command);
    }
  }
}

void performRead(String command) {
    int pos = command.indexOf(" ");
    if(pos == -1) {
      Serial.println("Invalid command syntax for read operation. Example : read 10");
      return;
    }
    String addrString = command.substring(pos);
    addrString.trim();
    int addr = addrString.toInt();
    if(addr < 0 || addr >= EEPROM.length()){
        Serial.println("Invalid EEPROM address to read " + addrString);
        return;
    }
    int val = EEPROM.read(addr);
    Serial.println("Value at address " + addrString + " = " + val);
}

void performWrite(String command) {
  int pos = command.indexOf(" ");
    if(pos == -1) {
      Serial.println("Invalid command syntax for write operation. Example: write 10 20");
      return;
    }
    String strParams = command.substring(pos);
    strParams.trim();
    pos = strParams.indexOf(" ");
    if(pos == -1){
      Serial.println("Invalid write command parameters.");
      return;
    }
    Serial.println("DEBUG: strParams=" + strParams);
    String strAddr = strParams.substring(0, pos);
    String strVal = strParams.substring(pos);
    Serial.println("DEBUG: strAddr=" + strAddr);
    Serial.println("DEBUG: strVal=" + strVal);
    strAddr.trim();
    strVal.trim();
    int addrToWrite = strAddr.toInt();
    int val = strVal.toInt();
    if(addrToWrite < 0 || addrToWrite >= EEPROM.length()){
        Serial.println("Invalid EEPROM address to write " + strAddr);
        return;
    }
    Serial.println("Write value " + String(val) + " to address " + strAddr);
    EEPROM.write(addrToWrite, val);
    Serial.println("Write ok");
}
