#include <SoftwareSerial.h>
#include <ModbusRTUMaster.h>

const uint8_t rxPin = 3;
const uint8_t txPin = 2;
const uint8_t dePin = 4;

SoftwareSerial mySerial(rxPin, txPin);
ModbusRTUMaster modbus(mySerial, dePin); // serial port, driver enable pin for rs-485 (optional)

//bool coils[4];
//bool discreteInputs[4];
uint16_t holdingRegisters[2];
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

  modbus.readHoldingRegisters(1, 0x02, holdingRegisters, 2);
  total = (holdingRegisters[0] << 16) | holdingRegisters[1];
  x = total/1000;
  Serial.println("L1 Current : " + String(x) + "A");

  modbus.readHoldingRegisters(1, 0x28, holdingRegisters, 2);
  total = (holdingRegisters[0] << 16 ) | holdingRegisters[1];
  x = total/10;
  Serial.println("Frequency : " + String(x) + "Hz");

  modbus.readHoldingRegisters(1, 0x2A, holdingRegisters, 2);
  total = (holdingRegisters[0] << 16 ) | holdingRegisters[1];
  x = total/10;
  Serial.println("L1 - L2 Voltage : " + String(x) + "V");

  Serial.println("--------------------------");
  delay(1000);

}
