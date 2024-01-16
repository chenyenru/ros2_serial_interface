#include <Servo.h>

Servo servo1; // Define a servo object

const char move_straight = 'w';
const char turn_right = 'd';
const char turn_left = 'a';

void setup() {
  // Initialize Serial Communication
  Serial.begin(9600);

  // Attach the servo to the specified pin
  servo1.attach(9);
}

void runCommand(char command) {
  if (command == move_straight) {
    Serial.println("Move Straight");
    // Adjust the servo position to move straight (center position)
    servo1.write(90);
  } else if (command == turn_right) {
    Serial.println("Turn Right");
    // Adjust the servo position to turn right
    servo1.write(135);
  } else if (command == turn_left) {
    Serial.println("Turn Left");
    // Adjust the servo position to turn left
    servo1.write(45);
  }
}

void loop() {
  // Check for serial commands and execute corresponding actions
  if (Serial.available()) {
    char command = Serial.read();
    runCommand(command);
  }
}