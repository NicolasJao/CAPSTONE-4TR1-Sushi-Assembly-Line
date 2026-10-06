// Stepper motor pins
const int stepPin = 2;
const int dirPin = 3;


bool motorOn = true;

void setup() {
  pinMode(stepPin, OUTPUT);
  pinMode(dirPin, OUTPUT);


  Serial.begin(9600);

  digitalWrite(dirPin, HIGH);
}

void loop() {


  
  //Serial.println(motorOn);
  // Run motor
  if (motorOn) {
    digitalWrite(stepPin, HIGH);
    delayMicroseconds(1200);

    digitalWrite(stepPin, LOW);
    delayMicroseconds(1200);
  }
}