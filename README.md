# 🚗 Beginner-Level Car Parking Monitoring System using Arduino UNO

A simple and beginner-friendly car parking monitoring system built using an **Arduino UNO**, **three ultrasonic distance sensors**, and **three I2C LCD displays**. The system detects the presence of vehicles in parking slots and displays the real-time status on individual LCD screens.

---

## 📌 Project Overview

This project simulates a basic car parking monitoring system where each parking slot is monitored by an ultrasonic sensor. When a vehicle is detected within a defined distance threshold, the corresponding LCD display shows the slot as **Occupied**. Otherwise, it shows **Available**.

This is ideal for:
- Learning Arduino and sensor integration
- Understanding I2C communication with multiple devices
- Prototyping smart parking concepts

🔗 [View & Simulate on Tinkercad](https://www.tinkercad.com/things/kjIyo7lLG8a-empty-space-detector-using-ardiuno)

---

## 🧰 Components

| Name | Quantity | Component |
|------|----------|-----------|
| U1 | 1 | Arduino Uno R3 |
| DIST1, DIST2, DIST3 | 3 | Ultrasonic Distance Sensor (HC-SR04, 4-pin) |
| U2 | 1 | PCF8574-based LCD 16×2 I2C (Address: 0x20) |
| U3 | 1 | PCF8574-based LCD 16×2 I2C (Address: 0x21) |
| U4 | 1 | PCF8574-based LCD 16×2 I2C (Address: 0x22) |

---

## 🔌 Pin Connections

### Ultrasonic Sensors → Arduino UNO

| Sensor | Sensor Pin | Arduino Pin |
|--------|------------|-------------|
| DIST1 | VCC | 5V |
| DIST1 | GND | GND |
| DIST1 | TRIG | D4 |
| DIST1 | ECHO | D5 |
| DIST2 | VCC | 5V |
| DIST2 | GND | GND |
| DIST2 | TRIG | D2 |
| DIST2 | ECHO | D3 |
| DIST3 | VCC | 5V |
| DIST3 | GND | GND |
| DIST3 | TRIG | D6 |
| DIST3 | ECHO | D7 |

### I2C LCD Displays → Arduino UNO

All three LCD displays share the same I2C bus (SDA and SCL), but each has a unique I2C address configured via the PCF8574 backpack.

| LCD | Arduino Pin | LCD Pin | I2C Address |
|-----|-------------|---------|-------------|
| U2 (Slot 1) | A4 (SDA) | SDA | 0x20 |
| U2 (Slot 1) | A5 (SCL) | SCL | 0x20 |
| U3 (Slot 2) | A4 (SDA) | SDA | 0x21 |
| U3 (Slot 2) | A5 (SCL) | SCL | 0x21 |
| U4 (Slot 3) | A4 (SDA) | SDA | 0x22 |
| U4 (Slot 3) | A5 (SCL) | SCL | 0x22 |
| All LCDs | 5V | VCC | — |
| All LCDs | GND | GND | — |

> **Note:** All I2C devices (U2, U3, U4) share a single SDA (A4) and SCL (A5) line on the Arduino. They are distinguished by their unique I2C addresses.

---

## 🗂️ Circuit Overview

```
Arduino UNO
├── 5V  ──────────────────────────── VCC of all sensors and LCDs
├── GND ──────────────────────────── GND of all sensors and LCDs
├── D2  ──► DIST2 TRIG
├── D3  ──► DIST2 ECHO
├── D4  ──► DIST1 TRIG
├── D5  ──► DIST1 ECHO
├── D6  ──► DIST3 TRIG
├── D7  ──► DIST3 ECHO
├── A4 (SDA) ─── U2 SDA ─── U3 SDA ─── U4 SDA
└── A5 (SCL) ─── U2 SCL ─── U3 SCL ─── U4 SCL
```

---

## 📚 Libraries Required

Install the following libraries via Arduino IDE (Sketch → Include Library → Manage Libraries):

- **Wire** *(built-in)* — for I2C communication
- **LiquidCrystal_I2C** — for controlling I2C-based LCD displays

---

## ⚙️ How It Works

1. The Arduino continuously triggers each ultrasonic sensor.
2. The sensor measures the time taken for the echo to return and calculates the distance.
3. If the distance is below a set threshold (e.g., 10 cm), the slot is marked as **Occupied**.
4. Each LCD display shows the status of its corresponding parking slot in real time.

---

## 🚀 Getting Started

1. Assemble the circuit as per the connection table above.
2. Install the required libraries in Arduino IDE.
3. Upload the Arduino sketch to the board.
4. Power up and observe each LCD showing live slot availability.

---

## 📷 Circuit Diagram


<img width="1588" height="899" alt="Screenshot 2026-03-25 093028" src="https://github.com/user-attachments/assets/82378de2-bb6e-44cb-a411-7dcef20ad7c6" />

🔗 [https://www.tinkercad.com/things/kjIyo7lLG8a-empty-space-detector-using-ardiuno](https://www.tinkercad.com/things/kjIyo7lLG8a-empty-space-detector-using-ardiuno)

---

## 📄 License

This project is open-source and free to use for educational purposes.
