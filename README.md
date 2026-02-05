# PID-Motor-Controller
Closed-loop DC motor speed control using quadrature encoder feedback and PID control on an ESP32.

## Hardware Used
- ESP32 (ESP-WROOM-32 development board)
- TB6612FNG dual motor driver
- DC motor
- Breadboard and jumper wires
- External motor power supply

## Features
- Motor enable/disable using standby control
- Bidirectional motor control (CW / CCW)
- Variable speed control using PWM
- ESP32 hardware PWM (LEDC)

## How It Works
- The ESP32 controls motor direction using the AIN1 and AIN2 pins on the TB6612FNG.
- Motor speed is controlled using a PWM signal on the PWMA pin.
- The STBY pin must be set HIGH to enable the motor driver.
- PWM duty cycle determines the effective motor speed.

## Current Status
- [x] Motor spins in both directions
- [x] PWM speed control implemented
- [ ] Closed-loop control (PID) (In Progress)
- [ ] Encoder feedback (In Progress)

## Photos
<img width="1342" height="620" alt="image" src="https://github.com/user-attachments/assets/c6e96963-03a2-463d-a798-a95835611392" />
<img width="603" height="1307" alt="image" src="https://github.com/user-attachments/assets/b85d156f-af14-4835-80ea-d887a84b94b0" />

## Future Improvements
- Add quadrature encoder support
- Implement closed-loop speed control using PID
- Add serial commands for dynamic speed control
- Log motor speed data for analysis
- Improve mechanical mounting and wiring robustness
