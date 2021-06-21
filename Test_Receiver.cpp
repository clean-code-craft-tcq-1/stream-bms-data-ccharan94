

#include "test/catch.hpp"
#include "BMS_AttributeDataSender.h"

TEST_CASE("To check if file was successfully opened to read") 
{
 
  REQUIRE(BMS_ReadfromConsole()== Success); 
}

/*TEST_CASE("To check data is printed on the console") 
{
  REQUIRE(BMS_WriteToConsole(UserRequest)== Success);
  
}*/
