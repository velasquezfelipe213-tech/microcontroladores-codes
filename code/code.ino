int bit1 = 18;
int bit2 = 19;
int bit3 = 21;
int bit4 = 22;
int codigo;
int led1 = 2;
int led2 = 4;
int led3 = 16;
int led4 = 17;
int pot1 = 15;
int dt = 200;
int dt2 = 1000;
int caso;

void setup(){
  pinMode(bit1,INPUT);
  pinMode(bit2,INPUT);
  pinMode(bit3,INPUT);
  pinMode(bit4,INPUT);
  Serial.begin(115200);
  pinMode(pot1,INPUT);
  pinMode(led1,OUTPUT);
  pinMode(led2,OUTPUT);
  pinMode(led3,OUTPUT);
  pinMode(led4,OUTPUT);
}

void loop(){
  int cod1 = digitalRead(bit1);
  int cod2 = digitalRead(bit2);
  int cod3 = digitalRead(bit3);
  int cod4 = digitalRead(bit4);
  codigo = (cod1*1)+(cod2*2)+(cod3*4)+(cod4*8);
  int val1 = analogRead(pot1);
  int val2 = map(val1,65,4095,0,100);
  
  if(val2 > 30 && codigo <= 7){
    caso = 1;
  }
  else if(val2 > 30 && codigo > 7){
    caso = 2;
  }
  else if(val2 <= 30 && codigo <= 7){
    caso = 3;
  }
  else{
    caso = 4;
  }
  
  switch(caso){
    case 1:
    digitalWrite(led1,1);
    digitalWrite(led2,1);
    digitalWrite(led3,0);
    digitalWrite(led4,0);break;
    
    case 2:
    digitalWrite(led1,0);
    digitalWrite(led2,0);
    digitalWrite(led3,1);
    digitalWrite(led4,1);break;
    
    case 3:
    digitalWrite(led1,1);
    digitalWrite(led2,1);
    digitalWrite(led3,1);
    digitalWrite(led4,1);
    delay(dt2);
    digitalWrite(led1,0);
    digitalWrite(led2,0);
    digitalWrite(led3,0);
    digitalWrite(led4,0);
    delay(dt2);break;
    
    case 4:
    digitalWrite(led1,1);
    digitalWrite(led2,0);
    digitalWrite(led3,0);
    digitalWrite(led4,0);
    delay(dt2);
    digitalWrite(led1,0);
    digitalWrite(led2,1);
    digitalWrite(led3,0);
    digitalWrite(led4,0);
    delay(dt2);
    digitalWrite(led1,0);
    digitalWrite(led2,0);
    digitalWrite(led3,1);
    digitalWrite(led4,0);
    delay(dt2);
    digitalWrite(led1,0);
    digitalWrite(led2,0);
    digitalWrite(led3,0);
    digitalWrite(led4,1);
    delay(dt2);break;
  }
  
  Serial.print(codigo);
  Serial.print(" ");
  Serial.println(val2);
  delay(dt);
}