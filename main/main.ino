// https://www.instructables.com/Test-your-radar-detector-or-laser-jammer-with-this/
#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);  // setup LCD 4 bit mode
int pulse = 1;                          // pulse size length in microseconds
int choice = 0;                         // select laser gun model type
int lastchoice = 0;                     // recall last selection choice
int fire;                               // trigger fire button

void setup() {
  lcd.begin(16, 2);     // 16x2 LCD
  analogWrite(10, 90);  // foreground LCD
  analogWrite(9, 150);  // background LCD ~3.3 volts
  lcd.clear();
  pinMode(13, OUTPUT);  // 940nM LED output (mimic 904nM laser diode)
  // pinMode(11, INPUT);   // setup trigger button as input
}

void loop() {
  // choice = analogRead(0);          // read laser gun model selection from 10K pot
  // choice = (int)(choice / 85.25);  // only 12 valid choices, 11 guns + stealth mode

  if (choice != lastchoice)  // clear display only if it's different
    lcd.clear();
  lastchoice = choice;

  switch (choice) {
    case 0:
      lcd.setCursor(0, 0);

      lcd.setCursor(0, 1);
      lcd.print("/Rev.1 100Hz");  // 100pps
      // fire = digitalRead(11);
      if (true) {
        lcd.setCursor(12, 1);
        lcd.print("Fire");
        for (int a = 1; a <= 200; a++) {
          digitalWrite(13, HIGH);
          delayMicroseconds(pulse);
          digitalWrite(13, LOW);
          delayMicroseconds(9918);  // 10ms
        }
        lcd.setCursor(12, 1);
        lcd.print(" ");
      }
      break;
    case 1:
      lcd.setCursor(0, 0);
      lcd.print("Ultralyte Rev.2");
      lcd.setCursor(0, 1);
      lcd.print("125Hz");  // 125pps
      // fire = digitalRead(11);
      if (true) {
        lcd.setCursor(6, 1);
        lcd.print("Fire");
        for (int a = 1; a <= 250; a++) {
          digitalWrite(13, HIGH);
          delayMicroseconds(pulse);
          digitalWrite(13, LOW);
          delayMicroseconds(7932);
        }
        lcd.setCursor(6, 1);
        lcd.print(" ");
      }
      break;
    case 2:
      lcd.setCursor(0, 0);
      lcd.print("Stalker LZ-1/LR");
      lcd.setCursor(0, 1);
      lcd.print("130Hz");  // 130pps
      // fire = digitalRead(11);
      if (true) {
        lcd.setCursor(6, 1);
        lcd.print("Fire");
        for (int a = 1; a <= 260; a++) {
          digitalWrite(13, HIGH);
          delayMicroseconds(pulse);
          digitalWrite(13, LOW);
          delayMicroseconds(7627);
        }
        lcd.setCursor(6, 1);
        lcd.print(" ");
      }
      break;
    case 3:
      lcd.setCursor(0, 0);
      lcd.print("Riegl");
      lcd.setCursor(0, 1);
      lcd.print("160Hz");  // 160pps
      // fire = digitalRead(11);
      if (true) {
        lcd.setCursor(6, 1);
        lcd.print("Fire");
        for (int a = 1; a <= 320; a++) {
          digitalWrite(13, HIGH);
          delayMicroseconds(pulse);
          digitalWrite(13, LOW);
          delayMicroseconds(6195);
        }
        lcd.setCursor(6, 1);
        lcd.print(" ");
      }
      break;
    case 4:
      lcd.setCursor(0, 0);
      lcd.print("Laser Ally");
      lcd.setCursor(0, 1);
      lcd.print("185.12Hz");  // 185.12pps
      // fire = digitalRead(11);
      if (true) {
        lcd.setCursor(10, 1);
        lcd.print("Fire");
        for (int a = 1; a <= 370; a++) {
          digitalWrite(13, HIGH);
          delayMicroseconds(pulse);
          digitalWrite(13, LOW);
          delayMicroseconds(5352);
        }
        lcd.setCursor(10, 1);
        lcd.print(" ");
      }
      break;
    case 5:
      lcd.setCursor(0, 0);
      lcd.print("Kustom Pro 3/4");
      lcd.setCursor(0, 1);
      lcd.print("/Lite 200Hz");  // 200pps
      // fire = digitalRead(11);
      if (true) {
        lcd.setCursor(12, 1);
        lcd.print("Fire");
        for (int a = 1; a <= 400; a++) {
          digitalWrite(13, HIGH);
          delayMicroseconds(pulse);
          digitalWrite(13, LOW);
          delayMicroseconds(4953);  // 5ms
        }
        lcd.setCursor(12, 1);
        lcd.print(" ");
      }
      break;
    case 6:
      lcd.setCursor(0, 0);
      lcd.print("LTI TruSpeed");
      lcd.setCursor(0, 1);
      lcd.print("200.3Hz");  // 200.3pps
      // fire = digitalRead(11);
      if (true) {
        lcd.setCursor(9, 1);
        lcd.print("Fire");
        for (int a = 1; a <= 400; a++) {
          digitalWrite(13, HIGH);
          delayMicroseconds(pulse);
          digitalWrite(13, LOW);
          delayMicroseconds(4946);
        }
        lcd.setCursor(9, 1);
        lcd.print(" ");
      }
      break;
    case 7:
      lcd.setCursor(0, 0);
      lcd.print("Laser Atlanta");
      lcd.setCursor(0, 1);
      lcd.print("Pro2 238.4Hz");  // 238.4pps
      // fire = digitalRead(11);
      if (true) {
        lcd.setCursor(12, 1);
        lcd.print("Fire");
        for (int a = 1; a <= 476; a++) {
          digitalWrite(13, HIGH);
          delayMicroseconds(pulse);
          digitalWrite(13, LOW);
          delayMicroseconds(4154);
        }
        lcd.setCursor(12, 1);
        lcd.print(" ");
      }
      break;
    case 8:
      lcd.setCursor(0, 0);
      lcd.print("Laser Atlanta");  // 238.4pps/68.1pps stealth mode
      lcd.setCursor(0, 1);
      lcd.print("Stealth Mode");  // 2 pulses fire followed by 5 missing pulses
      // fire = digitalRead(11);
      if (true) {
        lcd.setCursor(12, 1);
        lcd.print("Fire");
        for (int a = 1; a <= 68; a++) {
          digitalWrite(13, HIGH);
          delayMicroseconds(pulse);
          digitalWrite(13, LOW);
          delayMicroseconds(4154);
          digitalWrite(13, HIGH);
          delayMicroseconds(pulse);
          digitalWrite(13, LOW);
          delayMicroseconds(12462);  // need 6 delays units (4154*3)
          delayMicroseconds(12462);  // (4154*3)
        }
        lcd.setCursor(12, 1);
        lcd.print(" ");
      }
      break;
    case 9:
      lcd.setCursor(0, 0);
      lcd.print("Kustom Prolaser1");
      lcd.setCursor(0, 1);
      lcd.print("381.5Hz");  // 381.5pps
      // fire = digitalRead(11);
      if (true) {
        lcd.setCursor(9, 1);
        lcd.print("Fire");
        for (int a = 1; a <= 763; a++) {
          digitalWrite(13, HIGH);
          delayMicroseconds(pulse);
          digitalWrite(13, LOW);
          delayMicroseconds(2591);
        }
        lcd.setCursor(9, 1);
        lcd.print(" ");
      }
      break;
    case 10:
      lcd.setCursor(0, 0);
      lcd.print("Jenoptik Laveg");
      lcd.setCursor(0, 1);
      lcd.print("600Hz");  // 600pps
      // fire = digitalRead(11);
      if (true) {
        lcd.setCursor(6, 1);
        lcd.print("Fire");
        for (int a = 1; a <= 1200; a++) {
          digitalWrite(13, HIGH);
          delayMicroseconds(pulse);
          digitalWrite(13, LOW);
          delayMicroseconds(1642);
        }
        lcd.setCursor(6, 1);
        lcd.print(" ");
      }
      break;
    case 11:
      lcd.setCursor(0, 0);
      lcd.print("NJL SCS 102");
      lcd.setCursor(0, 1);
      lcd.print("3200Hz");  // 3200pps
      // fire = digitalRead(11);
      if (true) {
        lcd.setCursor(7, 1);
        lcd.print("Fire");
        for (int a = 1; a <= 6400; a++) {
          digitalWrite(13, HIGH);
          delayMicroseconds(pulse);
          digitalWrite(13, LOW);
          delayMicroseconds(299);
        }
        lcd.setCursor(7, 1);
        lcd.print(" ");
      }
      break;
  }
}