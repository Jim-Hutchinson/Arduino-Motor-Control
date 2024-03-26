const byte buttonPin = 2; // button between pin2 and ground

void setup() {
  pinMode(buttonPin, INPUT_PULLUP);
  pinMode(13, OUTPUT);
}

void loop() {
  if (!digitalRead(buttonPin)) {
    digitalWrite(13, !digitalRead(13));
    delay(500);
  }
}