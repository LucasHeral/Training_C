#include <iostream>
#include <cmath>
using namespace std;


int part1(int a, int power){
  if(power==0){
    return 1;
  }
  else{
    return(a * part1(a,(power-1)));
  }
}

int main(){
  int a,power;
  cout<<"Enter an integer:";
  cin>> a;
  cout<<"Enter the power to which you want to compute the integre, you must enter a non-negative integer:";
  cin>> power;
  cout<<part1(a,power);
}

