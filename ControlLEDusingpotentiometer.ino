//  _ ___ _______     ___ ___ ___  ___ _   _ ___ _____ ___ 
// / |_  )__ /   \   / __|_ _| _ \/ __| | | |_ _|_   _/ __| 
// | |/ / |_ \ |) | | (__ | ||   / (__| |_| || |  | | \__ \ 
// |_/___|___/___/   \___|___|_|_\\___|\___/|___| |_| |___/ 
// 
// Control LED using potentiometer
// 
// Made by Thinh Hua Quang
// License: CC-BY-SA 3.0
// Downloaded from: https://123d.circuits.io/circuits/1506766-control-led-using-potentiometer

#include <Servo.h>

Servo myservo;  

int brightness = 0;
int led = 9;
// the setup routine runs once when you press reset:
void setup() {
  
  Serial.begin(9600);
  //pinMode(led, OUTPUT);
  myservo.attach(led);
}

// the loop routine runs over and over again forever:
void loop() {
  brightness = analogRead(A0);
  brightness = map(brightness, 0, 1023, 0, 254);
  
  Serial.print("brightness = ");
  Serial.print(brightness);
  Serial.print("\n");
  
  //analogWrite(led, brightness);
  myservo.write(brightness);
  
  delay(1000);              
}
