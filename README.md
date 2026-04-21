# PID-Motor-Controller
This project explores the design and implementation of a DC motor control system using an ESP32 microcontroller. The current implementation focuses on open-loop motor speed control using PWM, with plans to integrate encoder feedback for closed-loop speed regulation.

## Hardware Used
- ESP32 (ESP-WROOM-32 development board)
- TB6612FNG dual motor driver
- DC motor
- Breadboard and jumper wires
- External motor power supply

## Software Tools
- Arduino IDE
- ESP32 Arduino Core
- C/C++ for embedded programming

## Current Functionality
- Generates a PWM signal using the ESP32 LEDC peripheral
- Controls motor speed by adjusting PWM duty cycle
- Controls motor direction via digital GPIO pins
- Demonstrates reliable open-loop motor operation

## How It Works
- The ESP32 controls motor direction using the AIN1 and AIN2 pins on the TB6612FNG.
- Motor speed is controlled using a PWM signal on the PWMA pin.
- The STBY pin must be set HIGH to enable the motor driver.
- PWM duty cycle determines the effective motor speed.

## Current Status
- [x] Motor spins in both directions
- [x] PWM speed control implemented
- [x] Closed-loop control (PID) 
- [x] Encoder feedback

Unfortunately I don't have a DC Power supply of 12V to fully power the motor so 5V will do now. On the lookout for cheap dc power supply to connect to.

## Photos
<img width="1878" height="1010" alt="image" src="https://github.com/user-attachments/assets/8aacc747-71dc-4e4c-9303-f6bcc7c3a1d1" />


## Future Improvements
- Improve mechanical mounting and wiring robustness
- Add temperature sensor and fan to make it smart fan based on temperature sensor and pid control
