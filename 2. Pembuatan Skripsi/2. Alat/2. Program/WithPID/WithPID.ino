//https://www.anakkendali.com/arduino-tutorial-pid-untuk-air-heater-dengan-sensor-lm35-tanpa-library-pengujian/
#define pinSensor A0
int val;
float suhu;
float Kp = 10;
float Ki = 0.38;
float Kd = 0;
float Sp = 50 ;
int power;
double error, error_1, sum_error;
void PID () {
  bacaSuhu();
  error_1 = error ;
  error =  suhu - Sp;
  sum_error += error;
  double P = Kp * error;
  double I = Ki * sum_error ;
  double D = (Kd / 100) * (error - error_1);
  power = P + I + D;
  if (power > 255){
    power = 255;
  }
  else if (power < 0){
    power = 0;
  }
  analogWrite(5, power);
}
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}
void loop() {
  // put your main code here, to run repeatedly:
  PID();
//  Serial.print(error);
//  Serial.print("  ");
//  Serial.print(error_1);
//  Serial.print("  ");
//  Serial.print(sum_error);
//  Serial.print("  ");
//  Serial.print(power);
//  Serial.print("  ");
  Serial.print(Sp);
  Serial.print("  ");
  Serial.println(suhu);
}
void bacaSuhu() {
  val = analogRead(pinSensor);
  suhu = val / 2.0479;
  delay(100);
}