/*

 ============================================================================
 Project Name : Vehicle Control System
 Author       : Rehab Ahmed
 Project date : 25-12-2023
 ============================================================================

 */

#include <stdio.h>
#include <stdlib.h>
#include "functions.h"


int main(void) {
	disableBuffering();
	// function to disable buffering.
	char choice ;
	int engineState =OFF,vehicleSpeed=0 ,ACStatus = OFF, roomTemperature=33 ,engineTempController =OFF,engineTemp=90;
	do{
		        choice = mainMenu();
		        // execute main menu and check for input with switch case
				switch (choice)
				{
				case 'a':
				{
					turnedOn();
					engineState=ON;
					while (engineState)
					{
					char sensorsChioce =sensorsMenu();
					switch(sensorsChioce)
					{
				               case'a':
				            	   engineState=OFF;
				            	   vehicleSpeed=0;
							   break;
				               case'b':
				            	  trafficLightData(&vehicleSpeed);
				            	  if (vehicleSpeed==30)
				            	  {
				            		  ACStatus=ON;
				            		  roomTemperature = (float)(roomTemperature * 5/4) + 1;
#if WITH_ENGINE_TEMP_CONTROLLER
				            		  engineTempController=ON;
									  engineTemp = (float)(engineTemp * 5/4) + 1;

#endif
				            	  }
				            	   STATUS (&engineState,&ACStatus,&vehicleSpeed ,&roomTemperature,&engineTempController,&engineTemp);
				               break;
				               case'c':
				            	   roomTempData(&ACStatus,&roomTemperature);
				            	   STATUS (&engineState,&ACStatus,&vehicleSpeed ,&roomTemperature,&engineTempController,&engineTemp);
				               break;

#if WITH_ENGINE_TEMP_CONTROLLER
				               case'd':
				            	   engineTemperature(&engineTempController,&engineTemp);
				            	   STATUS (&engineState,&ACStatus,&vehicleSpeed ,&roomTemperature,&engineTempController,&engineTemp);
				               	break;
#endif
				               default:
				            	   printf("Invalid Input\n");
				            	   break;
					}

				}
				break;
				}
				case 'b':
					turnedOff();
					continue;
				case 'c':
					Quit();
					break;
				default:
					printf("Invalid input try again.\n");
					break;
				}
	}while (choice !='c' );

		return 0;
			}

