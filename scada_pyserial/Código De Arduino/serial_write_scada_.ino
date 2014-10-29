int Analog0=0;
int led13 = 13;
int Analog2=2;
int pin8 =8;
String valor;
int valor_al;
int c;

void setup() 
{
  pinMode(led13, OUTPUT);
  pinMode(Analog0,INPUT);
  pinMode(Analog2,INPUT);
  pinMode(pin8, INPUT);

  Serial.begin(9600);
} 

void loop() 

{ 
 
  pin8=digitalRead (8);                 /*Pin Pulsador*/ 
 
  Analog0=analogRead(0);                 /*Entrada Analogica*/
  Analog0=map(Analog0,0,1023,0,9);
 
  Analog2=analogRead (2);                /*Entrada Analogica*/
  Analog2=map(Analog2,0,1023,0,9);        
  

  if (pin8 == HIGH)
  {

    valor_al=1;


  }
  if (pin8 == LOW)
  {
 
  
    valor_al=0;

  }
 

    if (Serial.available())
  {   
    c = Serial.read();
    if (c == '1') // ENCENDIDO
    {
      digitalWrite(led13, HIGH);//Encendido

    }
    if (c == '0') // APAGADO
    {
      digitalWrite(led13, LOW);//Apagado

    }

  }
  delay(1000);
  String valor =(String(valor_al)  + String (Analog0)   + String (Analog2) + "\n");
  Serial.print(valor); 
}





