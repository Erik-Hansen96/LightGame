//https://www.tinkercad.com/things/l4s05lD0lEB-copy-of-multiple-leds-breadboard-blocks
int arr[] = {5,6,7,8,9,10,11,12,13,12,11,10,9,8,7,6};
int arr1[] = {5,6,7,8,9,10,11,12,13,12,11,10,9,8,7,6};
int arr2[] = {13,12,11,10,9,8,7,6,5,6,7,8,9,10,11,12};
int idx;
bool pressed = false;
void setup()
{
  pinMode(13, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(4, INPUT);
  Serial.begin(9600);
}

void loop()
{
  randomSeed(analogRead(0));
  int rand = random(1,3);
  
  while(!pressed){
    if(rand == 1){
      for(int i = 0; i < 16; i++){
        arr[i] = arr2[i];
      }
    } else{
       for(int i = 0; i < 16; i++){
        arr[i] = arr1[i];
      }
    }
    for(int i = 0; i < 16; i++){
      digitalWrite(arr[i],HIGH);
      if(digitalRead(4) == HIGH){
        idx = i;
        pressed = true;
        delay(300);
        break;
      }
      delay(50);
      if(digitalRead(4) == HIGH){
        idx = i;
        pressed = true;
        delay(300);
        break;
      }
      digitalWrite(arr[i],LOW);
    }
  }

  if(arr[idx] == 9){
    digitalWrite(arr[idx],HIGH);
    delay(100);
    for(int i = 0; i < 5; i++){
      digitalWrite(arr[idx+1],HIGH);
      digitalWrite(arr[idx-1],HIGH);
      delay(100);
      digitalWrite(arr[idx+1],LOW);
      digitalWrite(arr[idx-1],LOW);
      digitalWrite(arr[idx+2],HIGH);
      digitalWrite(arr[idx-2],HIGH);
      delay(100);
      digitalWrite(arr[idx+2],LOW);
      digitalWrite(arr[idx-2],LOW);
      digitalWrite(arr[idx+3],HIGH);
      digitalWrite(arr[idx-3],HIGH);
      delay(100);
      digitalWrite(arr[idx+3],LOW);
      digitalWrite(arr[idx-3],LOW);
      digitalWrite(arr[idx+4],HIGH);
      digitalWrite(arr[idx-4],HIGH);
      delay(100);
      digitalWrite(arr[idx+4],LOW);
      digitalWrite(arr[idx-4],LOW);
    }
    idx++;
  }

  if(digitalRead(4) == HIGH){
    pressed = false;
    delay(200);
    digitalWrite(arr[idx],LOW);
    digitalWrite(arr[idx-1],LOW);
  }

}