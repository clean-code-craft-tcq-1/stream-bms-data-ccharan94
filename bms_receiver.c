#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>


void  ReadSenderdataFromConsole() 
{
  int i=0, length=100;
char Attribute1[Length],Attribute2[Length]=0;
 float AttributeValue1, AttributeValue2=0;
//if (scanf("%11c[^:]%f,%3c[^:]%f\n", Attribute1, AttributeValue1, Attribute2,AttributeValue2)==4);
  scanf("%11c[^:]%f,%3c[^:]%f\n", Attribute1, &AttributeValue1, Attribute2, &AttributeValue2);
	printf("%f,%f\n",AttributeValue1, AttributeValue2);
}

void main()
{
  ReadSenderdataFromConsole();
  return0;
}
