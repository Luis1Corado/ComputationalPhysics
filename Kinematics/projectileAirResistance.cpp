#include <iostream>
#include <string>
#include <cmath>
#include <cstdlib>
#include <fstream>
using namespace std;

#define PI 3.1415926535897932
#define g 9.81

int main(){
  double x0,y0, x, y, t, dt, vx0, vy0, vx, vy, tf, theta, v0, k; 
  string buf; 

  cout << "# Enter k, v0, theta (in degrees): \n";
  cin >> k >> v0 >> theta; getline(cin, buf);
  cout << "# Enter dt: \n";
  cin >> dt;
  cout << "# v0= " << v0 << " theta= " << theta << "o (degrees)" << endl;
  cout <<"# t0= " << 0.0 << " tf= " << tf << " dt= " << dt << endl;

//Initialize
  if (v0 <= 0.0){cerr << "Illegal value of v0 <= 0\n";exit(1);}
  if (k <= 0.0){cerr << "Illegal value of k <= 0\n";exit(1);}
  if (theta <= 0.0){cerr << "Illegal value of theta <= 0\n";exit(1);}
  if (theta >= 90){cerr << "Illegal value of theta >= 90\n";exit(1);}
  theta = (PI/180)*theta;
  vx0 = v0*cos(theta);
  vy0 = v0*sin(theta);
  cout << "# vx0 = " << vx0 << " v0y = " << vy0 << endl;
  ofstream myfile("ProjectileAirResistance.dat");
  myfile.precision(17);
  //Compute 
  t = 0.0;
  while(y >= 0){
    vx = vx0*exp(-k*t);
    vy =(vy0 + (g/k))*exp(-k*t)-(g/k);
    x = (vx0/k)*(1-exp(-k*t));
    y = (1.0/k)*(vy0 + (g/k))*(1.0-exp(-k*t)) - (g/k)*t;
    myfile << t << " " << x << " " << y << " " << vx<< " " << vy << endl;
    t = t + dt;
  }
 
}
