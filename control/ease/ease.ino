
const int ping = 7;
const int ping2 = 6;

long d1, d2, cm1, cm2;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  /*
  pinMode(ping, OUTPUT);
  digitalWrite(ping, LOW);
  delayMicroseconds(2);
  digitalWrite(ping, HIGH);
  delayMicroseconds(5);
  digitalWrite(ping, LOW);
  pinMode(ping, INPUT);
  d1 = pulseIn(ping, HIGH);
  
  pinMode(ping2, OUTPUT);
  digitalWrite(ping2, LOW);
  delayMicroseconds(2);
  digitalWrite(ping2, HIGH);
  delayMicroseconds(5);
  digitalWrite(ping2, LOW);
  pinMode(ping2, INPUT);
  d2 = pulseIn(ping2, HIGH);
  */
}

void loop() {
  // put your main code here, to run repeatedly
  configurePing(ping);
  configurePing(ping2);
  
  d1 = pulseIn(ping, HIGH);
  d2 = pulseIn(ping2, HIGH);
  cm1 = d1/29/2;
  cm2 = d2/29/2;
  
  Serial.println(String(cm1) + ", " + String(cm2));
  delay(100);
}

void configurePing(int port) {
  pinMode(port, OUTPUT);
  digitalWrite(port, LOW);
  delayMicroseconds(2);
  digitalWrite(port, HIGH);
  delayMicroseconds(5);
  digitalWrite(port, LOW);
  pinMode(port, INPUT);
}



