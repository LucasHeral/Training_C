
#include <iostream>
#include <cmath>
using namespace std;

void swap(int &x, int &y) {
   int temp;
   temp = x; 
   x = y;    
   y = temp; 
  
   return;
}

int main(){
  int x= 2;
  int y= 3;
  swap (x,y);
  return 0;
}

