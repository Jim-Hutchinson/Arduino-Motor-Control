int motorPin = 9;          // The pin the motor is connected to
int potPin = A0;           // The pin the potentiometer is connected to
int buttonPin = 8;         // The pin the button is connected to
int potValue = 0;          // The value read from the potentiometer
int motorSpeed = 0;        // The speed of the motor
boolean motorOn = false;   // Whether the motor is currently on
unsigned long motorTime;   // The time the motor was turned on
unsigned long motorDelay;  // The time delay for the motor to turn off

void setup() {
  pinMode(motorPin, OUTPUT);
  pinMode(potPin, INPUT);
  pinMode(buttonPin, INPUT_PULLUP);
  Serial.begin(9600);
}

void loop() {
  // Wait for the button to be pressed
  while (digitalRead(buttonPin) == HIGH) {
  }
  delay(10000); //wait 10 seconds before starting

  // Button has been pressed, turn on the motor
  motorOn = true;
  motorTime = millis();
  motorDelay = 50000;  // Set the motor delay to 50 seconds (50000 milliseconds)

  // Loop while the motor is on and the timer has not expired
  while (motorOn && millis() - motorTime < motorDelay) {
    // Read the value of the potentiometer
    potValue = analogRead(potPin);

    // Map the potentiometer value (0-1023) to a motor speed (0-255)
    motorSpeed = map(potValue, 0, 1023, 0, 127);

    // Set the speed of the motor
    analogWrite(motorPin, motorSpeed);

    // Print the potentiometer value and motor speed to the serial monitor
    Serial.print("Potentiometer value: ");
    Serial.print(potValue);
    Serial.print(", Motor speed: ");
    Serial.println(motorSpeed);

    // Wait a short time before repeating the loop
    delay(10);
  }

  // Turn off the motor after the timer has expired
  analogWrite(motorPin, 0);
  motorOn = false;
}

