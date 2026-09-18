  // SOURCE CODE (C++)
  int irSensorPin = 2;  // Black wire to Pin 2
  int buzzerPin = 9;    // Active buzzer to Pin 9
  int redLed = 5;       // Red hazard LED to Pin 5


  void setup() {
    pinMode(irSensorPin, INPUT_PULLUP);
    pinMode(buzzerPin, OUTPUT);
    pinMode(redLed, OUTPUT);
  }


  void loop() {
    int sensorStatus = digitalRead(irSensorPin);

    // The E18-D80NK drops LOW when an object blocks its line-of-sight
    if (sensorStatus == HIGH) {
      // INTRUDER TRACKED! Trigger rapid high-intensity strobe alert sirens instantly
      for (int i = 0; i < 4; i++) {
        digitalWrite(redLed, HIGH);
        tone(buzzerPin, 1300);  // Piercing high-pitch security alert pitch
        delay(70);
        digitalWrite(redLed, LOW);
        noTone(buzzerPin);
        delay(70);
      }
    } else {
      // Defense grid line is clear and secure
      digitalWrite(redLed, LOW);
      noTone(buzzerPin);
    }
  }
