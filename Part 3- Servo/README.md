# Servo motor

## Servo Library

This library allows an Arduino board to control RC (hobby) servo motors. Servos have integrated gears and a shaft that can be precisely controlled. Standard servos allow the shaft to be positioned at various angles, usually between 0 and 180 degrees. Continuous rotation servos allow the rotation of the shaft to be set to various speeds.

## Pinout 
![servo_motor](https://user-images.githubusercontent.com/32713072/36919577-403a7e00-1e77-11e8-9813-5602cbb6cbdf.jpg) <br/>

- Red wire - VCC or power supply
- Brown wire - ground
- Yellow wire - control signal

## Controlling a servo motor

The servo connector carries the control signal, used to tell the motor where to go. This control signal is a specific type of pulse train. The pulses occur at a 20 mSec (50 Hz) interval, and vary between 1 and 2 mSec in width. The Pulse Width Modulation hardware available on a microcontroller is a great way to generate servo control signals.

## Description of the module

-	A servo motor is an electrical device which can push or rotate an object with great precision. If you want to rotate and object at some specific angles or distance, then you use servo motor.
-	If motor is used is DC powered then it is called DC servo motor, and if it is AC powered motor then it is called AC servo motor. 
-	used in many applications like toy car, RC helicopters and planes, Robotics, Machine etc.
-	Servo motor works on PWM (Pulse width modulation) principle, means its angle of rotation is controlled by the duration of applied pulse to its Control PIN. Basically servo motor is made up of DC motor which is controlled by a variable resistor (potentiometer) and some gears. High speed force of DC motor is converted into torque by Gears.
-	Servo motors are generally an assembly of four things: a DC motor, a gearing set, a control circuit and a position-sensor (usually a potentiometer).

## Servo motor VS DC motors
![brushless-vs-servo-structure](https://user-images.githubusercontent.com/32713072/36919863-31f31afe-1e78-11e8-8de3-a9d0bc203e50.jpg)
<br/>
-	The position of servo motors can be controlled more precisely than those of standard DC motors, and they usually have three wires (power, ground & control). Power to servo motors is constantly applied, with the servo control circuit regulating the draw to drive the motor. Servo motors are designed for more specific tasks where position needs to be defined accurately such as controlling the rudder on a boat or moving a robotic arm or robot leg within a certain range.
-	Servo motors do not rotate freely like a standard DC motor. Instead the angle of rotation is limited to 180 Degrees (or so) back and forth. Servo motors receive a control signal that represents an output position and applies power to the DC motor until the shaft turns to the correct position, determined by the position sensor.
