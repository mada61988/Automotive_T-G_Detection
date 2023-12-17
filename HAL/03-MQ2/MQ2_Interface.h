// HeaderGuard
#ifndef _MQ2_INTERFACE_
#define _MQ2_INTERFACE_


int  GetPercentage(float rs_ro_ratio, float *pcurve);
int GetGasPercentage(float rs_ro_ratio, int gas_id);
float ReadSensor();
float ResistanceCalculation(int raw_adc);
float SensorCalibration();

#define LPG (0)         // Gas identity no.
#define SMOKE (1)



#endif

