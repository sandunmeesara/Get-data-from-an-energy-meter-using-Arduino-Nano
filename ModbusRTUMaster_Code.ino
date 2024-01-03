#include <SoftwareSerial.h>
#include <ModbusRTUMaster.h>

const uint8_t rxPin = 3;
const uint8_t txPin = 2;
const uint8_t dePin = 4;

SoftwareSerial mySerial(rxPin, txPin);
ModbusRTUMaster modbus(mySerial, dePin); // serial port, driver enable pin for rs-485 (optional)

uint16_t holdingRegisters[10];
uint32_t total,x;

void setup() {
  Serial.begin(9600);
  modbus.begin(9600); // baud rate, config (optional)

}

void loop() {
  
  modbus.readHoldingRegisters(1, 0x01, holdingRegisters,1);
  x = holdingRegisters[0];
  Serial.println("Passcode : " + String(x) + "");

  modbus.readHoldingRegisters(1, 0x07, holdingRegisters,1);
  x = holdingRegisters[0];
  Serial.println("Potentia1 transformer ratio (urat) : " + String(x) + "");

  modbus.readHoldingRegisters(1, 0x0B, holdingRegisters,1);
  x = holdingRegisters[0];
  Serial.println("Meter type (meter type) : " + String(x) + "");

  modbus.readHoldingRegisters(1, 0x2008, holdingRegisters,2);
  total = ((uint32_t)holdingRegisters[0]<<16) | holdingRegisters[1];
  String hexString = String(total, HEX);
  float floatResult = hexToFloat(hexString);
  floatResult = floatResult * 0.1;
  Serial.println("Phase phase voltage (ub) : " + String(floatResult) + "v");
  
  Serial.println("--------------------------");
  delay(1000);

}


String decimalToHex(String decimalString) {
  long decimalValue = atol(decimalString.c_str()); // Convert decimal string to long
  char hexBuffer[9]; // Buffer for storing hexadecimal representation (8 characters + null terminator)
  snprintf(hexBuffer, sizeof(hexBuffer), "%08lX", decimalValue); // Convert long to hexadecimal string
  return String(hexBuffer);
}

bool isValidHex(String hexString) {
  for (char c : hexString) {
    if (!isHexadecimalDigit(c)) {
      return false;
    }
  }
  return hexString.length() > 0;
}

bool isHexadecimalDigit(char c) {
  return (c >= '0' && c <= '9') || (c >= 'A' && c <= 'F') || (c >= 'a' && c <= 'f');
}

float hexToFloat(String hexString) {
  unsigned long hexInt = strtoul(hexString.c_str(), NULL, 16); // Convert hexadecimal string to unsigned long
  float result;
  memcpy(&result, &hexInt, sizeof(result)); // Copy the raw bytes into a float variable
  return result;
}

