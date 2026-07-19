# Pothole Filling Robot

## Overview

An Arduino-based mobile robot designed to detect and temporarily fill road potholes. The robot is manually navigated using a wired joystick, while an ultrasonic sensor detects potholes by measuring road surface variations.

## Features

* Automatic pothole detection using an ultrasonic sensor
* Servo-controlled sand dispensing mechanism
* Joystick control disabled during filling for safe operation
* Manual navigation restored after filling

## Hardware

* Arduino Uno
* HC-SR04 Ultrasonic Sensor
* Servo Motor
* DC Motors & Motor Driver
* Wired Joystick

## Software

* Arduino IDE
* Embedded C

## Working

The robot is manually driven to the target area. When a pothole is detected, the Arduino automatically halts movement, opens the sand container using a servo motor to fill the pothole, then closes the container and re-enables manual control.




