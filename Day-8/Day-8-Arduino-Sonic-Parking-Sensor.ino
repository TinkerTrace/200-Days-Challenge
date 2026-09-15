  
  #define TRIG_PIN 2
  #define ECHO_PIN 3
  #define RED_LED 5
  #define YEL_LED 6
  #define GRN_LED 7
  #define BUZZER_PIN 9

  // Variable to help blink the buzzer without freezing the code
  unsigned long lastBlinkTime = 0;
  bool buzzerState = false;

  void setup() {
    pinMode(TRIG_PIN, OUTPUT);
    pinMode(ECHO_PIN, INPUT);
    pinMode(RED_LED, OUTPUT);
    pinMode(YEL_LED, OUTPUT);
    pinMode(GRN_LED, OUTPUT);
    pinMode(BUZZER_PIN, OUTPUT);
    
    Serial.begin(9600); // Allows you to debug distance in the Serial Monitor
  }

  void loop() {
    // Generate a clean 10-microsecond pulse to trigger the sensor
    digitalWrite(TRIG_PIN, LOW);
    delayMicroseconds(2);
    digitalWrite(TRIG_PIN, HIGH);
    delayMicroseconds(10);
    digitalWrite(TRIG_PIN, LOW);
    
    // Read the echo bounce time and convert it to centimeters
    long duration = pulseIn(ECHO_PIN, HIGH);
    int distance = duration * 0.034 / 2; 
    
    // Print distance to Serial Monitor for testing
    Serial.print("Distance: ");
    Serial.print(distance);
    Serial.println(" cm");

    // Reset LEDs every loop iteration
    digitalWrite(RED_LED, LOW);
    digitalWrite(YEL_LED, LOW);
    digitalWrite(GRN_LED, LOW);

    // Zone logic
    if (distance > 0 && distance < 10) { 
      // CRITICAL ZONE: Solid Red Light + Continuous Alarm
      digitalWrite(RED_LED, HIGH);
      digitalWrite(BUZZER_PIN, HIGH);
      
    } else if (distance >= 10 && distance <= 25) { 
      // WARNING ZONE: Solid Yellow Light + Intermittent Beeping (Non-blocking)
      digitalWrite(YEL_LED, HIGH);
      
      // Blink the buzzer every 100 milliseconds without using delay()
      if (millis() - lastBlinkTime >= 100) {
        lastBlinkTime = millis();
        buzzerState = !buzzerState;
        digitalWrite(BUZZER_PIN, buzzerState);
      }
      
    } else { 
      // SAFE ZONE: Green Light only, Buzzer off
      digitalWrite(GRN_LED, HIGH);
      digitalWrite(BUZZER_PIN, LOW);
    }

    delay(60); // Small delay to give the ultrasonic sensor time to settle
  }
