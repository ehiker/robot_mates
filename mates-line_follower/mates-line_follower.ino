// include the Servo library
#include <Servo.h>

const int line_sensor_analog_pin = A1;
const int line_sensor_digital_pin = 3;
const int line_sensor_power_pin = 2; // Line sensor is powered by digital out pin

int line_sensor_state = 0;
int line_sensor_value = 0;

const int black = 1;  // Line sensor state defines black line under the sensor

const int left_wheel_pin = 11;  // Servo control signal output
const int right_wheel_pin = 9;

Servo left_wheel;
Servo right_wheel;

const int out_speed = 1800; // Outer wheel speed
const int in_speed = 1600;  // Inner wheel speed

void setup() {
  // put your setup code here, to run once:
  
  pinMode(line_sensor_digital_pin, INPUT);
  
  left_wheel.attach(left_wheel_pin);
  right_wheel.attach(right_wheel_pin);

  pinMode(line_sensor_power_pin, OUTPUT);
  digitalWrite(line_sensor_power_pin, HIGH);  // Pwer the line sensor up
  
  pinMode(LED_BUILTIN, OUTPUT);
  digitalWrite(LED_BUILTIN, HIGH);  // Turn the user LED on

  left_wheel.writeMicroseconds(1500); // Breake the wheels...
  right_wheel.writeMicroseconds(1500);

  delay(3000);                        // ...for 3s
}

void loop() {
  // put your main code here, to run repeatedly:

  line_sensor_state = digitalRead(line_sensor_digital_pin);

  // Read also sensor's analog value for future purposes
  line_sensor_value = analogRead(line_sensor_analog_pin);

  if (line_sensor_state == black)
  {
    left_wheel.writeMicroseconds(out_speed);
    right_wheel.writeMicroseconds(in_speed); 
  }
  else
  {
    left_wheel.writeMicroseconds(in_speed);
    right_wheel.writeMicroseconds(out_speed);
  }
      
  delay(50);
}
