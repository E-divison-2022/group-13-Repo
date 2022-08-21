int m1a = 9;
int m1b = 10;
int m2a = 11;
int m2b = 12;
char val;
int RELAY_PINN = 4;
int RELAY_PIN = 3;
void setup() 



{   
pinMode(m1a, OUTPUT);  // Digital pin 10 set as output Pin
pinMode(m1b, OUTPUT);  // Digital pin 11 set as output Pin
pinMode(m2a, OUTPUT);  // Digital pin 12 set as output Pin
pinMode(m2b, OUTPUT);  // Digital pin 13 set as output Pin
pinMode(RELAY_PIN, OUTPUT);
pinMode(RELAY_PINN, OUTPUT);
Serial.begin(9600);
}

void loop()
{
  while (Serial.available() > 0 )
  {
    
  val = Serial.read();
  Serial.println(val);
  }
  if(val=='O')
  {
     digitalWrite(RELAY_PINN, HIGH);
     digitalWrite(RELAY_PIN, LOW);// turn on pump 5 seconds
  }
  else

  if( val == 'F') // Forward
    {
      digitalWrite(m1a, HIGH);
      digitalWrite(m1b, LOW);
      digitalWrite(m2a, HIGH);
      digitalWrite(m2b, LOW);  
    }
  else if(val == 'B') // Backward
    {
      digitalWrite(m1a, LOW);
      digitalWrite(m1b, HIGH);
      digitalWrite(m2a, LOW);
      digitalWrite(m2b, HIGH); 
    }
  
    else if(val == 'R') //Left
    {
    digitalWrite(m1a, LOW);
    digitalWrite(m1b, LOW);
    digitalWrite(m2a, HIGH);
    digitalWrite(m2b, LOW);
    }
    else if(val == 'L') //Right
    {
    digitalWrite(m1a, HIGH);
    digitalWrite(m1b, LOW);
    digitalWrite(m2a, LOW);
    digitalWrite(m2b, LOW); 
    }
    
  else if(val == 'S') //Stop
    {
    digitalWrite(m1a, LOW);
    digitalWrite(m1b, LOW);
    digitalWrite(m2a, LOW);
    digitalWrite(m2b, LOW); 
     
    }
    else if(val == 'T') //Pump Stop
    {
     digitalWrite(RELAY_PINN  , LOW); 
     digitalWrite(RELAY_PIN, LOW);// turn off pump 5 seconds
    }
    
    }
