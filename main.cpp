// Definificones y declaraciones globales.
#include "mbed.h"
#include "arm_book_lib.h"

int main()
{
//Declaraciones e inicializaciones.
   //Defino entrada digital, posteriormente su PullDown.
   DigitalIn gasDetector(D2);
   DigitalIn overTempDetector(D3);
   
   //Salida digital.
   DigitalOut alarmLed(LED1);
   
   gasDetector.mode(PullDown);   
   overTempDetector.mode(PullDown);

   //SuperLoop.
   while (true) {
      // Si se detecta gas o se detecta sobre temperatura -> enciente la alarlma
      // sino -> alarma apagada.
      //if (gasDetector  or overTempDetector)
      if ( gasDetector || overTempDetector ) {
         alarmLed = ON;
      } else {
         alarmLed = OFF;
      }
      
   }
}