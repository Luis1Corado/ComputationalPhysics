#include <fstream>
#include <cmath>
#include <iostream> 
#include <string>
#include <cstdlib>

using namespace std;

#define g 9.81
#define PI 3.1415926535897932

int main(){
  double r, x, y, z, v0, v0x, v0y, v0z, t, tf, dt;
  double vx, vy, vz, x0, y0, z0;
  double theta, omega;

  string buf;

  cout << "# Enter omega: \n";
  cin >> omega; getline(cin, buf);
  cout << "# Enter v0, theta (degrees): \n";
  cin >> v0 >> theta;  getline(cin, buf);
  cout << "#Enter tf, dt: \n";
  cin >> tf >> dt;
  
  cout << "# omega= " << omega << "T = " << 2.0*PI/omega << endl;
  cout << "# v0= " << v0 << "Theta= " << theta << endl;
  cout <<"# t0= " << 0.0 << " tf= " << tf << " dt= " << dt << endl;

  //Initialize
  if(theta<0.0 || theta >= 90.0) exit(1);
  theta = PI/180.0*theta;
  v0y = v0*cos(theta);
  v0z = v0*sin(theta);
  cout << "# V0x= " << 0.0
       << " V0y= " << v0y
       << " V0z= " << v0z << endl;
  x0 = -v0y/omega; 
  cout << " x0= " << x0 
    << " y0= " << y0
    << " z0 = " << z0;
  ofstream myfile("ChargeinB.dat");
  myfile.precision(17);

  t = 0.0;
  vz = v0z; 
  while(t <= tf){
    x = x0*cos(omega*t);
    y = -x0*sin(omega*t);
    z = v0z*t;
    vx = v0y*sin(omega*t);
    vy = v0y*cos(omega*t);
    myfile << t << " " << x<< " " << y<< " " << z << " " << vx << " " << vy << " " << vz << " " <<endl;
    t = t+dt;
  }
}


