#include <iostream>
#include <cmath>
using namespace std;


double * read_poly(int &n){
  cout << "Please enter the degree of the polynomial: ";
  cin >> n;
  double * c=new double[n+1];
  for(int i=0;i<=n;i++){
    cout << "Coefficient of degree " << i << ": ";
    cin >> c[i];
  }
  return c;
}


void print_poly(double *c, int n){
  int i;
  cout << c[0];
  if(n>0)
    cout << " + ";
  for(i=1;i<n;i++)
    cout << c[i] << "*x^" << i << " + ";
  if(n>0)
    cout << c[n] << "*x^" << i;
  cout << endl;
}


double value_at_position_x(double *c, int n,double x){

  double val = c[0];
  if(n>0){
    for(int i = 1;i<=n;i++){
      val += c[i]*pow(x,i);
    }
  }
  return val;
}

double * poli_sum (double * p1, int d1, double * p2, int d2, int & dr){
  if(d1 == d2){
    dr =d1;
    double * c=new double[dr+1]; 
    for (int i=0;i<=dr;i++){
      c[i] = p1[i] +p2[i];
    }
    return c;
  }
  
  else{
    dr = max(d1,d2);
    double * c=new double[dr+1]; 
    for (int i =0;i<=min(d1,d2);i++){
      c[i] = p1[i] +p2[i];
    }

    if (d1 == max(d1,d2)){
      for (int n = min(d1,d2)+1;n<=d1;n++){
        c[n] = p1[n];}
    }
    else{
      for (int n = min(d1,d2)+1;n<=d2;n++){
        c[n] = p2[n];
      }
    }
    return c;
  }
}


double * poli_prod (double *p1, int d1, double *p2, int d2, int &dr2){
  dr2 = d1 + d2;

  double *c = new double [dr2+1];
  for(int i = 0;i<=d1;i++){
    for(int j = 0; j<=d2;j++){
      c[i+j] += p1[i]*p2[j];
      }
    }
  return c;
}



int main()
{
  double *p1;
  double *p2;
  double *p3;
  double *p4;
  double px;
  int d1;
  int d2;
  int dr;
  int dr2;
  int x;

  p1=read_poly(d1);
  print_poly(p1,d1);

  cout<<"Please enter a real number x for which the polynomial previously entered will be computed:";
  cin>>x;
  px = value_at_position_x(p1,d1,x);
  cout<<"At x = "<<x<<" the value of the polynomial is "<<px<<endl;

  cout<<"Lets now find sum and product of the polynomial just entered with a new polynomial."<<endl;

  p2 = read_poly(d2);
  print_poly(p2,d2);

  p3 = poli_sum(p1,d1,p2,d2,dr);
  cout<<"The sum of the two polynomials entered is: "<<endl;
  print_poly(p3,dr);

  p4 = poli_prod(p1,d1,p2,d2,dr2);
  cout<<"The product of the two polynomials entered is: "<<endl;
  print_poly(p4,dr2);

  delete[] p1;
  delete[] p2;
  delete[] p3;
  delete[] p4;
  return 0;

}