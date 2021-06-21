#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void  ReadSenderdataFromConsole() 
{
  int Length=1024,line=0;
char Attribute1[Length],Attribute2[Length];
float TemperatureValue[Length];
 float SoCValue[Length];
 float AttributeValue1, AttributeValue2=0;
 while (scanf("%s%f,%s%f\n", Attribute1, &AttributeValue1, Attribute2, &AttributeValue2)!=EOF)
 {
   //printf("%s%0.2f,%s0.2%f\n",Attribute1, AttributeValue1, Attribute2, AttributeValue2);
   TemperatureValue[line]=AttributeValue1;
   SoCValue[line]= AttributeValue2;
   printf("%0.2f,%0.2f\n",AttributeValue1,AttributeValue2);
   delay (1);
   line++;
 }	 
 //scanf("%s%f,%s%f\n", Attribute1, &AttributeValue1, Attribute2, &AttributeValue2);
 //printf("%[^{]s%0.2f,%s0.2%f\n",Attribute1, AttributeValue1, Attribute2, AttributeValue2);
}
void delay(int number_of_seconds)
{
  
  int milli_seconds = 1000 * number_of_seconds;

  
  clock_t start_time = clock();

  while (clock() < start_time + milli_seconds);
}

int main()
{
  ReadSenderdataFromConsole();
  return 0;
}
