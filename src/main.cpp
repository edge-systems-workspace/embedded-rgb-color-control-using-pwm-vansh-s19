#include <Arduino.h>

/**
 * @file main.cpp
 * @brief Embedded RGB LED Control System (Digital + PWM)
 * @author Vansh Saxena
 * @date 2026-02-28
 *
 * @details
 * This program controls an RGB LED using both digital
 * ON/OFF control and PWM brightness modulation.
 * It demonstrates individual color control and color mixing.
 */

// Define RGB pins (PWM supported pins)
#define RED_PIN 9
#define GREEN_PIN 10
#define BLUE_PIN 11

/**
 * @brief Initializes serial communication and RGB pins.
 */
void setup() {

    Serial.begin(9600);

    pinMode(RED_PIN, OUTPUT);
    pinMode(GREEN_PIN, OUTPUT);
    pinMode(BLUE_PIN, OUTPUT);

    Serial.println("RGB LED Control System Initialized");
}

/**
 * @brief Continuously cycles through digital and PWM color modes.
 */
void loop() {

    // -------- DIGITAL MODE --------
    Serial.println("Digital Red ON");
    digitalWrite(RED_PIN, HIGH);
    delay(1000);

    digitalWrite(RED_PIN, LOW);
    delay(500);

    // -------- PWM MODE --------

    // Red
    Serial.println("PWM Red");
    analogWrite(RED_PIN, 255);
    analogWrite(GREEN_PIN, 0);
    analogWrite(BLUE_PIN, 0);
    delay(1000);

    // Green
    Serial.println("PWM Green");
    analogWrite(RED_PIN, 0);
    analogWrite(GREEN_PIN, 255);
    analogWrite(BLUE_PIN, 0);
    delay(1000);

    // Blue
    Serial.println("PWM Blue");
    analogWrite(RED_PIN, 0);
    analogWrite(GREEN_PIN, 0);
    analogWrite(BLUE_PIN, 255);
    delay(1000);

    // White (Mix)
    Serial.println("PWM White (Mixed)");
    analogWrite(RED_PIN, 255);
    analogWrite(GREEN_PIN, 255);
    analogWrite(BLUE_PIN, 255);
    delay(1000);

    // Turn OFF all
    analogWrite(RED_PIN, 0);
    analogWrite(GREEN_PIN, 0);
    analogWrite(BLUE_PIN, 0);
    delay(1000);
}