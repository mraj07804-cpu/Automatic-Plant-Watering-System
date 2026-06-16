#include <Arduino.h>

// Arduino sketch entrypoint for the Watering System

const int sensorPin = A0; // Soil moisture sensor analog pin
const int ledPin = 9;     // LED pin
const int buzzerPin = 8;  // Buzzer pin
const int pumpPin = 10;   // Pump pin

const int threshold = 500; // Moisture threshold

void setup()
{
    pinMode(sensorPin, INPUT);
    pinMode(ledPin, OUTPUT);
    pinMode(buzzerPin, OUTPUT);
    pinMode(pumpPin, OUTPUT);
    Serial.begin(9600);
}

void loop()
{
    int moisture = analogRead(sensorPin);
    Serial.println(moisture);

    if (moisture < threshold)
    {
        digitalWrite(ledPin, HIGH);
        digitalWrite(buzzerPin, HIGH);
        delay(2000);
        digitalWrite(ledPin, LOW);
        digitalWrite(buzzerPin, LOW);

        digitalWrite(pumpPin, HIGH);
        delay(10000);
        digitalWrite(pumpPin, LOW);
    }

    delay(500);
}
