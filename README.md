# RFID Attendance & Access System

![Arduino](https://img.shields.io/badge/Arduino-Uno-blue)
![C++](https://img.shields.io/badge/C++-Embedded-orange)
![RFID](https://img.shields.io/badge/RFID-MFRC522-success)
![Status](https://img.shields.io/badge/Status-Active-success)
![License](https://img.shields.io/badge/License-MIT-green)
[![Wokwi](https://img.shields.io/badge/Wokwi-Live%20Simulation-blueviolet)](https://wokwi.com/projects/464379162690625537)

An RFID-based attendance and access verification system built using Arduino. The system scans RFID cards, verifies authorized users, displays access status on an LCD screen, and provides buzzer feedback for successful or denied access attempts.

---

## 🔗 Live Simulation

Experience the project online using Wokwi:

👉 https://wokwi.com/projects/464379162690625537

This simulation demonstrates:

* RFID card scanning
* Access verification
* LCD status messages
* Buzzer feedback
* Real-time attendance logging

---

## Problem Statement

Manual attendance systems can be slow and inefficient. This project provides a simple RFID-based solution for faster attendance marking and basic access verification.

---

## Features

* RFID card scanning
* UID-based authorization system
* LCD display feedback
* Buzzer alert system
* Attendance logging through Serial Monitor
* Access granted and denied verification
* Real-time RFID scanning
* Online Wokwi simulation support
* Interactive IoT demonstration

---

## Technologies Used

* Arduino
* C++
* SPI Communication
* MFRC522 RFID Module
* LiquidCrystal_I2C Library
* Wokwi IoT Simulator

---

## Components Used

* Arduino UNO
* MFRC522 RFID Reader
* RFID Cards / Tags
* I2C LCD Display
* Buzzer
* Breadboard
* Jumper Wires

---

## How It Works

1. The RFID card is scanned using the MFRC522 RFID reader.
2. The system reads the unique UID of the RFID card.
3. The scanned UID is compared with the authorized UID list.
4. If the card is authorized:

   * LCD displays "Access Granted"
   * Short buzzer confirmation sound is played
   * Attendance is logged in the Serial Monitor
5. If the card is unauthorized:

   * LCD displays "Access Denied"
   * Long buzzer alert is triggered
6. The system resets and waits for the next card scan.

---

## Authorization Logic

The system stores authorized RFID card UIDs in an array. Whenever a card is scanned, the UID is matched against the stored authorized list.

### Example

* Authorized card → Access Granted
* Unauthorized card → Access Denied

This helps prevent unauthorized access attempts.

---

## Challenges Faced

* Reading RFID UID data correctly
* Managing authorized card verification
* Handling LCD display updates
* Creating different buzzer responses for access states
* Organizing hardware connections properly

---

## Problems Solved

* Faster attendance verification
* Simple RFID-based access control
* Reduced manual attendance handling
* Real-time user verification using RFID cards

---

## Key Functionalities

* Scan RFID cards using MFRC522 reader
* Verify UID authorization
* Display access messages on LCD
* Trigger different buzzer responses
* Log attendance details through Serial Monitor

---

## Serial Monitor Output Example

```bash id="n6g15x"
UID,STATUS,MILLIS
43EF2C06,GRANTED,15230
86F64506,DENIED,18742
```

---

## Preview

### Hardware Setup

![Hardware Setup](pictures/hardware.png)

### RFID Card Scan

![RFID Scan](pictures/rfidscanner.png)

### Access Granted

![Access Granted](pictures/accessgranted.png)

### Access Denied

![Access Denied](pictures/accessdenied.png)

### Serial Monitor Logs

![Serial Monitor](pictures/serialmonitor.png)

---

## Project Structure

```bash id="r4wnk0"
RFID-Attendance-System/
│── RFID_Attendance_System.ino
│── README.md
│── LICENSE
│
├── pictures/
│   ├── hardware.png
│   ├── rfidscanner.png
│   ├── accessgranted.png
│   ├── accessdenied.png
│   └── serialmonitor.png
```

---

## Future Improvements

* Database integration for attendance storage
* Web dashboard for attendance tracking
* Cloud synchronization
* Fingerprint authentication support
* Student attendance analytics

---

## Repository Topics

arduino • rfid • iot • attendance-system • embedded-cpp • wokwi • rc522 • arduino-project

---

## Authors

* Nikhil Rejith

---

## License

This project is licensed under the MIT License.
