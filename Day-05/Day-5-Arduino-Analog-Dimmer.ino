  // SOURCE CODE (C++)
  
  
  int potPin = A0;    // Potentiometer connected to Analog Pin A0
  int ledPin = 9;     // Red LED connected to PWM Pin 9
  int potValue = 0;   // Variable to store the raw dial reading
  int ledBright = 0;  // Variable to store scaled brightness


  void setup() {
    pinMode(ledPin, OUTPUT);
  }


  void loop() {
    potValue = analogRead(potPin);               // Reads raw value (0 to 1023)
    ledBright = map(potValue, 0, 1023, 0, 255);  // Scales down to PWM range (0 to 255)
    analogWrite(ledPin, ledBright);              // Changes actual LED brightness
    delay(10);                                   // Smooth sampling delay
  }
