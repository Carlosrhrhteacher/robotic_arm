                                                                                                                                                             // Icluimos librería servo.
#include <Servo.h>
 
//JOTSTICK 1
// Deaclaramos valores x e y joystick 1 y variables para x e y joystick 1
const int pinJoyX = A0; //declaramos el eje x del joystick
const int pinJoyY = A1; //declaramos el eje y del joystick
int ValorX;
int ValorXs ;
int ValorY;
int ValorYs ;
//Declaramos los servos qur funcionaran con el joystick 1 
Servo servoBase;
Servo servoHombro;
int GradoServoBase;
int GradoServoHombro;
 
 
//JOYSTICK 2
// Declaramos valores x e y joystick 2 y variables para x e y joystick 2
const int pinJoyX2 = A3; //declaramos el eje x para el joystick 2
const int pinJoyY2 = A2; //declaramos el eje y para el  joystick 2
int ValorX2;
int ValorXs2;
int ValorY2;
int ValorYs2;
//Declaramos los servos que funcionarán con el joystick 2
Servo servoCodo;
Servo servoMuneca;
int GradoServoCodo;
int GradoServoMuneca;
 
 
//declaramos variables necesarias para crear la funcion.
unsigned long tiempo = millis();
boolean reinicio = false;
int pausa = 30;
 
 
void setup() {
  //Declaramos posiciones iniciales Joistick 1
  servoBase.attach(2); // se coloca el servo en el pin 2, será nuestro servo del eje de abcisas
  servoBase.write(90);
  servoHombro.attach(3); // se coloca el servo en el pin 3, será nuestro servo del eje de ordenadas 
  servoHombro.write(0);
  delay(300);
 
  
  //Declaramos posiciones iniciales Joistick 2
  servoCodo.attach(4); // se coloca el servo en el pin 4, será nuestro servo del eje de abcisas
  servoCodo.write(90);
  servoMuneca.attach(5);  // se coloca el servo en el pin 5, será nuestro servo del eje de ordenadas 
  servoMuneca.write(90);
  delay(300);
 
}
 
void loop() {
  //Crearemos una función para el funcionamiento de los servos, de tal forma que solo tendremos que declarar las llamadas de cada servoa la funcion.
  //Llamadas a la funcion de los servos que funcionaran con nuestro Joystick 1
  GradoServoBase = mover_servo(servoBase, GradoServoBase, ValorY, pinJoyY);
  GradoServoHombro = mover_servo(servoHombro, GradoServoHombro, ValorX, pinJoyX);
//Llamadas a la funcion de los servos que funcionaran con nuestro Joystick 2
GradoServoCodo = mover_servo(servoCodo, GradoServoCodo, ValorY2, pinJoyY2);
GradoServoMuneca = mover_servo(servoMuneca, GradoServoMuneca, ValorX2, pinJoyX2);
 
}
 
//Creamos la funcion para el funcionamiento de nuestro servo.
/*En primer lugar declaramos nuestro funcion, la cual tiene que ser tipo int. Esto debe a que sino no nos devuleve datos y sin este tipo
* de funcion y la funcion return que se puede ver al final, nuestro codigo no modifica la variable general por lo que el código no funcionaria. 
* El funcionamienyto basico del codigo es el siguiente:
* Nuestra primera condición if mide el valor de nuestro reloj de arduino para entrar en la funcion. Despues declaramos nuestro tiempo otra vez en 
* el valor inicial para que cuando se reinicie el bucle el codigo funcione.
* La segunda condicion if dice que cuando se cumplan las condiciones de que el joystick este en los valores para mover el servo y siempre y 
* cuando el valor del servo este entre 0 y 180 este suma o reste grados para que el servo se mueva hacia un lado o hacia otro.
*/
int mover_servo(Servo nombre_servo, int  grado_servo, int potenciometro, int entradaAnalogica ) {
  potenciometro  = analogRead(entradaAnalogica);
  if (millis() - tiempo >= 5)
  {
    tiempo += 5;
    if (analogRead(entradaAnalogica) > 520 && grado_servo < 180) {
      grado_servo ++;
      nombre_servo.write(grado_servo);
    }
    else {
      if (analogRead(entradaAnalogica) < 480 && grado_servo > 0) {
        grado_servo --;
        nombre_servo.write(grado_servo);
        reinicio = true;
      }
    }
  }
  return (grado_servo);
}
