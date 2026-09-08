


  int ledPin = 7;

  // the setup function runs once when you press reset or power the board
  void setup() {
    // initialize digital pin ledPin as an output.
    pinMode(ledPin, OUTPUT);
  }

  // the loop function runs over and over again forever
  void loop() {
    digitalWrite(ledPin, HIGH);  // change state of the LED by setting the pin to the HIGH voltage level
    delay(1000);                      // wait for a second
    digitalWrite(ledPin, LOW);   // change state of the LED by setting the pin to the LOW voltage level
    delay(1000);                      // wait for a second
  }
