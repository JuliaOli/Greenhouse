#define AMOSTRAS 10

int LDR = 0; //Define a variável LDR como 0.
int ldr_val = 0; //Define a variável ldr_val iniciado em 0
float ldr_tensao = 0;
float aRef = 5;
float lux = 0;

//coefiecients

float p1 = 46.764;
float p2 = -468.54;
float p3 = 1794.4;
float p4 = -3144.1;
float p5 = 2633.3;
float p6 = -792.64;


void setup(){
  Serial.begin(9600); //Velocidade da porta serial
}

float amostras() {
  float total=0;  
  for (int i=0; i<AMOSTRAS; i++) {
    total += 1.0 * analogRead(LDR);
    delay(5);
  }
  return total / (float)AMOSTRAS;
}

float ldrToLux(float ldr_tension){
    return p1*pow(ldr_tension,5) + p2*pow(ldr_tension,4) + p3*pow(ldr_tension,3) + p4*pow(ldr_tension,2) + p5*ldr_tension + p6;
}
 
void loop(){
 
 //ldr_val = analogRead(LDR);      
 
 ldr_val = amostras();
 ldr_tensao = (ldr_val * aRef) / 1023.0;
 lux = ldrToLux(ldr_tensao);
 
 
 //Serial.println(ldr_val); //Manda o valor lido para a porta serial
 Serial.println(ldr_tensao); 
 Serial.println(lux); 
 
 
 /*if (ldr_val<512)
 {
   Serial.println(": Escuro"); //Escreva no serial Monitor
 }
  else if(ldr_val > 700)
  {
    Serial.println(": Claro ");
  }*/
 
  delay(2000); //Aguarda meio segundo
 
}
