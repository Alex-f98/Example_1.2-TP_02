// Definificones y declaraciones globales.
#include "mbed.h"
#include "arm_book_lib.h"

int main()
{
//Declaraciones e inicializaciones.
   //Defino entrada digital, posteriormente su PullDown.
   DigitalIn gasDetector(D2);
   // La clase DigitalIn representa un objeto que permite leer 
   // el estado de un pin digital (alto o bajo).
   /*
   Objeto: gasDetector.
   Mensaje: enumerator D2, enum PinName
   Metodo: read(), mode(PinMode pull), is_connected(), int(){lo mismo que read()}
   Clase: class DigitalIn
   Herencia: No hay herencia explicita en la clase, pero depende del struct gpio para los contructores.
   Lista de inicializadores: https://programmerclick.com/article/43624122554/
    Inicializa :gpio() es un struct que primero se inicializa para luego crear el constructor.
   Luego se llama al contructor de gpi y se hace el mapeo de cada struct de gpio() hacia los puertos de la placa
   HW.
   */

   //Analogo: Se declara el objeto overTempDectector de la clase DigitalIn usando por argumento un PIN D3 = PE_13(un tipo enumerativo).
   DigitalIn overTempDetector(D3);
   
   //Salida digital.
   //Analogo: Se declara el objeto alarmLed de la clase DigitalOut usando por argumento LED1 = PB_0(led verde, un tipo enumerativo).
   DigitalOut alarmLed(LED1);
   
   //Setea en modo PullDown el objeto gasDetector con el metodo mode().
   gasDetector.mode(PullDown);   
   //Setea en modo PullDown el objeto overTempDetector con el metodo mode().
   overTempDetector.mode(PullDown);

   //SuperLoop.
   while (true) {
      // Si se detecta gas o se detecta sobre temperatura -> enciente la alarlma
      // sino -> alarma apagada.
      //if (gasDetector  or overTempDetector)
      if ( gasDetector || overTempDetector ) {
         alarmLed = ON;
         printf("Gas detectado: %s ; alarmLed: %s\n", gasDetector ? "true" : "false", alarmLed ? "true" : "false");

      } else {
         alarmLed = OFF;
         printf("Gas detectado: %s ; alarmLed: %s\n", gasDetector ? "true" : "false", alarmLed ? "true" : "false");

      }
      
   }
}

/*
cinco.
BUILD: contiene el mbed_config.h
mbed-os: es el repositorio de mbed definido en "mbed-os.lib"
.gititnore: define que archivos ignorar cuando haga un push al repo.
.mbed: define variables de entorno entre ellas el target. ej:TARGET=NUCLEO-F429ZI
arm_boo_lib.h: define constantes (ON,OFF..) y un alias delay(ms).
main.cpp: el codigo principal en donde se trabaja.
mbed-os.lib: define el link del repositorio github de embed.
*/

/*
d)
Mbed OS (de Arm) es un sistema operativo embebido open source pensado para los dispositivos basados en Arm Cortex-M
En el estan definidas las librerias para manejo de GPIO, ADC, timer, etc. 
Todas las funciones para manejo de hardware.
*/

/*
7-
Se utiliza printf, por default tiene badurate=9600 y envia a stdout.
Muestra las valores que de encendido o apagado de los sensores.
*/