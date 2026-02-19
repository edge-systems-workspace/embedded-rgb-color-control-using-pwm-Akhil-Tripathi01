[![Review Assignment Due Date](https://classroom.github.com/assets/deadline-readme-button-22041afd0340ce965d47ae6ef1cefeee28c7c493a6346c4f15d667ab976d596c.svg)](https://classroom.github.com/a/LDXstfmX)
# 🎨 Embedded RGB LED Control System

![License](https://img.shields.io/badge/license-MIT-blue)
![Platform](https://img.shields.io/badge/platform-Arduino-orange)
![Language](https://img.shields.io/badge/language-C++-blue)


An embedded RGB LED control system demonstrating both digital (ON/OFF) and analog (PWM-based brightness control) modes for color mixing and intensity modulation.

---

## 📑 Table of Contents

- Project Overview
- Hardware Requirements
- Software Requirements
- Wiring Connections
- Working Principle
- Code Structure
- Documentation Requirement
- Submission Requirements
- Future Improvements
- License

---

## 🚀 Project Overview

This project demonstrates RGB LED control using Arduino (Uno R4 recommended).

The system supports:

- Digital color control (HIGH/LOW)
- PWM brightness control
- Color mixing
- Structured serial interaction
- Doxygen documentation standards
- Git-based workflow discipline

---

## 🔧 Hardware Requirements

- Arduino Uno R4
- RGB LED (Common Cathode recommended)
- 3 × 220Ω Resistors
- Breadboard
- Jumper wires
- USB cable

---

## 💻 Software Requirements

- Arduino IDE
- Git
- GitHub Account

---

## 🔌 Wiring Connections (Common Cathode RGB)

| RGB Pin | Arduino |
|---------|----------|
| Red     | Pin 9    |
| Green   | Pin 10   |
| Blue    | Pin 11   |
| Common  | GND      |

⚠ Use current-limiting resistors for each color.

---

## ⚙ Working Principle

- Digital Mode → Pin HIGH or LOW (Full ON/OFF)
- Analog Mode → PWM using analogWrite() (0–255)
- Color mixing achieved by varying RGB intensity

---

## 🧠 Code Structure

The system:

1. Initializes Serial communication
2. Configures RGB pins as OUTPUT
3. Implements digital color control
4. Implements PWM-based brightness control
5. Displays structured output

---

## 📚 Documentation Requirement

Students must include:

- File-level Doxygen block
- Documentation for:
  - `setup()`
  - `loop()`
- Required tags:
  - `@file`
  - `@brief`
  - `@author`
  - `@date`

---

## 📊 Submission Requirements

- Minimum 5 meaningful commits
- Proper commit message format
- All TODO tasks completed
- Doxygen documentation included
- Code must compile successfully

---

## 🔮 Future Improvements

- Serial-based color input (R,G,B values)
- Predefined color patterns
- Smooth fading transitions
- IoT-based color control
- Music reactive lighting system

---

## 📜 License

This project is licensed under the MIT License.
