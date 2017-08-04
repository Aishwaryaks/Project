#include<SoftwareSerial.h>
SoftwareSerial cell(2,3);
int relaypin=7;
float sen=A0;
float gas;
int pin = A5; // analog pin
int putPin = A3; // humidity
int tempc = 0,tempf=0; // temperature variables
//int samples; // variables to make a better precision
int maxi = -100,mini = 100; // to start max/min temperature
int i;
float humi = 0;  //humidity 
float samples=0;
float prehum = 0;
float humconst = 0;       
float truehum = 0;
float pretruehum = 0; 
long pretruehumconst = 0; 
long valb = 0;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  cell.begin(9600);
  pinMode(relaypin,OUTPUT);
  
}

void loop() {
//   put your main code here, to run repeatedly:
samples = ( 5.0 * analogRead(pin) * 100.0) / 1024.0;
tempc = tempc + samples;
delay(1000);
tempc = tempc/8.0; 
tempf = (tempc * 9)/ 5 + 32;
valb = analogRead(putPin); // reading
prehum = (valb/5);
humconst = (0.16/0.0062);   //humidity constant
humi = prehum - humconst;
pretruehumconst = 0.00216*tempc;
pretruehum = 1.0546-pretruehumconst;
truehum = humi/pretruehum ;
//delay(1000);
gas=analogRead(sen);
Serial.print(tempc,DEC);
Serial.print(" Celsius, ");
Serial.print ("Humidity: ");
Serial.print ((long)truehum);
Serial.println ("% ");
Serial.println("gas:  ");
Serial.println(gas);
tempc = 0;
if(gas>100)
{

 digitalWrite(relaypin,HIGH);
   Serial.println("CALLING......");
   cell.println("ATD+918105091575;");
   delay(10);
   cell.println("ATH");
cell.println("gas high");
 Serial.println("switch on fan");
 
  delay(1000);
 
}
else
{
  Serial.println("switch off fan");
  digitalWrite(relaypin,LOW);
  delay(1000);
}

delay(10); // delay before loop*/
}


/*void sendMessageon()
{
   myserial.println("AT+CMGF=1");
    //delay(1000);
    mySerial.println("AT+CMGS=\"+918105091575\"\r");
    mySerial.println("MOTOR ON"); 
    //delay(100);
    mySerial.println((char)26) ;
    //delay(1000);
            
  
}*/
