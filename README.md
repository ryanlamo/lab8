# Lab 8
Main.c code to program robot to navigate maze. 

## Notes About Lab
This lab requires the following header and implementation from previous labs to run
 - From Lab 6
    - `robot.c` and `robot.h`
 - From Lab 7 
    - `sensor.c` and `sensor.h`

The header files must be included in this main.c file for the program to run properly. 

## Basic Flow of Program 

This robot is a left-wall following robot. To move, robot uses following steps to check for a wall:

 - 1. Robot first checks center sensor for wall. If sees a wall, it will get sensor reading from left sensor. If there is no wall to the left, it will turn left, otherwise it will turn right. 
 - 2. If no wall in front, robot will move forward as a "left-following" robot, meaning it will stay close to the left wall at all times. 
 - 3. If robot senses it is getting too close to left wall or right wall, it will make small adjustments. 
 
## Functions

- Code available to the User
  - anything on either the Lab 6 or Lab 7 files

- Code used for this Program 
  - From Lab 6
      - `moveRobotRight`
      - `moveRobotLeft`
      - `moveRobotForward`
      - `moveRobotBack`
      - `stopRobot`
  
  - From Lab 7 
      - `getCenterSensorReading`
      - `getRightSensorReading`
      - `getLeftSensorReading`
      
