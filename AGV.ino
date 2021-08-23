#include <AFMotor.h>
#include <SoftwareSerial.h>
#include <ArduinoBlue.h>

AF_DCMotor motorE(1, MOTOR12_64KHZ); ///  motorE
AF_DCMotor motorD(2, MOTOR12_64KHZ); ///  motorDireita

//// COMANDO QUE DEFINE AS PORTAS NO ARDUINO, NOME DAS PORTAS

/*
  #define TX  19
  #define RX  18
*/
SoftwareSerial bluetooth(19,18);

//// DEFINE DO INFRAVERMELHO, QUE DETECTA A PESA

#define infravermelho 43

//// DEFINE DOS SEGUIDORES DE LINHA NPN

#define esquerda 37
#define centro 30
#define direita 35



//// variaveis

int input_infra = 1, indo;
char receptor;

void setup() {

  // put your setup code here, to run once:
  Serial.begin(38400);
  bluetooth.begin(38400);
  motorE.setSpeed(100);
  motorD.setSpeed(100);

}

void loop() {


  receptor = bluetooth.read();
  //Serial.println(digitalRead(infravermelho));
  Serial.println(receptor);
  
  while ( receptor == '1') {

    
    input_infra = digitalRead(infravermelho);
    Serial.println("bluetooth on");
    if (input_infra == 0) {

      indo = 1;

    }
    while (indo == 1) {
      motorE.run(FORWARD);
      motorD.run(FORWARD);

      delay(10000);
      indo=0;
      
    }
 
   
  }

}
