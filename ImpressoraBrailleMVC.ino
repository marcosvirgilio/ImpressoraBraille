// Controle CNC Shield IMpressora 3D
#include <Servo.h>


// Definição dos pinos 
#define stepPinX 2 //Passo eixo X
#define stepPinY 3 //Passo eixo y
#define dirPinX 5 // Direção eixo X
#define dirPinY 6 // Direção eixo y
#define servoPin 22

Servo servo;
 
 void setup() {
 // Definindo os pinos acima como saída
 pinMode(stepPinX,OUTPUT); 
 pinMode(stepPinY,OUTPUT); 
 pinMode(dirPinX,OUTPUT);
 pinMode(dirPinY,OUTPUT);

 servo.attach(servoPin);  //precisa atrelar o servo a porta 9


 }

void moverY(int passos, char sentido){
  if (sentido == 'd' || sentido == 'D'){
   //define o sentido de rotação X
    digitalWrite(dirPinX,HIGH);
    //define o sentido de rotação Y
    digitalWrite(dirPinY,HIGH);
  } else {   
     //define o sentido de rotação X
    digitalWrite(dirPinX,LOW);
    //define o sentido de rotação Y
    digitalWrite(dirPinY,LOW);
  }
  // Conta 1600 pulsos para que o motor gire
  for(int x = 0; x < passos; x++) {
    digitalWrite(stepPinX,HIGH);
    digitalWrite(stepPinY,HIGH); 
    delayMicroseconds(500); 
    digitalWrite(stepPinX,LOW); 
    digitalWrite(stepPinY,LOW); 
    delayMicroseconds(500); 
  }
}

void moverX(int passos, char sentido){
  if (sentido == 'c' || sentido == 'C'){
    //define o sentido de rotação X
    digitalWrite(dirPinX,HIGH);
    //define o sentido de rotação Y
    digitalWrite(dirPinY,LOW);
  } else {
    //define o sentido de rotação X
    digitalWrite(dirPinX,LOW);
    //define o sentido de rotação Y
    digitalWrite(dirPinY,HIGH);
  }
  // Conta 1600 pulsos para que o motor gire
  for(int x = 0; x < passos; x++) {
    digitalWrite(stepPinX,HIGH);
    digitalWrite(stepPinY,HIGH); 
    delayMicroseconds(500); 
    digitalWrite(stepPinX,LOW); 
    digitalWrite(stepPinY,LOW); 
    delayMicroseconds(500); 
  }
}

 void loop() {
  
  moverY(2600,'d');
  moverY(2600,'e');
  //ferramenta
  servo.write(0);
  delay(1000);
  servo.write(65);
  //pula linha
  moverX(300,'b');
  //Aguarda 1 segundo e reinicia o loop
  delay(1000);
  
}