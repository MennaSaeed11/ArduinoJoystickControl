#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>
#include <Servo.h>
RF24 radio(9, 10);
Servo myservo1,myservo2;
const byte address[6] = "00001";
int joystick[2]={90,90};

void setup() {
Serial.begin(9600);
radio.begin();
radio.openReadingPipe(0, address);
radio.setPALevel(RF24_PA_MIN);
radio.startListening();
myservo1.attach(6);
myservo2.attach(5);
}

void loop() {
if ( radio.available()) {
while (radio.available()) {
radio.read(joystick,sizeof(joystick));
Serial.print("VRX= ");
Serial.print(joystick[0]);
Serial.print(" VRY= ");
Serial.println(joystick[1]);
myservo1.write(joystick[0]);
myservo2.write(joystick[1]);
}
}
}
