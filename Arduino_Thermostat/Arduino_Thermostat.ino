#include <OneWire.h>
#include <DallasTemperature.h>
#define ONE_WIRE_BUS 8


// Setup a oneWire instance to communicate
OneWire oneWire(ONE_WIRE_BUS);
DallasTemperature sensors(&oneWire);


#include <LiquidCrystal.h> 
LiquidCrystal lcd(12,11,5,4,3,2);

void setup()
{  
   lcd.begin(16, 2);
   lcd.clear();
   lcd.print("  Temperature");   
}

void loop()
{
  
  float degreesC, degreesF;
  sensors.requestTemperatures();
  
  degreesC = sensors.getTempCByIndex(0);
  degreesF = degreesC * (9.0/5.0) + 32.0;
     
  lcd.setCursor(0,1);
   
  lcd.print(degreesF);
  lcd.print("F    ");
  lcd.print(degreesC);
  lcd.print("C");
  delay(2000);       
}

