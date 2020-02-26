// Microcontroler and Eletronic Instrumentation Project 
// GreenHouse

//Lybraries
#include <LiquidCrystal.h>
#include <Wire.h>

// Constants
#define AMOSTRAS 10
#define LED 9 //Defines LED pin as 9
#define LDR A0 //Defines LDR sensor pin as A0
#define moistureSensor A1 //Defines Moisture sensor pin as A1
#define waterPump 10 // Defines waterpump pwm port as 3

//Pin used by LCD display
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

// Moisture sensor variables
int aux = 0;
double counter = 0;
double pulse; // Pulse duration variable
double soilMoistureValue = 0;
int soilMoisturePercent = 0;
double soilMoisturePulse = 0;

//LDR variables
int ldrValue = 0;
int luxPercent = 0;
double ldrTension = 0;
double lux = 0;
double aRef = 5;


// Calibration coeficients
// LDR
float p1 = 204.93;
float p2 = 1.4485;

// Moisture Sensor
float p1M = 0.013453;
float p2M = -0.31662;
float p3M = 2.7506;
float p4M = -10.771;
float p5M = 16.373;

void setup(){

  //Defines the number of rows and colluns of LCD
  lcd.begin(16, 2);
  
  //Pin mode
    // LDR
    pinMode(LDR, INPUT);
    pinMode(LED, OUTPUT);
    //Moisture sensor
    pinMode(waterPump, OUTPUT);
    pinMode(moistureSensor, INPUT);

  //Serial Port Velocity
    Serial.begin(9600);
}

// Sample function for LDR sensor
float samples(int ldrPin) {
  float total=0;  
  for (int i=0; i<AMOSTRAS; i++) {
    total += 1.0 * analogRead(ldrPin);
    delay(5);
  }
  return total / (float)AMOSTRAS;
}

// LDR sensor calibration function
double ldrToLux(float ldr_tension){
    double ldrLux = p1*ldr_tension + p2;
    return abs(ldrLux);
}

// Moisture sensor calibration function 
double soilMoisture(float pulse){
    double sensor = p1M*pow(pulse,4) + p2M*pow(pulse,3) + p3M*pow(pulse,2) + p4M*pulse + p5M;
    return sensor;
}

// Get the pulse by time from the moisture sensor
double getPulseDuration(int pin){
  pulse = pulseIn(pin, LOW);
  counter = counter + pulse;
  aux++;
  if(aux>1000){
    //Serial.print("media ");
    double arduinoRef =  1000/( (counter/1000));
    //Serial.println(0.85*arduinoRef-2.55);  
    aux = 0;
    counter =0;
    delay(1000);
    return 0.85*arduinoRef-2.55;
  }
}

void loop(){

<<<<<<< HEAD
  /******************************* LUMINOSIDADE **************************************************/
 /*
=======
  /********************************************************* LUX ********************************************************************/
 
>>>>>>> 444f92c5e157c1da784fe4dd3b1f872ccfd810a1
  // Obtaining data from LDR sensor
 ldrValue = samples(LDR);
 ldrTension = (ldrValue * aRef) / 1023.0;
 lux = ldrToLux(ldrTension); //Convert to lux
 
 // Clear the screen
  lcd.clear();
  //Cursor position
  lcd.setCursor(0, 0);
  // LCD TEXT
  lcd.print("LUMINOSIDADE");
  lcd.setCursor(0, 1);
  lcd.print(lux);
  
 // LED power control
 if (lux > 1000)
 {
    Serial.println(lux); 
    analogWrite(LED, 64); // Ciclo ativo de 25%
  }
  else if(lux <= 1000 && lux >= 700)
  {
    Serial.println(": Claro ");
    analogWrite(LED, 127); // Ciclo ativo de 50%
  }
   else if (lux < 700 && lux >= 400)
 {
    Serial.println(lux); 
    analogWrite(LED, 191); // Ciclo ativo de 100%
  }
  else
  {
    Serial.println(": Claro ");
    analogWrite(LED, 255); // Ciclo ativo de 100%
  }
  delay(2000);
*/

 /************************************************** MOISTURE SENSOR + WATER PUMP ****************************************************/


  soilMoistureValue = getPulseDuration(moistureSensor);
  //soilMoisturePulse = soilMoisture(soilMoistureValue);

<<<<<<< HEAD
  if(soilMoistureValue > 3){
=======
  // Activate the water pump if the humidity is lower than certain value given by the sensor
  if(soilMoistureValue >= 0.9){
>>>>>>> 444f92c5e157c1da784fe4dd3b1f872ccfd810a1
    analogWrite(waterPump, 255);
    delay(3000);
    analogWrite(waterPump, 0);
  }
  else{
    analogWrite(waterPump, 0);
  }
<<<<<<< HEAD
  soilMoisturePercent = map(soilMoistureValue,-0.96, 7, 0, 100);
=======

  // Maps the values into percentage
  soilMoisturePercent = map(soilMoistureValue,-0.56, 1.9, 0, 100);
>>>>>>> 444f92c5e157c1da784fe4dd3b1f872ccfd810a1

  lcd.clear();
  //Posiciona o cursor na coluna 3, linha 0;
  lcd.setCursor(0, 0);
  //Envia o texto entre aspas para o LCD
  lcd.print("HUMIDADE");
  lcd.setCursor(0, 1);
  lcd.print(soilMoisturePercent);
  
  //delay(2000);
}
