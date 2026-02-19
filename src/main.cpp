#include <Arduino.h>
/**
 * @file main.cpp
 * @brief Embedded RGB LED Control (Digital + PWM)
 * @author Akhil
 * @date 2026-02-19
 *
 * @details
 * Controls RGB LED using digital ON/OFF
 * and analog PWM brightness control.
 * Features color patterns, transitions, and serial control.
 */

// Pin definitions for RGB LED (PWM-capable pins)
int redPin = 9;
int greenPin = 10;
int bluePin = 11;

// Color modes
const int MODE_DIGITAL = 0;
const int MODE_PWM_DEMO = 1;
const int MODE_COLOR_FADE = 2;
const int MODE_RAINBOW = 3;

int currentMode = MODE_DIGITAL;

/**
 * @brief Set RGB LED to a specific color
 * @param red Red intensity (0-255)
 * @param green Green intensity (0-255)
 * @param blue Blue intensity (0-255)
 */
void setColor(int red, int green, int blue) {
  analogWrite(redPin, red);
  analogWrite(greenPin, green);
  analogWrite(bluePin, blue);
}

/**
 * @brief Turn off the LED (all pins to 0)
 */
void turnOffLED() {
  setColor(0, 0, 0);
}

/**
 * @brief Demo mode - cycle through primary colors
 */
void colorCycleMode() {
  Serial.println(">>> Primary Color Cycle <<<");

  // Red
  setColor(255, 0, 0);
  Serial.println("Red: ON");
  delay(1500);

  // Green
  setColor(0, 255, 0);
  Serial.println("Green: ON");
  delay(1500);

  // Blue
  setColor(0, 0, 255);
  Serial.println("Blue: ON");
  delay(1500);

  // White (all on)
  setColor(255, 255, 255);
  Serial.println("White: ON");
  delay(1500);

  // Off
  turnOffLED();
  Serial.println("All OFF");
  delay(500);
}

/**
 * @brief PWM brightness demonstration
 */
void pwmDemoMode() {
  Serial.println(">>> PWM Brightness Demo <<<");

  // Fade red from 0 to 255
  Serial.println("Fading Red...");
  for (int i = 0; i <= 255; i += 15) {
    analogWrite(redPin, i);
    delay(50);
  }
  delay(500);

  // Fade green from 0 to 255
  analogWrite(redPin, 0);
  Serial.println("Fading Green...");
  for (int i = 0; i <= 255; i += 15) {
    analogWrite(greenPin, i);
    delay(50);
  }
  delay(500);

  // Fade blue from 0 to 255
  analogWrite(greenPin, 0);
  Serial.println("Fading Blue...");
  for (int i = 0; i <= 255; i += 15) {
    analogWrite(bluePin, i);
    delay(50);
  }
  delay(500);

  turnOffLED();
  Serial.println("Fade complete");
}

/**
 * @brief Rainbow color fade effect
 */
void rainbowMode() {
  Serial.println(">>> Rainbow Fade Effect <<<");

  for (int transition = 0; transition < 3; transition++) {
    // Red to Yellow (increase green)
    for (int g = 0; g <= 255; g += 5) {
      setColor(255, g, 0);
      delay(10);
    }

    // Yellow to Green (decrease red)
    for (int r = 255; r >= 0; r -= 5) {
      setColor(r, 255, 0);
      delay(10);
    }

    // Green to Cyan (increase blue)
    for (int b = 0; b <= 255; b += 5) {
      setColor(0, 255, b);
      delay(10);
    }

    // Cyan to Blue (decrease green)
    for (int g = 255; g >= 0; g -= 5) {
      setColor(0, g, 255);
      delay(10);
    }

    // Blue to Magenta (increase red)
    for (int r = 0; r <= 255; r += 5) {
      setColor(r, 0, 255);
      delay(10);
    }

    // Magenta to Red (decrease blue)
    for (int b = 255; b >= 0; b -= 5) {
      setColor(255, 0, b);
      delay(10);
    }
  }

  turnOffLED();
  Serial.println("Rainbow complete");
}

/**
 * @brief Print menu to serial
 */
void printMenu() {
  Serial.println("\n========== RGB LED CONTROL MENU ==========");
  Serial.println("1 - Digital Mode (Color Cycle)");
  Serial.println("2 - PWM Demo (Brightness Fade)");
  Serial.println("3 - Rainbow Fade Effect");
  Serial.println("Enter mode (1-3):");
}

void setup() {
  // Initialize serial communication at 9600 baud
  Serial.begin(9600);

  // Set RGB pins as outputs
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);

  // Startup message
  Serial.println("\n========================================");
  Serial.println("RGB LED Control System Initialized!");
  Serial.println("========================================");

  // Turn off LED initially
  turnOffLED();

  delay(1000);
  printMenu();
}

void loop() {
  // Check for serial input to change mode
  if (Serial.available() > 0) {
    int input = Serial.read();

    if (input == '1') {
      currentMode = MODE_DIGITAL;
      Serial.println("\n[Mode Changed: Digital Color Cycle]");
    } else if (input == '2') {
      currentMode = MODE_PWM_DEMO;
      Serial.println("\n[Mode Changed: PWM Brightness Demo]");
    } else if (input == '3') {
      currentMode = MODE_RAINBOW;
      Serial.println("\n[Mode Changed: Rainbow Fade Effect]");
    }
  }
\






  // Execute current mode
  switch (currentMode) {
    case MODE_DIGITAL:
      colorCycleMode();
      break;
    case MODE_PWM_DEMO:
      pwmDemoMode();
      break;
    case MODE_RAINBOW:
      rainbowMode();
      break;
    default:
      colorCycleMode();
  }
}
