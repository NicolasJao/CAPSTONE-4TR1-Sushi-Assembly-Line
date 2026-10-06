/*     Simple Stepper Motor Control Exaple Code
 *      
 *  by Dejan Nedelkovski, www.HowToMechatronics.com
 *  
 */

// defines pins numbers
const int stepPin = 4; 
const int dirPin = 5; 
 
void setup() {
  // Sets the two pins as Outputs
  pinMode(stepPin,OUTPUT); 
  pinMode(dirPin,OUTPUT);
  Serial.begin(9600);
}
void loop() {
if (Serial.available() > 0){
  String input = Serial.readString();
  input.trim();
  Serial.println(input);


  if (input == "close"){
    digitalWrite(dirPin,LOW); //Changes the rotations direction --> LOW IS CCW
    // Makes 400 pulses for making two full cycle rotation
    for(int x = 0; x < 1000; x++) {
      digitalWrite(stepPin,HIGH);
      delayMicroseconds(250);
      digitalWrite(stepPin,LOW);
      delayMicroseconds(250);
      //Serial.println(x);
    }
  } else if (input == "open"){
    digitalWrite(dirPin,HIGH); // Enables the motor to move in a particular direction --> HIGH is CW
    // Makes 200 pulses for making one full cycle rotation
    for(int x = 0; x < 1000; x++) {
      digitalWrite(stepPin,HIGH); 
      delayMicroseconds(250); 
      digitalWrite(stepPin,LOW); 
      delayMicroseconds(250); 
      //Serial.println(x);
    }
  }

}
/*
  digitalWrite(dirPin,HIGH); // Enables the motor to move in a particular direction --> HIGH is CW
  // Makes 200 pulses for making one full cycle rotation
  for(int x = 0; x < 200; x++) {
    digitalWrite(stepPin,HIGH); 
    delayMicroseconds(500); 
    digitalWrite(stepPin,LOW); 
    delayMicroseconds(500); 
  }
  delay(1000); // One second delay
  
  digitalWrite(dirPin,LOW); //Changes the rotations direction --> LOW IS CCW
  // Makes 400 pulses for making two full cycle rotation
  for(int x = 0; x < 400; x++) {
    digitalWrite(stepPin,HIGH);
    delayMicroseconds(500);
    digitalWrite(stepPin,LOW);
    delayMicroseconds(500);
  }
  delay(1000);*/
}