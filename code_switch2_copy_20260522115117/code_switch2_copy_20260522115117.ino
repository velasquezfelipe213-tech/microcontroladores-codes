int bit1 = 21;
int bit2 = 22;
int codigo;
int led1 = 2;
int led2 = 4;
int led3 = 16;
int led4 = 17;
int pot1 = 15;
int dt1 = 200;

void setup(){
  pinMode(bit1,INPUT);
  pinMode(bit2,INPUT);
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
  codigo = (cod1*1)+(cod2*2);
  int val1 = analogRead(pot1);
  int val2 = map(val1,65,4095,0,100);
  
  switch(codigo){
    case 0:
    digitalWrite(led1,0);
    digitalWrite(led2,0);
    digitalWrite(led3,0);
    digitalWrite(led4,0);break;
    
    case 1:
    digitalWrite(led1,1);
    digitalWrite(led2,1);
    digitalWrite(led3,1);
    digitalWrite(led4,1);
    delay(val2*2);
    digitalWrite(led1,0);
    digitalWrite(led2,0);
    digitalWrite(led3,0);
    digitalWrite(led4,0);
    delay(val2*2);break;
    
    case 2:
    digitalWrite(led1,1);
    digitalWrite(led2,0);
    digitalWrite(led3,0);
    digitalWrite(led4,0);
    delay(dt1);
    digitalWrite(led1,0);
    digitalWrite(led2,1);
    digitalWrite(led3,0);
    digitalWrite(led4,0);
    delay(dt1);
    digitalWrite(led1,0);
    digitalWrite(led2,0);
    digitalWrite(led3,1);
    digitalWrite(led4,0);
    delay(dt1);
    digitalWrite(led1,0);
    digitalWrite(led2,0);
    digitalWrite(led3,0);
    digitalWrite(led4,1);
    delay(dt1);break;
    
    case 3:
    digitalWrite(led1,1);
    digitalWrite(led2,0);
    digitalWrite(led3,0);
    digitalWrite(led4,0);
    delay(val2*2);
    digitalWrite(led1,0);
    digitalWrite(led2,1);
    digitalWrite(led3,0);
    digitalWrite(led4,0);
    delay(val2*2);
    digitalWrite(led1,0);
    digitalWrite(led2,0);
    digitalWrite(led3,1);
    digitalWrite(led4,0);
    delay(val2*2);
    digitalWrite(led1,0);
    digitalWrite(led2,0);
    digitalWrite(led3,0);
    digitalWrite(led4,1);
    delay(val2*2);break;
  }
  
  Serial.print(codigo);
  Serial.print(" ");
  Serial.println(val2);
  delay(dt1);
}