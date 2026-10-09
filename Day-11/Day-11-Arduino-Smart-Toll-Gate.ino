  // SOURCE CODE (C++)
  #include <Servo.h>  // Built-in library, no manual installation required!


  Servo gateServo;          // Create servo object to control the gate motor
  int irSensorPin = 2;      // Black sensor output wire to Pin 2
  int gateClosedAngle = 0;  // Downward position angle
  int gateOpenAngle = 90;   // Lifted position angle


  void setup() {
    gateServo.attach(9);  // Link the servo controller logic to Pin 9
    pinMode(irSensorPin, INPUT_PULLUP);

    // Start with the security barrier closed
    gateServo.write(gateClosedAngle);
  }


  void loop() {
    int sensorStatus = digitalRead(irSensorPin);


    // The E18-D80NK drops LOW when an object blocks its path
    if (sensorStatus == LOW) {
      // OBSTACLE TRACKED: Swiftly lift the barrier arm to 90 degrees
      gateServo.write(gateOpenAngle);
      delay(2000);  // Hold open for 2 seconds to let the object pass safely
    } else {
      // PATH CLEAR: Smoothly return the barrier to the closed position
      gateServo.write(gateClosedAngle);
    }
    delay(50);  // Small logic optimization delay
  }
