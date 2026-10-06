// Stepper motor pins
const int stepPin = 2;
const int dirPin = 3;

// Limit switches
const int lsStart = 2;
const int lsEnd = 3;

// Reed switch
const int reed1 = 7;

bool motorOn = true;
bool lastReedState = LOW;

void setup() {
  pinMode(stepPin, OUTPUT);
  pinMode(dirPin, OUTPUT);

  pinMode(lsStart, INPUT);
  pinMode(lsEnd, INPUT);

  pinMode(reed1, INPUT_PULLUP);

  Serial.begin(9600);

  digitalWrite(dirPin, HIGH);
}

void loop() {
    Serial.println("gdsfuihj");
  bool currentReedState = digitalRead(reed1);

  // Detect a NEW activation of the reed switch
  if (currentReedState == LOW && lastReedState == HIGH) {

    Serial.println("Reed switch detected!");
    
    // Stop motor for 1 second
    delay(1000);

    Serial.println("Continuing motor...");
  }

  // Update previous state
  lastReedState = currentReedState;

  Serial.println(motorOn);
  // Run motor
  if (motorOn) {
    digitalWrite(stepPin, HIGH);
    delayMicroseconds(100);

    digitalWrite(stepPin, LOW);
    delayMicroseconds(100);
  }
}