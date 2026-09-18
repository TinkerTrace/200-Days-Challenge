  // SOURCE CODE (C++)
  int irSensorPin = 2;  // Black wire to Pin 2
  int motorIn1 = 9;     // Connects to L298N IN1
  int motorIn2 = 10;    // Connects to L298N IN2


  void setup() {
    pinMode(irSensorPin, INPUT_PULLUP);
    pinMode(motorIn1, OUTPUT);
    pinMode(motorIn2, OUTPUT);

    // Start with the motor turned off completely
    digitalWrite(motorIn1, LOW);
    digitalWrite(motorIn2, LOW);
  }


  void loop() {
    int sensorStatus = digitalRead(irSensorPin);


    // The E18-D80NK drops LOW when an object blocks its path
    if (sensorStatus == HIGH) {
      // PROXIMITY ENGAGED: Drive the motor forward at maximum speed
      digitalWrite(motorIn1, HIGH);
      digitalWrite(motorIn2, LOW);
    } else {
      // PATH CLEAR: Stop the motor rotation instantly
      digitalWrite(motorIn1, LOW);
      digitalWrite(motorIn2, LOW);
    }
    delay(50);  // Small stability buffer delay
  }
