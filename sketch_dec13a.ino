byte j = 0;
byte vlb = 0;
int scr = 1;
void setup()
{
  for(int i = 3; i < 12; i++)
  {
    pinMode(i, OUTPUT);
    digitalWrite(i, LOW); 
  }
  pinMode(2, INPUT_PULLUP);
  Serial.begin(9600);
  attachInterrupt(digitalPinToInterrupt(2), volba, RISING);
}
void volba(){
  if(vlb > 2)
  {
    vlb = 0;
  }
  else
  {
    vlb++;
  }
}

void loop() {
  switch(vlb)
  {
    case 0:
      scroll();
      break;
    case 1:
      blink();
      break;
    case 2:
      scrollintext();
      break;
  }
  Serial.println(vlb);
   if(vlb > 2)
  {
    vlb = 0;
  } 
}
void scroll() { 
  digitalWrite(j, HIGH);
  digitalWrite(j-1, LOW);
  delay(500); 
  if(j >= 10)
   {
    digitalWrite(j, LOW);
    j = 2;
   }
  j = j+1;

 }
void blink () { //blikání
  for(int h = 3; h < 12; h++)
  { 
    digitalWrite(h, HIGH);
  } 
  delay(500);
  for(int k = 3; k < 12; k++)
  { 
    digitalWrite(k, LOW);
  } 
  delay(500);
}
void scrollintext(){
  if(scr == 1)
  {
    for(int x = 3;x < 11; x++)
    {
      digitalWrite(x, HIGH);
      delay(500);
    }
    scr = 0;
  }
  else if(scr == 0)
  {
    for(int x = 3;x < 11; x++)
    {
      digitalWrite(x, LOW);
      delay(500);
    }
    scr = 1;
  }
}
