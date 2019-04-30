#include <Arduino.h>

class Stack{
  private:
    String data[250];
    int current;
    void doubleSize();
  public:
    int size;
    Stack();
    void addItem(String input);
    String getItem(int index);
};

