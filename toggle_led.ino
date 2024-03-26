const byte buttonPin = 2; // button between pin2 and ground
const byte LEDpin = 13; // pin that controls the LED

void setup() {
  pinMode(buttonPin, INPUT_PULLUP);
  pinMode(LEDpin, OUTPUT);
}

void loop() {
  if (!digitalRead(buttonPin)) {
    digitalWrite(LEDpin, !digitalRead(13));
    delay(500);
  }
}