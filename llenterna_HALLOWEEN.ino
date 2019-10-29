
/*
  This projects is a Jack'o Lantern that glows in the dark when someone aproach. To do so we used a photoresistor 
  and a HCSR04 sensor wich, measures distances, this way when the outside light is below 100 and the destance is less than 50mm
  the lantern glows. 

 Adriano, Nacho, Guillem
*/
#include <HCSR04.h>//imports the HCRR04 Library in order to run the sensor
UltraSonicDistanceSensor distanceSensor(13, 12);//define the pins for the HCSR04
int led = 9;//define the led that's going to glow
// the setup routine runs once when you press reset:
void setup() {
  Serial.begin(9600); // initialize serial communication at 9600 bits per second:
  pinMode(led, OUTPUT); // define the led as an output
  Serial.begin(9600); // initialize serial communication at 9600 bits per second:
}

// the loop routine runs over and over again forever:
void loop() {
  int sensorValue = analogRead(A0); // read the input on analog pin A0:
  delay(1);// delay in between reads for stability
  Serial.println(distanceSensor.measureDistanceCm());// print out the value you read:
  delay(500);//delay in between reads for stability
  if (sensorValue < 100 && distanceSensor.measureDistanceCm() < 50) {//reads the imput in the A0 and the pins 12 & 13 and if they are below 100 in the A0 and below 50 in the 12/13 then turns the light on
    digitalWrite(9, HIGH);
  } else {// if the values are avobe 100 in A0 or 50 in 12/13 then turns the light off
    digitalWrite(9, LOW);
  }
}
