#include <elapsedMillis.h> //library provides a class with the same name that keeps track of the time that passed since it was created or set to a certain value
const int lm35Pin=A0; //LM35 temperature sensor connected to A0
const int ledPin = 13; //LED connected to digital pin 13
elapsedMillis elapsedTime; //creating instance of elapsedMillis
int interval = 250; //Initial interval of LED blinking

void setup(){
  pinMode(ledPin,OUTPUT);
  pinMode(lm35Pin,OUTPUT);
  Serial.begin(9600);
}
 
 void loop(){
  int temperature = readTemperature();
  if(temperature<30){
    interval = 250; //LED blinks every 250 ms
  }else if(temperature>=30){
    interval = 500; //LED blinks every 500 ms
  }
  //check if it's time to change LED state
  if(elapsedTime >= interval){
    toggleLED();
    elapsedTime = 0; //Reset the timer
  }
 }

 int readTemperature(){
  //Read LM35 temperature sensor value and convert it to Celsius
  int sensorValue = analogRead(lm35Pin);
  float voltage = ((5/1023)*sensorValue)*1000; //sensor output in milli volts
  float temperatureC = voltage/10; //temperature in Celcius
  return temperatureC;
 }

void toggleLED(){
  int currentState =digitalRead(ledPin);
  digitalWrite(ledPin,!currentState);
}