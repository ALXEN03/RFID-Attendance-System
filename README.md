# RFID Attendance & Access System

![Arduino](https://img.shields.io/badge/Arduino-Uno-blue)
![C++](https://img.shields.io/badge/C++-Embedded-orange)
![RFID](https://img.shields.io/badge/RFID-MFRC522-success)
![Status](https://img.shields.io/badge/Status-Active-success)
![License](https://img.shields.io/badge/License-MIT-green)

An RFID-based attendance and access verification system built using Arduino. The system scans RFID cards, verifies authorized users, displays access status on an LCD screen, and provides buzzer feedback for successful or denied access attempts.

## Problem Statement
Manual attendance systems can be slow and inefficient. This project provides a simple RFID-based solution for faster attendance marking and basic access verification.

## Features
- RFID card scanning
- UID-based authorization system
- LCD display feedback
- Buzzer alert system
- Attendance logging through Serial Monitor
- Access granted and denied verification
- Real-time RFID scanning

## Technologies Used
- Arduino
- C++
- SPI Communication
- MFRC522 RFID Module
- LiquidCrystal_I2C Library

## Components Used
- Arduino UNO
- MFRC522 RFID Reader
- RFID Cards / Tags
- I2C LCD Display
- Buzzer
- Breadboard
- Jumper Wires

## How It Works
1. The RFID card is scanned using the MFRC522 RFID reader.
2. The system reads the unique UID of the RFID card.
3. The scanned UID is compared with the authorized UID list.
4. If the card is authorized:
   - LCD displays "Access Granted"
   - Short buzzer confirmation sound is played
   - Attendance is logged in the Serial Monitor
5. If the card is unauthorized:
   - LCD displays "Access Denied"
   - Long buzzer alert is triggered
6. The system resets and waits for the next card scan.

## Authorization Logic
The system stores authorized RFID card UIDs in an array. Whenever a card is scanned, the UID is matched against the stored authorized list.

### Example
- Authorized card → Access Granted
- Unauthorized card → Access Denied

This helps prevent unauthorized access attempts.

## Challenges Faced
- Reading RFID UID data correctly
- Managing authorized card verification
- Handling LCD display updates
- Creating different buzzer responses for access states
- Organizing hardware connections properly

## Problems Solved
- Faster attendance verification
- Simple RFID-based access control
- Reduced manual attendance handling
- Real-time user verification using RFID cards

## Key Functionalities
- Scan RFID cards using MFRC522 reader
- Verify UID authorization
- Display access messages on LCD
- Trigger different buzzer responses
- Log attendance details through Serial Monitor

## Serial Monitor Output Example
```bash
UID,STATUS,MILLIS
43EF2C06,GRANTED,15230
86F64506,DENIED,18742
```

## Preview

### Hardware Setup
![Hardware Setup](preview1.png)

### RFID Card Scan
![RFID Scan](preview2.png)

### Access Granted
![Access Granted](preview3.png)

### Access Denied
![Access Denied](preview4.png)

### Serial Monitor Logs
![Serial Monitor](preview5.png)

## Project Structure
```bash
RFID-Attendance-System/
│── rfid_attendance.cpp
│── README.md
│── LICENSE
```

## Future Improvements
- Database integration for attendance storage
- Web dashboard for attendance tracking
- Cloud synchronization
- Fingerprint authentication support
- Student attendance analytics

## Authors
- Nikhil Rejith

## License
This project is licensed under the MIT License.
