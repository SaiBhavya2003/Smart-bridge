#include <Servo.h>

#include <Servo.h>

Servo tap_servo;

int sensor_pin = 5;
int tap_servo_pin =4;
int val;


const int soilMoisturePin = A0;
const int servoPin = 9; // Adjust these pin numbers according to your setup
const int servo2Pin = 10; // Second servo pin
const int moistureThreshold = 500; // Adjust this value according to your sensor's readings

Servo bridgeServo;
Servo bridgeServo2;

// Define angles for lifted and lowered positions
const int liftedAngle = 90;
const int loweredAngle = 0;

void setup() {
pinMode(soilMoisturePin, INPUT);
bridgeServo.attach(servoPin);
bridgeServo2.attach(servo2Pin);
}

void loop() {
int moistureLevel = analogRead(soilMoisturePin);

if (moistureLevel < moistureThreshold) {
// If soil is moist enough, lift the bridge
liftBridge();
} else {
// Otherwise, keep the bridge down
lowerBridge();
}
}

void liftBridge() {
// Move the servo motors to lift the bridge
bridgeServo.write(liftedAngle); // Use lifted angle
bridgeServo2.write(liftedAngle); // Second servo angle
delay(1500); // Adjust delay as needed
}

void lowerBridge() {
// Move the servo motors to lower the bridge
bridgeServo.write(loweredAngle); // Use lowered angle
bridgeServo2.write(loweredAngle); // Second servo angle
delay(1500); // Adjust delay as needed
}
