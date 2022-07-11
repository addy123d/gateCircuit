#define switch_1 3
#define switch_2 4


#define andGate 5
#define orGate 6
#define xorGate 7
#define nandGate 8

#define outputLED 2

int input_1 = 0; //Input 1
int input_2 = 0; //Input 2

int and_gate = 0;
int or_gate = 0;
int xor_gate = 0;
int nand_gate = 0;

void setup(){
  pinMode(switch_1,INPUT);
  pinMode(switch_2,INPUT);

  pinMode(andGate, INPUT);
  pinMode(orGate, INPUT);
  pinMode(xorGate, INPUT);
  pinMode(nandGate, INPUT);

  pinMode(outputLED,OUTPUT);

  Serial.begin(9600);
}


void loop(){
  int output;
  input_1 = digitalRead(switch_1);
  input_2 = digitalRead(switch_2);

  and_gate = digitalRead(andGate);
  or_gate = digitalRead(orGate);
  xor_gate = digitalRead(xorGate);
  nand_gate = digitalRead(nandGate);

  if(and_gate == HIGH) output = input_1 && input_2;
  if(or_gate == HIGH) output = input_1 || input_2;
  if(xor_gate == HIGH) output = input_1 ^ input_2;
  if(nand_gate == HIGH) output = !(input_1 && input_2);

  if(output == HIGH){
      //Make OUTPUT High
      digitalWrite(outputLED, HIGH);      
  }else{
      digitalWrite(outputLED, LOW);
  }

  delay(100);
}
