# Light Sensor

## Description

This project uses a Light Dependent Resistor (LDR) to detect the intensity of light in the environment. The LED will turn on when the environment is dark and turn off when it is bright.

## Components

- Arduino (e.g., Arduino Uno)
- LDR Sensor
- LED
- Jumper Wires
- 10kΩ Resistor (for the LDR)

## Pin Configuration

| Component | Arduino Pin     |
| --------- | --------------- |
| LDR       | A0 (Analog Pin) |
| LED       | 8 (Digital Pin) |

## Code

```cpp
const int pinLDR = 0; // Initialize LDR sensor on analog pin A0
const int pinLED = 8; // Initialize LED on pin 8
int sensorValue = 0;  // Store the sensor reading value
int outputValue = 0;  // Scale the sensor value

void setup() {
  pinMode(pinLED, OUTPUT);  // Set pin 8 as output for LED
}

void loop() {
  sensorValue = analogRead(pinLDR);  // Read the sensor value
  // Scale the sensor value (0-1023) to output value (0-500)
  outputValue = map(sensorValue, 0, 1023, 0, 500);

  // Check if outputValue is less than or equal to 300, indicating darkness
  if (outputValue <= 300) {
    digitalWrite(pinLED, HIGH); // Turn the LED on
  } else {
    digitalWrite(pinLED, LOW);  // Turn the LED off
  }

  delay(200);  // Wait for 200ms before the next loop
}
```

## How It Works

1. LDR Sensor:
   - The LDR is connected to the analog pin A0, and it reads the surrounding light intensity.
   - The sensorValue from the LDR is between 0 (complete darkness) and 1023 (very bright).
2. Mapping and Detection:
   - The map() function scales the sensor values to a range between 0 and 500.
   - If the outputValue is less than or equal to 300 (indicating a dark environment), the LED will turn on. Otherwise, it will remain off in a bright environment.

## Usage

1. Connect the LDR sensor and LED to the Arduino based on the pin configuration.
2. Upload the code to the Arduino.
3. The LED will light up in a dark environment and turn off in a bright one.

## Notes

- You can adjust the threshold value in the if statement to suit different lighting conditions.
- Ensure the correct connection of the LDR and LED components.
