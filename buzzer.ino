const int buzzer = 11;
const int trig = 8;
const int echo = 9;

void setup() {
  // put your setup code here, to run once:
  pinMode(buzzer, OUTPUT);
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);
  Serial.begin(9600);
}

void loop() {
  delay(3000);
  tone(buzzer, 32.7032);
  delay(1000);
  noTone(buzzer);

  delay(3000);

  double distance = cal_distance();
  Serial.println( distance);
  if(distance <= 50 ) {
    Serial.println("라");
    tone(buzzer, 440);
    delay(1000);
    noTone(buzzer);
  }
  else if( distance <= 100) {
    Serial.println("파");
    tone(buzzer, 349.2282);
    delay(1000);
    noTone(buzzer);
  }
  else if(distance <= 150) {
    Serial.println("레");
    tone(buzzer, 293.6648);
    delay(1000);
    noTone(buzzer);
  }
  else {
    Serial.println("도");
    tone(buzzer, 261.6256);
    delay(1000);
    noTone(buzzer);
  }
}

int cal_distance() {
  unsigned echoTimeUs;
  double distanceMm;

  digitalWrite(trig, HIGH);
  delayMicroseconds(20);
  digitalWrite(trig, LOW);
  echoTimeUs = pulseIn(echo, HIGH);

  distanceMm = ((34000*echoTimeUs)/1000000)/2;
  
  Serial.print(distanceMm);
  Serial.println(" cm");
  return ((ceil)(distanceMm));
}
