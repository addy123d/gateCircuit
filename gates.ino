#define modeButton 2
#define led1 3
#define led2 4
#define led3 5
#define led4 6

#define input1 7
#define input2 8
#define output 9


int buttonState = 0;
int lastButtonState = 0;     // previous state of the button
int counter = 0;

int outputState = 0;


void setup() {
  // put your setup code here, to run once:

  pinMode(modeButton,INPUT);
  pinMode(input1, INPUT);
  pinMode(input2, INPUT);
  
  pinMode(led1,OUTPUT);
  pinMode(led2,OUTPUT);
  pinMode(led3,OUTPUT);
  pinMode(led4,OUTPUT);

  pinMode(output, OUTPUT);
  
  Serial.begin(9600);

}

void loop() {
 
  //Reset Values at start
  digitalWrite(led1, LOW);
  digitalWrite(led2, LOW);
  digitalWrite(led3, LOW);
  digitalWrite(led4, LOW);


  Serial.println("Input 1: ");
  Serial.println(digitalRead(input1));

  Serial.println("Input 2: ");
  Serial.println(digitalRead(input2));
  
  buttonState = digitalRead(modeButton);
  
   // compare the buttonState to its previous state
  if (buttonState != lastButtonState) {
    // if the state has changed, increment the counter
    if (buttonState == HIGH) {
      // if the current state is HIGH then the button went from off to on:
      counter++;
    }
    
    // Delay a little bit to avoid bouncing
    delay(50);
  }
  // save the current state as the last state, for next time through the loop
  lastButtonState = buttonState;

  
  Serial.println("Counter Value: ");
  Serial.println(counter);
  
  switch(counter){
    case 1:
     digitalWrite(led1,HIGH);
     digitalRead(input1) && digitalRead(input2) ? digitalWrite(output,HIGH) : digitalWrite(output,LOW);
      break;
    case 2:
      digitalWrite(led2,HIGH);
      digitalRead(input1) || digitalRead(input2) ? digitalWrite(output,HIGH) : digitalWrite(output,LOW);
      break;
    case 3:
      digitalWrite(led3,HIGH);
      digitalRead(input1) ^ digitalRead(input2) ? digitalWrite(output,HIGH) : digitalWrite(output,LOW);
      break;
    case 4:
      digitalWrite(led4,HIGH);
      ! (digitalRead(input1) && digitalRead(input2)) ? digitalWrite(output,HIGH) : digitalWrite(output,LOW);
      break;
    default:
      counter = 0;
      break;
  }
  
 
  
  delay(100);
  

}
