  // SOURCE CODE (C++)


  int btn1 = 2;
  int btn2 = 3;
  int btn3 = 4;
  int btn4 = 5;
  int buzzerPin = 9;
  int ledPin = 8;


  void setup() {
    pinMode(btn1, INPUT_PULLUP);
    pinMode(btn2, INPUT_PULLUP);
    pinMode(btn3, INPUT_PULLUP);
    pinMode(btn4, INPUT_PULLUP);
    pinMode(buzzerPin, OUTPUT);
    pinMode(ledPin, OUTPUT);
  }


  void loop() {
    // BUTTON 1: Low C Note (261Hz)
    if (digitalRead(btn1) == LOW) {
      digitalWrite(ledPin, HIGH);
      while (digitalRead(btn1) == LOW) { tone(buzzerPin, 261); }  // Long sound while held
      noTone(buzzerPin);
      digitalWrite(ledPin, LOW);
    }

    // BUTTON 2: D Note (294Hz)
    else if (digitalRead(btn2) == LOW) {
      digitalWrite(ledPin, HIGH);
      while (digitalRead(btn2) == LOW) { tone(buzzerPin, 294); }  // Long sound while held
      noTone(buzzerPin);
      digitalWrite(ledPin, LOW);
    }

    // BUTTON 3: E Note (329Hz)
    else if (digitalRead(btn3) == LOW) {
      digitalWrite(ledPin, HIGH);
      while (digitalRead(btn3) == LOW) { tone(buzzerPin, 329); }  // Long sound while held
      noTone(buzzerPin);
      digitalWrite(ledPin, LOW);
    }

    // BUTTON 4: High F Note (349Hz)
    else if (digitalRead(btn4) == LOW) {
      digitalWrite(ledPin, HIGH);
      while (digitalRead(btn4) == LOW) { tone(buzzerPin, 349); }  // Long sound while held
      noTone(buzzerPin);
      digitalWrite(ledPin, LOW);
    }
  }
