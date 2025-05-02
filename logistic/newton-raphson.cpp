#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cmath>
#include <string>
using namespace std;

double f(double x, double rho);
double fp(double x, double rho);

int main(){
  const double rho = 15.0;
  const double eps = 1.0e-6;
  const int NMAX = 1000;
  double x0 , x1, err, g, gp;
  int i; 
  string buf;

  cout << "#Enter x0: \n";
  cin >> x0; getline(cin, buf);
  err = 1.0;
  cout << "iter  x                                   error      \n";
  cout << "-----------------------------------------------------\n";
  cout << 0 << " " << x0 << " " << err << '\n';

  cout.precision(17);

  for(i=1; i<NMAX; i++){
    g = x0*tan(x0) -sqrt(rho*rho -x0*x0);
    gp = x0/sqrt(rho*rho - x0*x0) + x0/(cos(x0)*cos(x0)) + tan(x0);
    x1 = x0 - g/gp;
    err = abs(x1-x0);
    cout << i << " " << x1 << " " << err << '\n';
    if(err < eps) break;
    x0 = x1;
  }
}

double f(double x, double rho){
  return x*tan(x) - sqrt(rho*rho - x*x);
}

double fp(double x, double rho){
    return x/sqrt(rho*rho - x*x) + x/(cos(x)*cos(x)) + tan(x);
}
