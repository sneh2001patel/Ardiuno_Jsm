//Ultrasonic sensor
#include "SD.h"
#define SD_ChipSelectPin 10
#include "TMRpcm.h"
#include "SPI.h"

TMRpcm tmrpcm;
int trigPin = 5;
int echoPin = 4;
long duration, cm, inches;

void setup() {
  tmrpcm.speakerPin = 9;
  Serial.begin(9600);
  if (!SD.begin(SD_ChipSelectPin))
  {
    Serial.println("SD fail");
    return;
  }
  tmrpcm.setVolume(6);
  Serial.begin(9600);
  //  inputs & outputs
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

}

void loop() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(5);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  pinMode(echoPin, INPUT);
  duration = pulseIn(echoPin, HIGH);
  cm = (duration / 2) / 29.1;
  inches = (duration / 2) / 74;

  if (cm <= 30) {
//    Serial.println("Jay Sawminarayan");
    tmrpcm.play("jsm.wav");
    delay(2000);
  }

  delay(500);


}
