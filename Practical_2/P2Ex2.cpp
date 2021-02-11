#include <iostream>
#include <cmath>
using namespace std;

void position_of_a_body (double initial_pos, double speed, double accel, int n_times, double delta){

  cout << "Enter the initial position:";
  cin >> initial_pos;
  cout << "Enter the initial speed:";
  cin >> speed;
  cout << "Enter acceleration:";
  cin >> accel;
  cout << "how many times you want to display the position of the moving body?";
  cin >> n_times;
  cout << "how often (in seconds) you want to update the position of the moving object?";
  cin >> delta;



  cout<<"At time 0 the position is: "<<initial_pos<<endl;
  for (int i = 1; i<=n_times;i++){
    double new_position;
    double t = i*delta;
    new_position = initial_pos + speed*t + (1/(2*accel))*t*t;
    initial_pos = new_position;
    cout<<"At time "<<t<<" the position is: "<<new_position<<endl;
   }

}

int main(){

  double initial_position,speed,accel,delta;
  int n_times;
  position_of_a_body(initial_position,speed,accel,n_times,delta);
}