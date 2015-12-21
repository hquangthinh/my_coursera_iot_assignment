
// variable to hold sensor value
int sensorValue;
// variable to calibrate low value
int sensorLow = 0;
// variable to calibrate high value
int sensorHigh = 1023;
// LED pin
const int ledPin = 8;

void setup() {
  Serial.begin(9600);
  // Make the LED pin an output and turn it on
  pinMode(ledPin, OUTPUT);
  digitalWrite(ledPin, HIGH);

  // calibrate for the first five seconds after program runs
  while (millis() < 5000) {
    // record the maximum sensor value
    sensorValue = analogRead(A0);
    if (sensorValue > sensorHigh) {
      sensorHigh = sensorValue;
    }
    // record the minimum sensor value
    if (sensorValue < sensorLow) {
      sensorLow = sensorValue;
    }
  }
  // turn the LED off, signaling the end of the calibration period
  digitalWrite(ledPin, LOW);
}

void loop() {
  //read the input from A0 and store it in a variable
  sensorValue = analogRead(A0);

  // map the sensor values to a wide range of pitches
  int adjustedLightLevel = map(sensorValue, sensorLow, sensorHigh, 0, 100);
  
  Serial.println(sensorValue);
  Serial.println(adjustedLightLevel);

  if(adjustedLightLevel < 10){
    digitalWrite(ledPin, HIGH);
  }else{
    digitalWrite(ledPin, LOW);
  }

  // wait for a moment
  delay(1000);
}
