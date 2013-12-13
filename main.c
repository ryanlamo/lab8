/* Author: C1C Ryan Lamo
 * Created: 11 December 2013
 * Last Edited: 11 December 2013
 * Description: This code will program the robot to navigate a maze in a left-wall following fashion.
 * Documentation:
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
    	if (getCenterSensorReading() > 0x1b0)
    	{
    		stopRobot();
    		__delay_cycles(1000000);
    		moveRobotBackward();
    		__delay_cycles(750000);
    		moveRobotRight();
    		__delay_cycles(1000000);
    		stopRobot();
    	}
    	else if (getLeftSensorReading() > 0x1a0)
    	{
    		moveRobotRight();
    		__delay_cycles(10000);
    	}
    	else if (getRightSensorReading() > 0x1a0)
    	{
    		moveRobotLeft();
    		__delay_cycles(1000);
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
