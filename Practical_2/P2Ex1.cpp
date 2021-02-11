#include <iostream>
#include <cmath>
using namespace std;

bool is_in_circle (double x, double y, double m, double p, double r){
  bool answer; 
  if (((x-m)*(x-m)+(y-p)*(y-p))<= r*r)
  {
    answer= true; 
  }
  else 
  {
    answer= false;
  }
  return answer; 
} 
//The algorithm returns 1 if the point is in the circle and 0 if it is not. 


int main() {
  double x;
  cout << "x-coordinate of the point:";
  cin >> x;
  double y;
  cout << "y-coordinate of the point:";
  cin >> y;
  double m;
  cout << "x-coordinate of the center of the circle:";
  cin >> m;
  double p;
  cout << "y-coordinate of the center of the circle:";
  cin >> p;
  double r;
  cout << "radius of the circle:";
  cin >> r;  
  cout << is_in_circle(x,y,m,p,r); 
}
