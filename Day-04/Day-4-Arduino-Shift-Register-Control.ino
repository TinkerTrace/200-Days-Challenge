  // SOURCE CODE (C++)
  int latchPin = 5;  // ST_CP of 74HC595
  int clockPin = 6;  // SH_CP of 74HC595
  int dataPin = 4;   // DS of 74HC595


  void setup() {
    pinMode(latchPin, OUTPUT);
    pinMode(clockPin, OUTPUT);
    pinMode(dataPin, OUTPUT);
  }


  void loop() {
    // Pattern 1: Binary 01 (Red On, Yellow Off)
    digitalWrite(latchPin, LOW);
    shiftOut(dataPin, clockPin, MSBFIRST, 1);
    digitalWrite(latchPin, HIGH);
    delay(100);


    // Pattern 2: Binary 10 (Red Off, Yellow On)
    digitalWrite(latchPin, LOW);
    shiftOut(dataPin, clockPin, MSBFIRST, 2);
    digitalWrite(latchPin, HIGH);
    delay(100);
  }
