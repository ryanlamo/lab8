/* Author: C1C Ryan Lamo
 * Created: 11 December 2013
 * Last Edited: 11 December 2013
 * Description: This code will program the robot to navigate a maze in a left-wall following fashion.
 * Documentation: Capt Branchflower helped explain how to order the if else statements so the robot would move properly.
 * C2C Bentley helped me understand how to make the if statements so the robot would stop as it got close to the wall
 */

#include "Lab7/sensor.h"
#include "Lab6/robot.h"
#include <msp430.h> 

//unsigned int leftSensor, rightSensor, centerSensor;

int main(void) {
    WDTCTL = WDTPW | WDTHOLD;	// Stop watchdog timer

    initPWM();
    initADC();

    for(;;)				//Left wall following program
    {
    	if (getCenterSensorReading() > 0x1c0)
    	{
    		stopRobot();
    		__delay_cycles(1000000);
    		moveRobotBackward();
    		__delay_cycles(1000000);

    		if (getLeftSensorReading() < 0x100)
    		{
    			moveRobotLeft();
    			__delay_cycles(100000);
    			stopRobot();
    		}
    		else
    		{
    			moveRobotRight();
    			__delay_cycles(2000000);
    			stopRobot();
    		}

    	}
    	else if (getLeftSensorReading() > 0x1a0)
    	{
    		moveRobotRight();
    		__delay_cycles(10000);
    	}
    	else if (getRightSensorReading() > 0x1a0)
    	{
    		moveRobotLeft();
    		__delay_cycles(500);
    	}
    	else
    	{
    		moveRobotForward();
    		__delay_cycles(10000);
    	}


    }
	
	return 0;
}

#pragma vector=ADC10_VECTOR
__interrupt void ADC10_ISR(void)
{
	__bic_SR_register_on_exit(CPUOFF);
}
