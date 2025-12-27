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
- [ ] Closed-loop control (PID)
- [ ] Encoder feedback

## Future Improvements
- Add encoder feedback for speed measurement
- Implement PID speed control
- Add serial input for runtime speed/direction control
- Improve power management and safety handling

## What I Learned
- Reading and applying motor driver datasheets
- Using ESP32 hardware PWM (LEDC)
- Safe motor direction switching
- Practical embedded debugging
