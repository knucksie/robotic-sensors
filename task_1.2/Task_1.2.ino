#define LED_PIN 8 // define LED pins
#define BUTTON_PIN 7

byte lastButtonState = LOW; // used to 
byte ledState = LOW;

unsigned long debounceDuration = 50; // button state validation period delta
unsigned long lastTimeButtonStateChanged = 0; // button state last changed time

void setup() {
  pinMode(LED_PIN, OUTPUT); // define pin mode for LED 
  pinMode(BUTTON_PIN, INPUT); // define pin mode for button
}

void loop() {
  if (millis() - lastTimeButtonStateChanged > debounceDuration) {
    byte buttonState = digitalRead(BUTTON_PIN); // read button pin value
    if (buttonState != lastButtonState) { // check whether button state has changed
      lastTimeButtonStateChanged = millis();
      lastButtonState = buttonState;
      if (buttonState == LOW) {
        ledState = (ledState == HIGH) ? LOW: HIGH;
        digitalWrite(LED_PIN, ledState); // change LED state
      }
    }
  }
}
