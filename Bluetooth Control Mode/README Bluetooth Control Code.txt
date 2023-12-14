
# Matatu Bluetooth Control Code

## Overview
This Arduino code is designed for controlling an Arduino Matatu using Bluetooth communication. The code allows for various commands to control the movement of the vehicle, turn on/off LEDs, and more.

## Features
- **Motor Control:** Move the Matatu forward, backward, turn left, turn right, stop, and more.
- **LED Control:** Turn on/off front and rear LEDs for visibility.
- **Buzzer Control:** Beep buzzer as horn.
- **Bluetooth Communication:** Communicate wirelessly with the Arduino using Bluetooth commands.

## Hardware Requirements
- Arduino board
- Matatu Chasis 
- Motor driver (L298N)
- Bluetooth module (HC-05)
- LEDs 
- TT Geared Motors with Wheels  
- Buck Step down DC to DC converter  
- Resistors
- Buzzer
- SPST Switch 
- Jumper wires
- Breadboard  

## Setup Instructions
1. Connect the hardware components based on the provided pin configurations in the code.
2. Upload the code to your Arduino board.
3. Ensure that the Bluetooth module is paired with the controlling device (e.g., smartphone).
4. Open a serial communication tool (Download Serial Bluetooth Terminal, on the google play store) on the controlling device and send the specified commands to control the Matatu.
5. Use MIT App Inventor to build a nice Custom interface for your Project 

## Usage
- Use a Bluetooth-enabled device (e.g., smartphone) to send commands to the Arduino over Bluetooth.
- See below a list of supported commands and their corresponding actions.
	B or b (Backwards):
		Motor control to move the Matatu backward.
		Activation of a buzzer tone during backward movement.

	F or f (Forward):
		Motor control to move the Matatu forward.

	R or r (Right):
		Motor control to turn the Matatu to the right.

	L or l (Left):
		Motor control to turn the Matatu to the left.

	C or c:
		Tail chase mode

	A or a:
		Tail chase mode

	S or s (Stop):
		Stop the movement of the Matatu by turning off all motors.

	X or x:
		Turn on the front LEDs.

	Z or z:
		Turn off the front LEDs.

	Y or y:
		Turn on the rear LEDs.

	U or u:
		Turn off the rear LEDs.

	H or h:
		Beep the Buzzer.


## Troubleshooting
- If the Matatu is not responding as expected, check the hardware connections and ensure that the Bluetooth module is properly paired.
- Review the serial output on the Arduino IDE or a serial monitor for debugging information.

## License
This code is provided under the [MIT License]. See the `LICENSE` file for details.

