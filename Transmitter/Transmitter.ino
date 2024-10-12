#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>

RF24 radio(9, 10);
int joystick[2];
const byte address[6] = "00001";

void setup() {
radio.begin();
radio.openWritingPipe(address);
radio.setPALevel(RF24_PA_MIN);
radio.stopListening();
}

void loop() {
joystick[0]=analogRead(A0);
joystick[1]=analogRead(A1);
joystick[0]=map(joystick[0],0,1023,0,180);
joystick[1]=map(joystick[1],0,1023,0,180);
radio.write(joystick,sizeof(joystick));}
