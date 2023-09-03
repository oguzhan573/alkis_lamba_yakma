

int ses_sensoru = 13;
int role = A0;
int alkis = 0;
long algilama_araligi_baslangic = 0;
long algilama_araligi = 0;
bool isik_durumu = false;

void setup() {
  pinMode(ses_sensoru, INPUT);
  pinMode(role, OUTPUT);
  
}


void loop()
 {

  int sensor_durumu = digitalRead(ses_sensoru);

  if (sensor_durumu ==0) 
  {
    if (alkis == 0) 
    {
      algilama_araligi_baslangic = algilama_araligi = millis();
      alkis++;
    } 
    else if (alkis > 0 && millis() - algilama_araligi >= 50) {
      algilama_araligi = millis();
      alkis++;
    }
  }

  if (millis() - algilama_araligi_baslangic >= 250) 
  {
    
    if (alkis == 2) 
    {
      if (isik_durumu==false) 
      {
        isik_durumu = true;
        digitalWrite(role, HIGH);
      } 
      else if (isik_durumu==true) 
      {
        isik_durumu = false;
        digitalWrite(role, LOW);
      }
    }
    alkis = 0;
  }
}
