  //VERIFIED SOURCE CODE (C++)


  int redLED = 7;
  int yellowLED = 8;
  int buttonPin = 2;


  void setup() {
    pinMode(redLED, OUTPUT);
    pinMode(yellowLED, OUTPUT);
    // Internal pull-up removes the need for an external resistor!
    pinMode(buttonPin, INPUT_PULLUP); 
  }


  void loop() {
    int buttonState = digitalRead(buttonPin);
    
    if (buttonState == LOW) {        // Button is pressed down
      digitalWrite(yellowLED, HIGH);
      digitalWrite(redLED, LOW);
    } else {                         // Button is released
      digitalWrite(yellowLED, LOW);
      digitalWrite(redLED, HIGH);
    }
  }
