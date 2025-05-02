#include <fstream>
#include <cmath>
#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

#define g 9.81
#define PI 3.1415926535897932

int main(){
  double l, r, x, y, z, vx, vy, vz, t, dt, tf;
  double theta, omega, cos_theta, sin_theta;
  string buf; 

  cout << "# Enter l, omega : \n";
  cin >> l >> omega; getline(cin, buf);
  cout << "# Enter tf, dt: \n";
  cin >> tf >> dt;
  cout << "# l= " << l << " omega= " << omega << endl;
  cout << "#T= " << 2.0*PI/omega <<"omega_min= " << sqrt(g/l)<< endl;
  cout << "# t0= " << 0.0 << " tf= " << tf << " dt= " << dt << endl;

  //Initialize  
  cos_theta = g/(omega*omega*l);
  if(cos_theta >= 1.0){
    cerr << "cos(theta)>= 1\n";
    exit(1);
  }
  sin_theta = sqrt(1.0 - cos_theta*cos_theta);
  z = -g/(omega*omega);
  vz = 0.0;
  r = g/(omega*omega)*sin_theta/cos_theta;
  ofstream myfile("ConicalPendulum.dat");
  myfile.precision(17);

  t = 0;
  while(t <= tf){
    x = r*cos(omega*t);
    y = r*sin(omega*t);
    vx = -r*sin(omega*t)*omega;
    vy = r*cos(omega*t)*omega;
    myfile << t << " "<<  x << " " << y << " " << z << " " << vx<< " " << vy << " " << vz << " " << endl;
    t = t+ dt;
  }

 }
