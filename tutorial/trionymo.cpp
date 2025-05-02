#include <iostream>
#include <cstdlib>
#include <cmath>
using namespace std;

double discriminant(double a, double b, double c);
void roots(double a, double b, double c, double D, double& x1, double& x2);

int main(){
  double a, b, c, D;
  double x1, x2;
  cout << "Polynomial form: aX^2 + bX + c\n";
  cout << "Enter a, b, c: ";
  cin >> a >> b >> c;
  cout << a << " " << b << " " << c << " "<< '\n';

  if (a == 0.0){
    cerr << "Trionomy : a=0 \n";
    exit(1);
  }
  D = discriminant(a, b, c);
  cout << "Discriminant = " << D <<'\n';

  if ( D>0.0){
    roots(a, b, c,D, x1, x2);
    cout << "Roots: x1= "<< x1 << " x2= " << x2<< '\n';
  }
  else if(D== 0.0){
    roots(a, b , c,D, x1, x2);
    cout << "Double root: x1 ="<< x1 << '\n';
  }
  else{
    cout << "No real roots \n";
    exit(1);
  }
}

double discriminant(double a, double b, double c){
  return b*b - 4*a*c;
}

void roots(double a, double b, double c, double D, double& x1, double& x2){
  x1 = (-b + sqrt(D))/(2.0*a);
  x2 = (-b - sqrt(D))/(2.0*a);
}
