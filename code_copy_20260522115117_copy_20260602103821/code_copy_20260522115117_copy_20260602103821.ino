int in1 = 5;
int in2 = 13;
int in3 = 12;
int out2 = 2;
int out3 = 4;
int out4 = 16;
int bot = 17;
int bot1;
int bot2;

void setup(){
  pinMode(in1,INPUT);
  pinMode(in2,INPUT);
  pinMode(in3,INPUT);
  pinMode(out2,OUTPUT);
  pinMode(out3,OUTPUT);
  pinMode(out4,OUTPUT);
  pinMode(bot1,INPUT);
}

void loop() {

  bot1 = digitalRead(bot);
  bot2 = !bot1;
  
  int q0 = digitalRead(in1);
  int q0N = !q0;
  
  int A = q0;
  int B = bot1;
  int AB = (A && B);
  
  int C = q0N;
  int D = bot2;
  int CD = (C && D);
  
  int E = (AB || CD);
  digitalWrite(out2,E);
  
  ////////////
  
  int q1 = digitalRead(in2);
  int q1N = !q1;
  
  int F = q1;
  int G = AB;
  int FG = (F && G);
  
  int H = q1N;
  int I = CD;
  int HI = (H && I);
  
  int J = (FG || HI);
  digitalWrite(out3,J);
  
  ////////////
  
  int q2 = digitalRead(in3);
  int q2N = !q2;
  
  int K = q2;
  int L = FG;
  int KL = (K && L);
  
  int M = q2N;
  int N = HI;
  int MN = (M && N);
  
  int O = (KL || MN);
  digitalWrite(out4,O);
}