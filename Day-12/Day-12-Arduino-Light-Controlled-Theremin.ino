  int ldrPin = A0;
  int buzzerPin = 8;

  void setup() {
    pinMode(buzzerPin, OUTPUT);
  }

  void loop() {
    int ldrValue = analogRead(ldrPin);
    int freq = map(ldrValue, 200, 900, 120, 4000);
    freq = constrain(freq, 120, 4000);

    tone(buzzerPin, freq);
    delay(10);
  }