  // SOURCE CODE (C++)
  #include <Adafruit_NeoPixel.h>


  #define PIN 6         // Data pin connected to DI
  #define NUMPIXELS 8   // 8 LEDs on your straight module
  #define POT_PIN A0    // Potentiometer center pin
  #define BUZZER_PIN 9  // Audio pin connected to buzzer


  Adafruit_NeoPixel strip(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);


  void setup() {
    strip.begin();
    strip.show();  // Initialize all pixels to 'off'
    pinMode(BUZZER_PIN, OUTPUT);
  }


  void loop() {
    int potVal = analogRead(POT_PIN);  // Read dial (0 to 1023)

    // 1. Map color spectrum (0-65535)
    int hue = map(potVal, 0, 1023, 0, 65535);

    // 2. Map audio frequencies (Low 150Hz to Laser 1500Hz)
    int frequency = map(potVal, 0, 1023, 150, 1500);


    for (int i = 0; i < NUMPIXELS; i++) {
      strip.setPixelColor(i, strip.gamma32(strip.ColorHSV(hue, 255, 120)));
    }
    strip.show();

    // Generates the smooth sweeping synth frequency tone
    tone(BUZZER_PIN, frequency);

    delay(15);  // Smooth rendering delay
  }