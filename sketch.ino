// Now turn this trash into treasure!
#define RED 22
#define GREEN 21
#define BLUE 20
#define TRIG 28
#define ECHO 27
#define BUZZER 26
#define BUTTON 11 
int buttonState = LOW;
// i dont think the library i just tried to do works so im commenting it
/* #include <TM1637.h>;
const int CLK = 0;
const int DIO = 1; 
TM1637 tm(CLK, DIO); */
void setup() {

  pinMode(TRIG, OUTPUT);
  pinMode(ECHO, INPUT);

  pinMode(RED, OUTPUT);
  pinMode(GREEN, OUTPUT);
  pinMode(BLUE, OUTPUT);

  pinMode(BUTTON, INPUT);

  Serial1.begin(115200);
  Serial1.println("Range finder with RGB LED marking distance");
}

void loop() {
  digitalWrite(TRIG, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG, LOW);


  buttonState = digitalRead(BUTTON); // Read the button state

    if (buttonState == HIGH) {
        Serial1.println("Button  pressed!"); // Action when button is pressed
         int duration = pulseIn(ECHO, HIGH);
          int inches = duration / 148;

          Serial1.print("Distance in inches: ");
          Serial1.println(inches);
           if (inches > 144) { // over 10 feet
            analogWrite(GREEN, 0);
            analogWrite(RED, 0);
            analogWrite(BLUE, 255);
          } else if (inches > 120) { // over 10 feet
            analogWrite(GREEN, 244);
            analogWrite(RED, 3);
            analogWrite(BLUE, 252);
          } else if (inches > 96){
            analogWrite(GREEN, 255);
            analogWrite(RED, 0);
            analogWrite(BLUE, 0);
          } else if (inches > 72){
            analogWrite(GREEN, 255);
            analogWrite(RED, 238);
            analogWrite(BLUE, 0);
          } else if (inches > 48){
            analogWrite(GREEN, 89);
            analogWrite(RED, 255);
            analogWrite(BLUE, 0);
          } else if (inches > 24){
            analogWrite(GREEN, 0);
            analogWrite(RED, 255);
            analogWrite(BLUE, 0);
          } else if (inches > 12) {
            analogWrite(GREEN, 0);
            analogWrite(RED, 255);
            analogWrite(BLUE, 242);
          } else {
             analogWrite(GREEN, 0);
            analogWrite(RED, 255);
            analogWrite(BLUE, 242);
            tone(BUZZER, 440, 25); // middle A 10 ms
            delay(50);
            analogWrite(GREEN, 66);
            analogWrite(RED, 200);
            analogWrite(BLUE, 245);
            delay(40);
            analogWrite(GREEN, 0);
            analogWrite(RED, 255);
            analogWrite(BLUE, 242);// flashing for extra visibility below 1 foot
          }
          /* tm.display(0, (inches % 10));
         tm.display(1, (inches / 10) % 10);
           tm.display(2, (inches / 10) % 10);
          tm.display(3, 0); */
    } else {
        analogWrite(GREEN, 0);
        analogWrite(RED, 0);
        analogWrite(BLUE, 0);
    }

  delay(100);

  
}