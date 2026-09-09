  // SOURCE CODE(C++)
  
  
  int redLED = 7;
  int yellowLED = 8;
  int buzzerPin = 9;


  void setup() {
    pinMode(redLED, OUTPUT);
    pinMode(yellowLED, OUTPUT);
    pinMode(buzzerPin, OUTPUT);
  }


  void loop() {
    // State 1: Red On, Yellow Off, High Pitch Tone
    digitalWrite(redLED, HIGH);
    digitalWrite(yellowLED, LOW);
    digitalWrite(buzzerPin, HIGH);
    delay(150);

    // State 2: Red Off, Yellow On, Siren Pause
    digitalWrite(redLED, LOW);
    digitalWrite(yellowLED, HIGH);
    digitalWrite(buzzerPin, LOW);
    delay(150);
  }
