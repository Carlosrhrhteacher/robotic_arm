#include <Servo.h>

// JOYSTICK 1
// Declaramos pines y variables para el Joystick 1
const int pinJoyX = A0; // Pin analógico para el eje X del Joystick 1
const int pinJoyY = A1; // Pin analógico para el eje Y del Joystick 1
int ValorX; // Variable para almacenar el valor del eje X del Joystick 1
int ValorXs; // Variable sin usar en el código actual
int ValorY; // Variable para almacenar el valor del eje Y del Joystick 1
int ValorYs; // Variable sin usar en el código actual

// Servos controlados por el Joystick 1
Servo servoBase; // Servo para la base del brazo robótico
Servo servoHombro; // Servo para el hombro del brazo robótico
int GradoServoBase; // Grados del servo de la base
int GradoServoHombro; // Grados del servo del hombro

// JOYSTICK 2
// Declaramos pines y variables para el Joystick 2
const int pinJoyX2 = A3; // Pin analógico para el eje X del Joystick 2
const int pinJoyY2 = A2; // Pin analógico para el eje Y del Joystick 2
int ValorX2; // Variable para almacenar el valor del eje X del Joystick 2
int ValorXs2; // Variable sin usar en el código actual
int ValorY2;// Variable para almacenar el valor del eje Y del Joystick 2
int ValorYs2; // Variable sin usar en el código actual

// Servos controlados por el Joystick 2
Servo servoCodo; // Servo para el codo del brazo robótico
Servo servoMuneca; // Servo para la muñeca del brazo robótico
Servo servoGiro; //-
int GradoServoCodo; // Grados del servo del codo
int GradoServoMuneca; // Grados del servo de la muñeca
int GradoServoGiro; // Grados del servo que gira

// Variables para la función mover_servo
unsigned long tiempo = millis(); // Tiempo actual en milisegundos
boolean reinicio = false; // Variable sin usar en el código actual
int pausa = 30; // Variable sin usar en el código actual

void setup() {
  // Inicialización de los servos y posiciones iniciales
  servoBase.attach(2); // Asigna el servo de la base al pin 2
  servoBase.write(90); // Posición inicial del servo de la base

  servoHombro.attach(3); // Asigna el servo del hombro al pin 3
  servoHombro.write(0); // Posición inicial del servo del hombro

  servoCodo.attach(4); // Asigna el servo del codo al pin 4
  servoCodo.write(90); // Posición inicial del servo del codo

  servoMuneca.attach(5); // Asigna el servo de la muñeca al pin 5
  servoMuneca.write(90); // Posición inicial del servo de la muñeca

    servoGiro.attach(6); // Asigna el servo de la muñeca al pin 5
  servoGiro.write(90); // Posición inicial del servo de la muñeca

  delay(300); // Espera 300 milisegundos
}

void loop() {
  // Control de los servos con los joysticks
  GradoServoBase = mover_servo(servoBase, GradoServoBase, ValorY, pinJoyY);
  GradoServoHombro = mover_servo(servoHombro, GradoServoHombro, ValorX, pinJoyX);
  GradoServoCodo = mover_servo(servoCodo, GradoServoCodo, ValorY2, pinJoyY2);
  GradoServoMuneca = mover_servo(servoMuneca, GradoServoMuneca, ValorX2, pinJoyX2);
  GradoServoGiro = mover_servo(servoGiro, GradoServoGiro, ValorY2, pinJoyY2);
}

// Función para mover un servo según el joystick
int mover_servo(Servo nombre_servo, int grado_servo, int potenciometro, int entradaAnalogica) {
  potenciometro = analogRead(entradaAnalogica); // Lee el valor del joystick

  if (millis() - tiempo >= 5) { // Controla la velocidad de movimiento
    tiempo += 5;

    if (analogRead(entradaAnalogica) > 520 && grado_servo < 180) {
      grado_servo++; // Incrementa los grados del servo
      nombre_servo.write(grado_servo); // Mueve el servo
    } else if (analogRead(entradaAnalogica) < 480 && grado_servo > 0) {
      grado_servo--; // Decrementa los grados del servo
      nombre_servo.write(grado_servo); // Mueve el servo
      reinicio = true; // Variable sin usar en el código actual
    }
  }

  return grado_servo; // Devuelve los grados del servo
}
