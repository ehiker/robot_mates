#include "MoleGraph.h"

const int line_sensor_analog_pin = A1;
const int line_sensor_digital_pin = 3;
const int line_sensor_power_pin = 2; // Line sensor is powered by digital out pin

int line_sensor_state = 0;
int line_sensor_value = 0;

MoleGraph moleGraph;

void UpdateGraphChannels(void)
{
  line_sensor_value = analogRead(line_sensor_analog_pin);
  line_sensor_state = digitalRead(line_sensor_digital_pin);
  moleGraph.SetChannelValue(1, line_sensor_value);
  moleGraph.SetChannelValue(2, line_sensor_state);
}

void MeasurementStartedCallback(void)
{
}

void MeasurementStoppedCallback(void)
{
}

void MeasurementPausedCallback(void)
{
}

void MeasurementContinuedCallback(void)
{
}

void setup() {
  // put your setup code here, to run once:
  
  pinMode(line_sensor_digital_pin, INPUT);
  
  pinMode(line_sensor_power_pin, OUTPUT);
  digitalWrite(line_sensor_power_pin, HIGH);  // Power the line sensor up
  
  pinMode(LED_BUILTIN, OUTPUT);
  digitalWrite(LED_BUILTIN, HIGH);  // Turn the user LED on

  moleGraph.Setup();
  moleGraph.SetSendingCallback(&UpdateGraphChannels);
  moleGraph.SetMeasurementStartedCallback(&MeasurementStartedCallback);
  moleGraph.SetMeasurementStoppedCallback(&MeasurementStoppedCallback);
  moleGraph.SetMeasurementPausedCallback(&MeasurementPausedCallback);
  moleGraph.SetMeasurementContinuedCallback(&MeasurementContinuedCallback);
}

void loop() {
  // put your main code here, to run repeatedly:

  moleGraph.CheckInput();
}
