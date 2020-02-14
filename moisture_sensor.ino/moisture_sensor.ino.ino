#include <LiquidCrystal.h>
#include <Wire.h>


//const int AirValue = 620;   //you need to replace this value with Value_1
//const int WaterValue = 310;  //you need to replace this value with Value_2

const int moistureSensor = 14; // Moisture sensor pin A0
const int waterPump = 3; // Moisture sensor pin 3 (pwm)

int aux = 0;
double counter = 0;
double pulse; //variável para guardar a duração do pulso

// Soil Moisture variables
int soilMoistureValue = 0;
int soilMoisturePercent = 0;
double soilMoisturePulse = 0;


void setup() {
  Serial.begin(9600); // open serial port, set the baud rate to 9600 bps
  
  // Pin Modes
  pinMode(waterPump, INPUT);
  pinMode(moistureSensor, INPUT);
}

double getPulseDuration(int pin){
  pulse = pulseIn(pin, LOW);
  counter = counter + pulse;
  aux++;
  if(aux>1000){
    Serial.print("media ");
    double arduinoRef =  1000/( (counter/1000));
    Serial.println(0.85*arduinoRef-2.55);  
    aux = 0;
    counter =0;
    delay(1000);
  }
}

void loop() {

getPulseDuration(moistureSensor);


//soilmoisturePercent = map(soilMoistureValue, AirValue, WaterValue, 0, 100);

/*if(soilmoisturepercent > 100)
{
  //Serial.println("100 %");
}
else if(soilmoisturepercent <0)
{
  //Serial.println("0 %");
}
else if(soilmoisturepercent >0 && soilmoisturepercent < 100)
{
  //Serial.print(soilmoisturepercent);
  //Serial.println("%");
  
}*/
}
