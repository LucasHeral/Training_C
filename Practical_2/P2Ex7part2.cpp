#include <iostream>
#include <cmath>
using namespace std;

int part2(int a, int power){
  if(power==0){
    return 1;
  }
  else if(power%2==0){
    return(part2(a,(power/2))*part2(a,(power/2)));
  }
  else{
    return(part2(a,(power/2))*part2(a,(power/2))*a);
  }
}  
  
int main(){
  int a,power;
  cout<<"Enter an integer:";
  cin>> a;
  cout<<"Enter the power to which you want to compute the integre, you must enter a non-negative integer:";
  cin>> power;
  cout<<part2(a,power);
}