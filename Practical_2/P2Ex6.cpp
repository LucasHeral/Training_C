#include <iostream>
#include <cmath>
using namespace std;

int fibonacci(int n){
  int f2=0;
  int f1=1;
  int fib=0;
  int i;

  if (n==0 || n==1){
    return n;
  }
    
  else {
    return (fibonacci(n-1)+fibonacci(n-2));
  }
}


int main(){
  int element;
  int n;
  cout<<"This algorirthl will give you the n-th element of the Fibonacci sequence. Which n do you want? ";
  cin>> n;
  element = fibonacci(n);
  cout<<element<<endl;

return 0;
}