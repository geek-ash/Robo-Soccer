const int ch1=A0;
const int ch2=A1;//ch2 of lcd transmitter not working
const int ch6=A3; //ch6 acts as a switch controlled by Vnb
const int ch4=A2;
const int EN_R1=9;
const int EN_L1=6;
const int EN_R2=11;//used in uno
const int EN_L2=3;//used in uno

int l1=7;//used in uno
int l2=5;//used in uno
int r1=12;//used in uno
int r2=13   ;//used in uno
int rw1 =10;
int rw2 =8;
int lw1 =4;
int lw2=2;
int rspeed,lspeed;
int deadzone=20;


void setup(){
 
  Serial.begin(9600);
  pinMode(ch1,INPUT);
  pinMode(ch2,INPUT);
  pinMode(ch6,INPUT);
  pinMode(ch4,INPUT);
  pinMode(r1,OUTPUT);
  pinMode(r2,OUTPUT);
  pinMode(l1,OUTPUT);
  pinMode(l2,OUTPUT);
   pinMode(rw1,OUTPUT);
  pinMode(rw2,OUTPUT);
  pinMode(lw1,OUTPUT);
  pinMode(lw2,OUTPUT);
  pinMode(EN_R1,OUTPUT);
  pinMode(EN_L1,OUTPUT);
  pinMode(EN_R2,OUTPUT);
  pinMode(EN_L2,OUTPUT);

}


int pulse_motor(int a){
   int val=pulseIn(a,HIGH,25000);
   if(val>1000)
          {
           val=map(val,1200,1875,-500,500);//gives optimum value
           val=constrain(val,-255,255);
             }
   else val=0;
   if(abs(val)<=deadzone) val=0;
   return val;
 }
  
void loop()
{
  
  if(pulseIn(ch6,HIGH,25000)>1500)
  {
  rspeed=pulse_motor(ch2);
  lspeed=pulse_motor(ch1);
  
 if (rspeed==0)
 {
  digitalWrite(r1,LOW);
  digitalWrite(r2,LOW);
   digitalWrite(rw1,LOW);
  digitalWrite(rw2,LOW);
  Serial.println("RS");
 }

 if (rspeed>0)
 {
  analogWrite(EN_R1,rspeed);
  analogWrite(EN_R2,rspeed);
  digitalWrite(r1,HIGH);
  digitalWrite(r2,LOW);
  digitalWrite(rw1,LOW);
  digitalWrite(rw2,HIGH);
  Serial.println("RF");
 }

 if (rspeed<0)
 {
  analogWrite(EN_R1,abs(rspeed));
  analogWrite(EN_R2,abs(rspeed));
  digitalWrite(r1,LOW);
  digitalWrite(r2,HIGH);
  digitalWrite(rw1,HIGH);
  digitalWrite(rw2,LOW);
  Serial.println("RB");
}
//for left side
if (lspeed==0)
 {
  
  digitalWrite(l1,LOW);
  digitalWrite(l2,LOW);
   digitalWrite(lw1,LOW);
  digitalWrite(lw2,LOW);
  Serial.println("LS");
  
 }

 if (lspeed>0)
 {
  analogWrite(EN_L1,lspeed);
  analogWrite(EN_L2,lspeed);
  digitalWrite(l1,HIGH);
  digitalWrite(l2,LOW);
   digitalWrite(lw1,LOW);
  digitalWrite(lw2,HIGH);
  Serial.println("LF");
 }

 if (lspeed<0)
 {
  analogWrite(EN_L1,abs(lspeed));
  analogWrite(EN_L2,abs(lspeed));
  digitalWrite(l1,LOW);
  digitalWrite(l2,HIGH);
   digitalWrite(lw1,HIGH);
  digitalWrite(lw2,LOW);
  Serial.println("LB");
}
  }

else
{
  

  lspeed=pulse_motor(ch2);
  rspeed=pulse_motor(ch4);//ch 3 not working

if (rspeed==0)
 {
  digitalWrite(r1,LOW);
  digitalWrite(r2,LOW);
   digitalWrite(rw1,LOW);
  digitalWrite(rw2,LOW);
  Serial.println("RS");
 }

 if (rspeed>0)
 {
  analogWrite(EN_R1,rspeed);
  analogWrite(EN_R2,rspeed);
  digitalWrite(r1,HIGH);
  digitalWrite(r2,LOW);
  digitalWrite(rw1,HIGH);
  digitalWrite(rw2,LOW);
  Serial.println("RF");
 }

 if (rspeed<0)
 {
  analogWrite(EN_R1,abs(rspeed));
  analogWrite(EN_R2,abs(rspeed));
  digitalWrite(r1,LOW);
  digitalWrite(r2,HIGH);
  digitalWrite(rw1,LOW);
  digitalWrite(rw2,HIGH);
  Serial.println("RB");
}
//for left side
if (lspeed==0)
 {
  
  digitalWrite(l1,LOW);
  digitalWrite(l2,LOW);
   digitalWrite(lw1,LOW);
  digitalWrite(lw2,LOW);
  Serial.println("LS");
  
 }

 if (lspeed>0)
 {
  analogWrite(EN_L1,lspeed);
  analogWrite(EN_L2,lspeed);
  digitalWrite(l1,HIGH);
  digitalWrite(l2,LOW);
   digitalWrite(lw1,HIGH);
  digitalWrite(lw2,LOW);
  Serial.println("LF");
 }

 if (lspeed<0)
 {
  analogWrite(EN_L1,abs(lspeed));
  analogWrite(EN_L2,abs(lspeed));
  digitalWrite(l1,LOW);
  digitalWrite(l2,HIGH);
   digitalWrite(lw1,LOW);
  digitalWrite(lw2,HIGH);
  Serial.println("LB");
}
  }
  

  }



 

 
 
