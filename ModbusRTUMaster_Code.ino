#include <SoftwareSerial.h>
#include <ModbusRTUMaster.h>

const uint8_t rxPin = 3;
const uint8_t txPin = 2;
const uint8_t dePin = 4;

SoftwareSerial mySerial(rxPin, txPin);
ModbusRTUMaster modbus(mySerial, dePin); // serial port, driver enable pin for rs-485 (optional)

//bool coils[4];
//bool discreteInputs[4];
uint16_t holdingRegisters[10];
//uint16_t inputRegisters[4];
uint32_t total,x;

void setup() {
  Serial.begin(9600);
  modbus.begin(9600); // baud rate, config (optional)

}

void loop() {
  
  //modbus.writeMultipleCoils(1, 0, coils, 2);                       // slave id, starting data address, bool array of coil values, number of coils to write
  //modbus.writeMultipleHoldingRegisters(1, 0, holdingRegisters, 2); // slave id, starting data address, unsigned 16 bit integer array of holding register values, number of holding registers to write
  //modbus.readDiscreteInputs(1, 0, discreteInputs, 2);              // slave id, starting data address, bool array to place discrete input values, number of discrete inputs to read
  //modbus.readInputRegisters(1, 0, inputRegisters, 2);              // slave id, starting data address, unsigned 16 bit integer array to place input register values, number of input registers to read



  modbus.readHoldingRegisters(1, 0x01, holdingRegisters,1);
  x = holdingRegisters[0];
  Serial.println("Passcode : " + String(x) + "");

  modbus.readHoldingRegisters(1, 0x07, holdingRegisters,1);
  x = holdingRegisters[0];
  Serial.println("Potentia1 transformer ratio (urat) : " + String(x) + "");

  modbus.readHoldingRegisters(1, 0x0B, holdingRegisters,1);
  x = holdingRegisters[0];
  Serial.println("Meter type (meter type) : " + String(x) + "");

  modbus.readHoldingRegisters(1, 0x2044, holdingRegisters,2);
  total = ((uint32_t)holdingRegisters[0]<<16) | holdingRegisters[1];
  //float floatValue;
  //memcpy(&floatValue,&total,sizeof(float));

  //x = holdingRegisters[]
  //x = holdingRegisters[0]<<16 | holdingRegisters[1];
  Serial.println("Line line voltage (uab) : " + String(total) + "v");
  
  for(int i=0;i<2;i++){
    Serial.println("Code: " + String(holdingRegisters[i]) + "");
  }
  
  Serial.println("--------------------------");
  delay(1000);

}
