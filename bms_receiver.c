#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "bms_receiver.h"

/***********************************************************************************************************************
**************************************************************************************************************************/
float MinimumAttributeValueArray[NumberOfAttributes]= {0,0};
float MaximumAttributeValueArray[NumberOfAttributes]= {0,0};
float Temperature[Max_ArraySize]={};
float ChargeRate[Max_ArraySize]={};
int NoOfEntery=0;

OperationMode BMS_ReadfromConsole()
{
  FILE *BMS_datafile;
  int line=1, Index=0;
  OperationMode ReadStatus= Failure;

  BMS_datafile=fopen("BMS_attributelog.txt", "r");
  if (BMS_datafile==NULL)
    {
      printf("File open attempt failed\n");

    }
	
else
    {
    
      float ReadTemperature=0,ReadChargeRate=0;
      printf("File open attempt successful\n");
    
      while(line != EOF)
        {
          line=fscanf(BMS_datafile,"%f %f",&ReadTemperature,&ReadChargeRate);
          Temperature[Index]=ReadTemperature;
          ChargeRate[Index]=ReadChargeRate;
          Index++;
        }
        NoOfEntery= Index;
        ReadStatus= Success;
    }
	
	fclose(BMS_datafile);
	return ReadStatus;
}
/***********************************************************************************************************************
**************************************************************************************************************************/

void Calculate_TemperatureMinandMaxRange(int NoOfEnteries)
{
 Calculate_MinParameterValue(Temperature, NoOfEnteries, &MinimumAttributeValueArray[0]);
 Calculate_MaxParameterValue(Temperature, NoOfEnteries, &MaximumAttributeValueArray[0]);
 printf("Minimum and Maximum Temperature in the given range is %0.2f and %0.2f respectively\n",MinimumAttributeValueArray[0],MaximumAttributeValueArray[0]);
}

/***********************************************************************************************************************
**************************************************************************************************************************/
void Calculate_ChargeRateMinandMaxRange(int NoOfEnteries)
{
  
  Calculate_MinParameterValue(ChargeRate, NoOfEnteries, &MinimumAttributeValueArray[1]);
  Calculate_MaxParameterValue(ChargeRate, NoOfEnteries, &MaximumAttributeValueArray[1]);
  printf("Minimum and Maximum ChargeRate in the given range is %0.2f and %0.2f respectively\n",MinimumAttributeValueArray[1],MaximumAttributeValueArray[1]);
}
/***********************************************************************************************************************
**************************************************************************************************************************/
 void Calculate_MaxParameterValue(float AttributeValue[], int NoOfEnteries, float *MaximumAttributeValue)
 {
   for(int i=0; i< NoOfEnteries; i++)
   {
        if(AttributeValue[i] > *MaximumAttributeValue)
        {
            *MaximumAttributeValue = AttributeValue[i];
        }
   }
   
 }
/***********************************************************************************************************************
**************************************************************************************************************************/    
void Calculate_MinParameterValue(float AttributeValue[], int NoOfEnteries, float *MinimumAttributeValue)
 {
  for(int i=0; i< NoOfEnteries; i++)
   {
     
     if(AttributeValue[i] < *MinimumAttributeValue)
          {
              *MinimumAttributeValue = AttributeValue[i];
          }
   }
}
/***********************************************************************************************************************
**************************************************************************************************************************/
void Calculate_TemperatureSimpleMovingAverage(int NoOfEnteries)
{
  float Temperature_SMA= Calculate_SimpleMovingAverage(Temperature, NoOfEnteries);
  printf("Simple moving average of Temperature is %0.2f\n",Temperature_SMA);
}
/***********************************************************************************************************************
**************************************************************************************************************************/
void Calculate_ChargeRateSimpleMovingAverage(int NoOfEnteries)
{
  float ChargeRate_SMA= Calculate_SimpleMovingAverage(ChargeRate, NoOfEnteries);
  printf("Simple moving average of Charge Rate is %0.2f\n",ChargeRate_SMA);
}
/***********************************************************************************************************************
**************************************************************************************************************************/
float Calculate_SimpleMovingAverage(float AttributeValue[], int NoOfEnteries)
{
  float AttributeAverage = 0;
  float AttributeSum = 0;
  for(int i=(NoOfEnteries-6); i< NoOfEnteries; i++)
   {
     AttributeSum+= AttributeValue[i];
     
   }
   AttributeAverage = AttributeSum/5;

   return AttributeAverage;
  
}
/***********************************************************************************************************************
**************************************************************************************************************************/
OperationMode ReceiveDatafromSender ()
{
  OperationMode ReadStatus= BMS_ReadfromConsole();
    printf("%d\n",NoOfEntery);
    Calculate_TemperatureMinandMaxRange(NoOfEntery);
    Calculate_ChargeRateMinandMaxRange(NoOfEntery);
    Calculate_TemperatureSimpleMovingAverage(NoOfEntery);
    Calculate_ChargeRateSimpleMovingAverage(NoOfEntery);
  return (ReadStatus);
}
