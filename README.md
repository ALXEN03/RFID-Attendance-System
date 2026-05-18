# RFID Attendance System

An RFID-based attendance management system built using Arduino and C++. The project automatically verifies RFID cards and records attendance using an RFID reader, LCD display, and buzzer alerts.

## Features
- RFID card scanning
- Automatic attendance verification
- LCD display for scan status
- Buzzer alert system
- Authorized card detection
- Serial monitor logging

## Technologies Used
- C++
- Arduino
- RFID RC522 Module
- LiquidCrystal_I2C Library
- SPI Communication

## Hardware Used
- Arduino Uno
- RFID RC522 Module
- I2C LCD Display
- Buzzer
- Jumper Wires

## How It Works
1. User scans RFID card
2. System reads card UID
3. UID is matched with authorized cards
4. Access is granted or denied
5. LCD displays the result
6. Buzzer gives audio feedback
7. Scan details are logged in Serial Monitor

## Project Structure
```bash
RFID-Attendance-System/
│── rfid_attendance.cpp
│── README.md
│── LICENSE
```

## Serial Output Example
```bash
UID,STATUS,MILLIS
43EF2C06,GRANTED,15230
86F64506,DENIED,18742
```

## Future Improvements
- Database integration
- Web dashboard
- Cloud attendance sync
- Student analytics
- Admin management system

## Author
Nikhil Rejith

## License
This project is licensed under the MIT License.
