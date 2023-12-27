/*
 * functions.h
 *
 *  Created on: Dec 25, 2023
 *      Author: Rehab
 */

#ifndef FUNCTIONS_H_
#define FUNCTIONS_H_
#define ON 1
#define OFF 0
#define WITH_ENGINE_TEMP_CONTROLLER 1
void disableBuffering();
void trafficLightData(int *vehicleSpeed);
char mainMenu (void );
void turnedOn (void);
void turnedOff(void);
void Quit(void);
char sensorsMenu (void);
void roomTempData(int *ACStatus, int *roomTemperature );
#if WITH_ENGINE_TEMP_CONTROLLER
void engineTemperature(int *engineTempController,int *engineTemp);
#endif
void STATUS (int *engineState, int *ACStatus, int *vehicleSpeed ,int *roomTemperature,int *engineTempController, int *engineTemp);

#endif /* FUNCTIONS_H_ */
