int led = 3;
int echo = 4;
int trig = 5;
int distancia;
int duracion;

void setup() {
  // put your setup code here, to run once:
  pinMode(led, OUTPUT);
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(trig, HIGH);
  delay(1);
  digitalWrite(trig, LOW);
  duracion = pulseIn(echo, HIGH);
  distancia = duracion / 58.2;
  Serial.println(distancia);
  delay(500);
  if(distancia <= 20 && distancia >=0){
    digitalWrite(led, HIGH);
    delay(distancia * 10);
    digitalWrite(led, LOW);
  }
}