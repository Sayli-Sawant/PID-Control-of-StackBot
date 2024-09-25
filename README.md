# Stackbot PID Control System

## Goal
Develop a PID control system for Stackbot using an ARM Cortex-based Microbit to achieve precise straight-line movement by integrating motor drivers, encoders, and touch sensors. The system enhances motor control and navigation accuracy through real-time feedback and PID tuning.

## Requirements

### Hardware
- ARM Cortex-based Microbit
- Motor driver circuit
- DC motors with encoders
- 12V battery for motors
- 5V battery for Microbit

### Software
- Keil for Embedded C Programming

## Working
- The **PID controller** adjusts motor speed based on encoder feedback, ensuring precise straight-line movement.
- **Encoders** measure real-time RPM, and the PID adjusts the duty cycle for each motor.
- **Touch sensors** control robot operation (start/stop).
- Tuning of PID constants minimizes error, providing smooth and accurate movement.
