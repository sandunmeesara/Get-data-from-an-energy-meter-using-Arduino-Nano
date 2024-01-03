#include <SoftwareSerial.h>
#include <ModbusRTUMaster.h>

const uint8_t rxPin = 3;
const uint8_t txPin = 2;
const uint8_t dePin = 4;

SoftwareSerial mySerial(rxPin, txPin);
ModbusRTUMaster modbus(mySerial, dePin); // serial port, driver enable pin for rs-485 (optional)

uint16_t holdingRegisters[2];
uint32_t total,x;
int dataAddress;
float floatResult;

void setup() {
  Serial.begin(9600);
  modbus.begin(9600); // baud rate, config (optional)

}

void loop() {

  //print Software version
  dataAddress = 0x00;
  Serial.println("Software version : " + String(readIntData(dataAddress)));
 
  //print Programming Code
  dataAddress = 0x01;
  Serial.println("Programming Code : " + String(readIntData(dataAddress)));

  //print Network Selection
  dataAddress = 0x03;
  Serial.println("Network Selection : " + String(readIntData(dataAddress)));
  
  //print Current Transformer Rate(IrAt)
  dataAddress = 0x06;
  Serial.println("Current Transformer Rate(IrAt) : " + String(readIntData(dataAddress)));

  //print Voltage Transformer Rate(UrAt)
  dataAddress = 0x07;
  Serial.println("Voltage Transformer Rate(UrAt) : " + String(readIntData(dataAddress)));

  //print Rotating Display Time(s)
  dataAddress = 0x0A;
  Serial.println("Rotating Display Time(s) : " + String(readIntData(dataAddress)));

  //print Backlight Time Control(s)
  dataAddress = 0x0B;
  Serial.println("Backlight Time Control(s) : " + String(readIntData(dataAddress)));

  //print Protocol Switching
  dataAddress = 0x2C;
  Serial.println("Protocol Switching : " + String(readIntData(dataAddress)));

  //print Communication Baud Rate
  dataAddress = 0x2D;
  Serial.println("Communication Baud Rate : " + String(readIntData(dataAddress)));

  //print Communication Address
  dataAddress = 0x2E;
  Serial.println("Communication Address : " + String(readIntData(dataAddress)));


  //print Three Phase line voltage(Uab)
  dataAddress = 0x2000;
  floatResult = readFloatData(dataAddress) * 0.1;
  Serial.println("Three Phase line voltage(Uab) : " + String(floatResult) + "v");

  //print Three Phase line voltage(Ubc)
  dataAddress = 0x2002;
  floatResult = readFloatData(dataAddress) * 0.1;
  Serial.println("Three Phase line voltage(Ubc) : " + String(floatResult) + "v");

  //print Three Phase line voltage(Uca)
  dataAddress = 0x2004;
  floatResult = readFloatData(dataAddress) * 0.1;
  Serial.println("Three Phase line voltage(Uca) : " + String(floatResult) + "v");

  //print Three Phase Phase voltage(Ua)
  dataAddress = 0x2006;
  floatResult = readFloatData(dataAddress) * 0.1;
  Serial.println("Three Phase Phase voltage(Ua) : " + String(floatResult) + "v");

  //print Three Phase Phase voltage(Ub)
  dataAddress = 0x2008;
  floatResult = readFloatData(dataAddress) * 0.1;
  Serial.println("Three Phase Phase voltage(Ub) : " + String(floatResult) + "v");

  //print Three Phase Phase voltage(Uc)
  dataAddress = 0x200A;
  floatResult = readFloatData(dataAddress) * 0.1;
  Serial.println("Three Phase Phase voltage(Uc) : " + String(floatResult) + "v");

  //print Three Phase Current(Ia)
  dataAddress = 0x200C;
  floatResult = readFloatData(dataAddress) * 0.001;
  Serial.println("Three Phase Current(Ia) : " + String(floatResult) + "A");

  //print Three Phase Current(Ib)
  dataAddress = 0x200E;
  floatResult = readFloatData(dataAddress) * 0.001;
  Serial.println("Three Phase Current(Ib) : " + String(floatResult) + "A");

  //print Three Phase Current(Ic)
  dataAddress = 0x2010;
  floatResult = readFloatData(dataAddress) * 0.001;
  Serial.println("Three Phase Current(Ic) : " + String(floatResult) + "A");

  //print Combined Active Power(Pt)
  dataAddress = 0x2012;
  floatResult = readFloatData(dataAddress) * 0.1;
  Serial.println("Combined Active Power(Pt) : " + String(floatResult) + "W");

  //print A Phase active power(Pa)
  dataAddress = 0x2014;
  floatResult = readFloatData(dataAddress) * 0.1;
  Serial.println("A Phase active power(Pa) : " + String(floatResult) + "W");

  //print B Phase active power(Pb)
  dataAddress = 0x2016;
  floatResult = readFloatData(dataAddress) * 0.1;
  Serial.println("B Phase active power(Pb) : " + String(floatResult) + "W");

  //print C Phase active power(Pc)
  dataAddress = 0x2018;
  floatResult = readFloatData(dataAddress) * 0.1;
  Serial.println("C Phase active power(Pc) : " + String(floatResult) + "W");

  //print C Phase active power(Pc)
  dataAddress = 0x2018;
  floatResult = readFloatData(dataAddress) * 0.1;
  Serial.println("C Phase active power(Pc) : " + String(floatResult) + "W");

  //print Combined Reactive Power(Qt)
  dataAddress = 0x201A;
  floatResult = readFloatData(dataAddress) * 0.1;
  Serial.println("Combined Reactive Power(Qt) : " + String(floatResult) + "var");

  //print A Phase Reactive Power(Qa)
  dataAddress = 0x201C;
  floatResult = readFloatData(dataAddress) * 0.1;
  Serial.println("A Phase Reactive Power(Qa) : " + String(floatResult) + "var");

  //print B Phase Reactive Power(Qb)
  dataAddress = 0x201E;
  floatResult = readFloatData(dataAddress) * 0.1;
  Serial.println("B Phase Reactive Power(Qb) : " + String(floatResult) + "var");

  //print C Phase Reactive Power(Qc)
  dataAddress = 0x2020;
  floatResult = readFloatData(dataAddress) * 0.1;
  Serial.println("C Phase Reactive Power(Qc) : " + String(floatResult) + "var");

  //print Combined Power Factor(PFt)
  dataAddress = 0x202A;
  floatResult = readFloatData(dataAddress) * 0.001;
  Serial.println("Combined Power Factor(PFt) : " + String(floatResult));

  //print A Phase Power Factor(PFa)
  dataAddress = 0x202C;
  floatResult = readFloatData(dataAddress) * 0.001;
  Serial.println("A Phase Power Factor(PFa) : " + String(floatResult));

  //print B Phase Power Factor(PFb)
  dataAddress = 0x202E;
  floatResult = readFloatData(dataAddress) * 0.001;
  Serial.println("B Phase Power Factor(PFb) : " + String(floatResult));

  //print C Phase Power Factor(PFc)
  dataAddress = 0x2030;
  floatResult = readFloatData(dataAddress) * 0.001;
  Serial.println("C Phase Power Factor(PFc) : " + String(floatResult));

  //print Frequency
  dataAddress = 0x2044;
  floatResult = readFloatData(dataAddress) * 0.01;
  Serial.println("Frequency : " + String(floatResult) + "Hz");

  //print Forward Total Active Energy 
  dataAddress = 0x101E;
  floatResult = readFloatData(dataAddress);
  Serial.println("Forward total active energy  : " + String(floatResult) + "kWh");

  //print Reverse Total Active Energy 
  dataAddress = 0x1028;
  floatResult = readFloatData(dataAddress);
  Serial.println("Reverse total active energy  : " + String(floatResult) + "kWh");

  //print Total reactive energy of the first quadrant 
  dataAddress = 0x1032;
  floatResult = readFloatData(dataAddress);
  Serial.println("Total reactive energy of the first quadrant : " + String(floatResult) + "kvarh");

  //print Total reactive energy of the second quadrant 
  dataAddress = 0x103C;
  floatResult = readFloatData(dataAddress);
  Serial.println("Total reactive energy of the second quadrant : " + String(floatResult) + "kvarh");

  //print Total reactive energy of the third quadrant 
  dataAddress = 0x1046;
  floatResult = readFloatData(dataAddress);
  Serial.println("Total reactive energy of the third quadrant : " + String(floatResult) + "kvarh");

  //print Total reactive energy of the fourth quadrant 
  dataAddress = 0x1050;
  floatResult = readFloatData(dataAddress);
  Serial.println("Total reactive energy of the fourth quadrant : " + String(floatResult) + "kvarh");
  
  Serial.println("---------------------------------------");
  delay(5000);

}

uint16_t readIntData(int dataAddress){
  modbus.readHoldingRegisters(1, dataAddress, holdingRegisters,1);
  x = holdingRegisters[0];
  return x;
}

float readFloatData(int dataAddress){
  modbus.readHoldingRegisters(1, 0x2008, holdingRegisters,2);
  total = ((uint32_t)holdingRegisters[0]<<16) | holdingRegisters[1];
  String hexString = String(total, HEX);
  float floatResult = hexToFloat(hexString);
  return floatResult;
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

