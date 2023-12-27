/*
 * functions.c
 *
 *  Created on: Dec 25, 2023
 *      Author: Rehab
 */
#include "functions.h"
#include <stdio.h>
void disableBuffering() {
    // Disable buffering for stdout
    setvbuf(stdout, NULL, _IONBF, 0);

    // Disable buffering for stderr
    setvbuf(stderr, NULL, _IONBF, 0);
}
char mainMenu (void )
{
	printf("a. Turn on the vehicle engine.\n");
	printf("b. Turn off the vehicle engine.\n");
	printf("c. Quit the system.\n");
	char input;
	scanf(" %c",&input);
	return input;
	}
void turnedOn (void)
{
	printf("Turn on the vehicle engine.\n");

	}
void turnedOff(void)
{
	printf("Turned off the vehicle engine.\n");

}
void Quit(void)
{
	printf("Quit the system.\n");

	}
char sensorsMenu (void)
{
	printf ("a. Turn off the engine.\n");
	printf("b. Set the traffic light color : \n");
	printf("c. Set the room temperature : \n");
#if WITH_ENGINE_TEMP_CONTROLLER
	printf("d. Set the engine temperature : \n");
#endif
	char sensorsChioce;
	scanf("  %c",&sensorsChioce);
	return sensorsChioce;
	}
void trafficLightData(int *vehicleSpeed)
{
	printf("Enter traffic light color : ");

	char trafficLight;

	scanf(" %c", &trafficLight);
	if (trafficLight>=97 && trafficLight<=122)
	{
		trafficLight-=32;
	}
	switch (trafficLight) {
    case 'G':
        *vehicleSpeed = 100;
        break;
    case 'O':
        *vehicleSpeed = 30;
        break;
    case 'R':
        *vehicleSpeed = 0;
        break;
    default:
        printf("Invalid traffic light color!\n");
        break;
}
	}
void roomTempData(int *ACStatus, int *roomTemperature )
{
	printf("Enter the room temperature : ");

	short roomTemp;

	scanf(" %hi", &roomTemp);

	if (roomTemp<=10 && roomTemp>30)
	{
		*ACStatus =OFF;
		*roomTemperature = roomTemp;
	}
	else
	{
		*ACStatus =ON;
		*roomTemperature = 20;
	}
	}

#if WITH_ENGINE_TEMP_CONTROLLER
void engineTemperature(int *engineTempController,int *engineTemp)
{
	printf("Enter engine temperature :\n");
	int temp;
	scanf(" %d",&temp);
	if (temp>100&&temp<=150)
	{
		*engineTemp = 125;
		*engineTempController=ON;
	}
	else
	{
		*engineTempController=OFF;
	}
}
#endif
void STATUS (int *engineState, int *ACStatus, int *vehicleSpeed ,int *roomTemperature,int *engineTempController, int *engineTemp)
{
	*engineState == ON ? printf("Engine is ON\n"):printf("Engine is OFF\n");
	*ACStatus == ON ? printf("AC is ON\n"):printf("AC is OFF\n");
	printf("Vehicle Speed :%d Km/hr\n",*vehicleSpeed);
	printf("Room Temperature :%d C\n",*roomTemperature);

#if WITH_ENGINE_TEMP_CONTROLLER
	(*engineTempController) == ON ? printf("Engine Temp Controller is ON\n"):printf("Engine Temp Controller is OFF\n");
	printf("Engine Temperature: %d C\n\n",*engineTemp);
#endif
	printf ("\n\n\n");
	}
