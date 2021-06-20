#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>


void  ReadSenderdataFromConsole() 
{
  int Length=100,line=0;
char Attribute1[Length],Attribute2[Length];
char TemperatureValue[Length];
 char SoCValue[Length];
 float AttributeValue1, AttributeValue2=0;
 while (scanf("%s%f,%s%f\n", Attribute1, &AttributeValue1, Attribute2, &AttributeValue2)!=EOF)
 {
   printf("%[^{]s%0.2f,%s0.2%f\n",Attribute1, AttributeValue1, Attribute2, AttributeValue2);
   TemperatureValue[line]=AttributeValue1;
   SoCValue[line]= AttributeValue2;
   line++;
 }	 
 //scanf("%s%f,%s%f\n", Attribute1, &AttributeValue1, Attribute2, &AttributeValue2);
 //printf("%[^{]s%0.2f,%s0.2%f\n",Attribute1, AttributeValue1, Attribute2, AttributeValue2);
}

int main()
{
  ReadSenderdataFromConsole();
  return 0;
}
