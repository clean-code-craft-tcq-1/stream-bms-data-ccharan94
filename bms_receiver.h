#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef enum {
  Failure,
  Success
} OperationMode;

#define Max_ArraySize 1024
#define NumberOfAttributes 2
extern float Temperature[Max_ArraySize];
extern float ChargeRate[Max_ArraySize];

extern float MinimumAttributeValueArray[NumberOfAttributes];
extern float MaximumAttributeValueArray[NumberOfAttributes];

extern OperationMode BMS_ReadfromConsole();
extern void Calculate_TemperatureMinandMaxRange(int NoOfEnteries);
extern void Calculate_ChargeRateMinandMaxRange(int NoOfEnteries);
extern void Calculate_MaxParameterValue(float AttributeValue[Max_ArraySize], float *MaximumAttributeValue);
extern void Calculate_MinParameterValue(float AttributeValue[Max_ArraySize], float *MinimumAttributeValue);
extern void Calculate_TemperatureSimpleMovingAverage(int NoOfEnteries);
extern void Calculate_ChargeRateSimpleMovingAverage(int NoOfEnteries);
extern float Calculate_SimpleMovingAverage(float AttributeValue[NoOfEnteries]);
  
