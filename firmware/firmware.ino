#include <SoftwareSerial.h>

SoftwareSerial mySerial(7, 8);

void initGSM(){
  mySerial.print("ATE0\r");
  delay(100);
  mySerial.print("AT\r");
  delay(100);
  mySerial.print("AT+CMGF=1\r");
  delay(100);
  mySerial.print("AT+CNMI=1,2,0,0,0\r");
  delay(100);
}

void setup() {
  mySerial.begin(19200);               // the GPRS baud rate
  Serial.begin(19200);    // the GPRS baud rate
  delay(2000);
  //initialize GMS for receiving
  initGSM();
  delay(2000);
  Serial.println("Send money start.");
  doSendMoney();
  Serial.println("Send money done.");
}

void loop() {
  if (Serial.available())
   switch(Serial.read())
   {
     case 't':
       Serial.println(F("sending money"));        
       doSendMoney();
       break;      
   }
}

void doSendMoney(){
  mySerial.print("AT+CUSD=1\r");
  delay(500);
// AT+CUSD=1,"*156#"
// +CUSD: 0,"Your number is: 233241943721",64
  mySerial.print("AT+CUSD=1,\"*170#\"\r");
  delay(3000);
//  waitForResponse();
//  ShowSerialData();
//+CUSD: 1,"Main Menu
//1) Transfer Money
//2) Pay Bill
//3) Buy Airtime
//4) My Wallet",64
  mySerial.print("AT+CUSD=1,\"1\"\r");
  delay(3000);
//  waitForResponse();
//  ShowSerialData();
//+CUSD: 1,"Transfer Money
//1) Mobile User
//2) Non Mobile User
//3) Favorite
//Select a number and press send",64
  mySerial.print("AT+CUSD=1,\"1\"\r");
  delay(3000);
//  ShowSerialData();
//  waitForResponse();
//+CUSD: 1,"Mobile User
//1) Subscriber
//2) Merchant
//Select a number and press send",64
  mySerial.print("AT+CUSD=1,\"1\"\r");
  delay(3000);
//  mySerial.print("AT+CUSD=1,\"1\"\r");
//  waitForResponse();
//  ShowSerialData();
//+CUSD: 1,"Enter mobile number",64
  mySerial.print("AT+CUSD=1,\"0245511543\"\r");
  delay(3000);
//  waitForResponse();
//  ShowSerialData();
//+CUSD: 1,"Repeat mobile number",64
  mySerial.print("AT+CUSD=1,\"0245511543\"\r");
  delay(3000);
//  waitForResponse();
//  ShowSerialData();
//+CUSD: 1,"Enter amount",64
  mySerial.print("AT+CUSD=1,\"5\"\r");
  delay(3000);
//  waitForResponse();
//  ShowSerialData();
//+CUSD: 1,"Enter Reference",64
  mySerial.print("AT+CUSD=1,\"1\"\r");
  delay(3000);
//  waitForResponse();
//  ShowSerialData();
//+CUSD: 1,"Send GHS 5 to Douglas Armooh (0245511543) with Reference: 1. Enter MM PIN for confirmation",64
  mySerial.print("AT+CUSD=1,\"2248\"\r");
  delay(3000);
//  waitForResponse();
//  ShowSerialData();
//+CUSD: 0,"Not enough funds to perform transaction",64
}

void ShowSerialData()
{
  while(!mySerial.available())
    Serial.write(mySerial.read());
}

void waitForResponse(){
    while(!mySerial.available()){
    //stop
  }
}

