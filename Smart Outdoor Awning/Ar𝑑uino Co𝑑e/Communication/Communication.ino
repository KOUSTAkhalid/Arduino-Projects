#include <LiquidCrystal_I2C.h>

// LC
LiquidCrystal_I2C lcd(0x3F,16,2); 

int Ldr_pin = A0;

boolean complete = false;
int sizef;
String value1 = "";
String valuetowrite = "";
String commandstring = "";
String v = "";
int valeur;

void setup()
{
  Serial.begin(9600);

  lcd.init(); //initialize the lcd
  lcd.backlight(); //open the backlight 
  lcd.setCursor(0,0);
  lcd.print(" CREATIVE AND");
  lcd.setCursor(0,1);
  lcd.print("  INNOVATION ");

}

void loop()
{
  READ();
  if (complete)
  {
    complete = false;
    sizef = value1.length();
    CMD();
    
    WRITE();
    LOAD();
    
    if (commandstring == "M" ){
      
    }else{
      Automatique();
    }
     
    
   value1 = "";
   commandstring = "";
  }
}

void READ()
{
        while (Serial.available())
  {
    char a = (char)Serial.read();
     value1 += a;
     if ( a == 'n')
     {
      complete = true;
     }
  }
  
}

void Automatique(){
  
}

void WRITE()
{
    if (sizef == 6)
  {
   v = value1.substring(2,5);
  }else if (sizef == 5)
  {
      v = value1.substring(2,4);
  }else if (sizef == 4)
  {
      v = value1.substring(2,3);
  }
}

void CMD()
{
  commandstring = value1.substring(1,2);
}
void LOAD()
{
    valeur = v.toInt();
 
 if ( valeur > 100)
 {
  valeur = 100;
 }
}
