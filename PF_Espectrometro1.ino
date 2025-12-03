#include "SparkFun_AS7265X.h"

AS7265X sensor; //Se instancia el objeto sensor de la clase AS7265x

void setup() 
{
  Serial.begin(115200);
  
  // Iniciar la comunicación I^2C con el sensor
  if (sensor.begin() == false) {
    Serial.println("El sensor no responde. Revisar conexiones.");
    while (1); // Ciclo infinito si hay falla.
  }

  //Se apagan los LEDs del sensor para evitar contaminación en las lecturas
  sensor.disableIndicator(); // Apaga el de estado-->Ya cubierto con pintura en el sensor físico.
  sensor.disableBulb(AS7265x_LED_WHITE);
  sensor.disableBulb(AS7265x_LED_IR);
  sensor.disableBulb(AS7265x_LED_UV);
  
  Serial.println("Espectrometro conectado. Abrir el Serial Plotter.");
}

void loop() 
{
  // Toma de medición de los 18 canales espectrales discretos
  sensor.takeMeasurements(); 

  // Imprimimos de valores en Serial Plotter
  // Orden dado por longitud de onda ascendente
  
  Serial.print(sensor.getCalibratedA()); Serial.print(","); // 410nm
  Serial.print(sensor.getCalibratedB()); Serial.print(","); // 435nm
  Serial.print(sensor.getCalibratedC()); Serial.print(","); // 460nm
  Serial.print(sensor.getCalibratedD()); Serial.print(","); // 485nm
  Serial.print(sensor.getCalibratedE()); Serial.print(","); // 510nm
  Serial.print(sensor.getCalibratedF()); Serial.print(","); // 535nm
  Serial.print(sensor.getCalibratedG()); Serial.print(","); // 560nm
  Serial.print(sensor.getCalibratedH()); Serial.print(","); // 585nm
  Serial.print(sensor.getCalibratedR()); Serial.print(","); // 610nm
  Serial.print(sensor.getCalibratedI()); Serial.print(","); // 645nm
  Serial.print(sensor.getCalibratedS()); Serial.print(","); // 680nm
  Serial.print(sensor.getCalibratedJ()); Serial.print(","); // 705nm
  Serial.print(sensor.getCalibratedT()); Serial.print(","); // 730nm
  Serial.print(sensor.getCalibratedU()); Serial.print(","); // 760nm
  Serial.print(sensor.getCalibratedV()); Serial.print(","); // 810nm
  Serial.print(sensor.getCalibratedW()); Serial.print(","); // 860nm
  Serial.print(sensor.getCalibratedK()); Serial.print(","); // 900nm
  Serial.println(sensor.getCalibratedL());                  // 940nm 
}
