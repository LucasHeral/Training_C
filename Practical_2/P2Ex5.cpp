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
    
  for(i=2;i<=n;i++){
    fib=f1+f2;
    f2=f1;
    f1=fib;
  }
  return fib;
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
