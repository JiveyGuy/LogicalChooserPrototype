#include <Arduino.h>
#define DEBUG true

//Stack object class declaration
class Stack{
  
  public: //public modifier
    int size;
    Stack();
    void addItem(String input);
    String getItem(int index);
    String toString();
  private: //private modifier (not using c++ convention rather java)
    String data[250];
    int current;
    void doubleSize();
};

//==========================================
Stack::Stack(){
      size = 250;
      current = 0;
}
void Stack::addItem(String input){
  if( current >= size ){
     doubleSize();
     addItem( input );
  } else {
     data[current++] = input;
  }
}
String Stack::toString(){
  String temp = "";
  for( int x =  0; x < current; x++){
    temp += data[current] + "\n";
  }
  return temp;
}
String Stack::getItem(int index){
  return data[ index ];
}

void Stack::doubleSize(){
    int len = size * 2;
    String temp[ len ];
    for( int x = 0; x < size; x++ ){
      temp[x] = data[x];
    }
}

//============================================
String getString(String text){
  Serial.print( text );
  while(Serial.available() == 0);
  String result = Serial.readString();
  Serial.println( result );
  return result;
}


void debug(String input){
  if( DEBUG ) Serial.println( "DEBUGG:: " + input );
}

Stack strings;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  getData();
  Serial.println(strings.toString());

}

void loop() {
  // put your main code here, to run repeatedly:
  
}


void getData(){
  //Run once always
  String temp = "";
  do{
    temp = getString( "::> ");
    strings.addItem( temp );
  }while(temp.length() > 0);
}
