#include <SPI.h>
#include <MFRC522.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

// --- Pins ---
#define SS_PIN 10
#define RST_PIN 9
#define BUZZER_PIN 8   // connect buzzer + to pin 8, - to GND

// --- Instances ---
MFRC522 mfrc522(SS_PIN, RST_PIN);
LiquidCrystal_I2C lcd(0x27, 16, 2); // change to 0x3F if needed

// --- Authorized UIDs ---
String authorizedCards[] = {
  "43EF2C06",   // example tag
  "CE818604",   // example tag
  "86F64506"    // add more UIDs
};
int totalCards = sizeof(authorizedCards) / sizeof(authorizedCards[0]);

void setup() {
  Serial.begin(9600);
  SPI.begin();
  mfrc522.PCD_Init();

  // LCD init
  lcd.init();
  lcd.backlight();
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("  RFID SYSTEM  ");
  lcd.setCursor(0,1);
  lcd.print("  Ready to Scan ");
  delay(1200);
  lcd.clear();

  // Buzzer init
  pinMode(BUZZER_PIN, OUTPUT);
  digitalWrite(BUZZER_PIN, LOW);

  Serial.println("UID,STATUS,MILLIS");
}

void loop() {
  // wait for a new card
  if (!mfrc522.PICC_IsNewCardPresent()) return;
  if (!mfrc522.PICC_ReadCardSerial()) return;

  // build UID string
  String uidString = "";
  for (byte i = 0; i < mfrc522.uid.size; i++) {
    if (mfrc522.uid.uidByte[i] < 0x10) uidString += "0";
    uidString += String(mfrc522.uid.uidByte[i], HEX);
  }
  uidString.toUpperCase();

  // check authorization
  bool authorized = false;
  for (int i = 0; i < totalCards; i++) {
    if (uidString == authorizedCards[i]) {
      authorized = true;
      break;
    }
  }

  // --- LCD + Buzzer ---
  lcd.clear();
  if (authorized) {
    lcd.setCursor(0,0);
    lcd.print("Access Granted ");
    lcd.setCursor(0,1);
    lcd.print(uidString);

    // Buzzer: 3 short beeps
    for (int i = 0; i < 2; i++) {
      digitalWrite(BUZZER_PIN, HIGH);
      delay(200);
      digitalWrite(BUZZER_PIN, LOW);
      delay(200);
    }
  } else {
    lcd.setCursor(0,0);
    lcd.print("Access Denied  ");
    lcd.setCursor(0,1);
    lcd.print(uidString);

    // Buzzer: continuous for 4 sec
    digitalWrite(BUZZER_PIN, HIGH);
    delay(3000);
    digitalWrite(BUZZER_PIN, LOW);
  }

  // --- Serial log ---
  Serial.print(uidString);
  Serial.print(",");
  Serial.print(authorized ? "GRANTED" : "DENIED");
  Serial.print(",");
  Serial.println(millis());

  // cleanup card
  mfrc522.PICC_HaltA();
  mfrc522.PCD_StopCrypto1();

  delay(2000);
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("  Ready to Scan ");
}
