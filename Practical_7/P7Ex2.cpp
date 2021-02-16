
#include <iostream>
#include <vector>
#include <cmath>


using namespace std;

template <typename T> class Stack {

public:

Stack(){
  TopStack=0;
  size=20;
  s[20];
  NbEle = 0;
}

Stack(int n){
  TopStack=0;
  size=n;
  s[n];
  NbEle = 0;
}

void push (T t){
  if (this->NbEle<this->size && this->NbEle >=0){
    this->s[this->TopStack++]=t;
    this->NbEle++;
  }
  //if (this->NbEle==this->size){
    //throw "FullStackException";
  //}
}

void pop (){
  if (this-> NbEle>0){
    --this->NbEle;
    --this->TopStack;
  }
  if (this-> NbEle==0){
    throw "EmptyStackException";
  }
}


T top(){
  if(this->NbEle>0){
      return this->s[this->TopStack-1];
    }
    else{
      return this->s[0];
    }
}

void print(){
  cout << "___________" << endl;
  if (NbEle==0){
    cout << "The stack is empty" << endl;
  }
  else{
    for(int i=TopStack-1;i>=0;i--){ 
      if (i==TopStack-1)
        cout << "Top of the stack −> \t"; else
        cout << "\t\t\t\t\t\t" ; cout << s[i] << endl;
      } 
    }
  cout << "___________" << endl << endl;
}


private:
int TopStack; //index of the top
int size; //size of the stack 
int NbEle; //Number of elements that are in the stack 
T s[]; //Elements of the stack 

};




int main(){

  Stack<int> s = Stack<int>(6);
  s.push(2);
  s.push(6);
  s.push(7);
  s.print();
  s.pop();
  s.print();


  return 0;
}