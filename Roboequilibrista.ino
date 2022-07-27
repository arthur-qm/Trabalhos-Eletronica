#include <Wire.h>
#include <MPU6050_tockn.h>
#define ma1 5
#define ma2 3
#define mb1 6
#define mb2 9
/*Nota: as portas 5 e 3 estão invertidas, 
porém na programação o método Set é utilizado já 
considerando isso*/
#define MPU6050_ADDR

MPU6050 mpu6050(Wire);

float angulo;
float normal = 0;
const float k = 0.055;
float vel;
void setup() {
  pinMode(ma1,OUTPUT);
  pinMode(ma2,OUTPUT);
  pinMode(mb1,OUTPUT);
  pinMode(mb2,OUTPUT);
  Serial.begin(9600);
  Serial.println("bomdia");
  Wire.begin();
  Set(0,0,0,0,0);
  mpu6050.begin();
  mpu6050.calcGyroOffsets(false);// MUDAR PARA "true" SE QUISER VISUALIZAR INFORMAÇÕES DE CALIBRAÇÃO NO MONITOR SERIAL
  for(int c=0;c<10;c++){
    mpu6050.update();
    normal = mpu6050.getAngleY();delay(10);
  }
}

void Set(int a1,int a2,int b1, int b2,float vel){
  Serial.print("vel: ");
  Serial.println(vel*255);
  analogWrite(ma1,a1*vel*255);
  analogWrite(ma2,a2*vel*255);
  analogWrite(mb1,b1*vel*255);
  analogWrite(mb2,b2*vel*255);
}


void loop() {
  mpu6050.update();
  angulo = mpu6050.getAngleY();
  vel = abs(angulo-normal)*(k);
  if(vel>1){vel=1;}//Limita o valor para um máximo de 1
  if(vel<0){vel=0;}//Limita o valor para um mínimo de 0
  if(angulo-normal<0){
    Set(0,1,0,1,vel);//Gira para o lado 1
    Serial.println("--Lado2");
  }else{
    Set(1,0,1,0,vel);//Gira para o lado 2
    Serial.println("--Lado1");
  }
}
