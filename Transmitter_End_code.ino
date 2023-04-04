// Here ESP32 Node MCU is used since it has in-built Wifi Module
#include <RCSwitch.h>

RCSwitch mySwitch = RCSwitch(); // initialize RCSwitch library
int tx_pin =16; // GPIO4 on ESP32 Dev Kit 1 board

void setup() {
  Serial.begin(9600);
  mySwitch.enableTransmit(tx_pin); // Set the interrupt number for the transmitter
  mySwitch.setPulseLength(400); // Set the pulse length (in microseconds)
  mySwitch.setRepeatTransmit(3); // Set the number of times to repeat the signal
}

void loop() {
  mySwitch.send(12345, 24); // Send the signal with the value 12345 and 24-bit protocol
  delay(1000); // Wait for 1 second before sending the next signal
}
