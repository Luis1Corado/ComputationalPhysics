#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <fstream>
#include <string> 
#include <cmath>

using namespace std;
#define PI 3.14159265358979324

void reflectVonCircle(double& vx, double& vy, double& x, double& y, const double& xc, const double& yc, const double& R);
int main(){
   double x0, y0, z0, v0x, v0y, v0z, t0, tf, dt, t, x, y, z, vx, vy, vz;
  double L, R, R2, vxy, rxy, r2xy, xc, yc;
  int i, nr, nz; 
  string buf;

  cout << "#Enter R, L : \n";
  cin >> R >> L; getline(cin, buf);
  cout << "#Enter x0,y0, z0, v0x, v0y, v0z,:\n";
  cin >> x0 >> y0 >> z0 >> v0x >> v0y >> v0z; getline(cin, buf);
  rxy = sqrt(x0*x0 + y0*y0);

  cout << "# Enter t0, tf, dt: \n";
  cin >> t0>>tf>>dt; getline(cin, buf);
  if(R<= 0.0){cerr << "R<=0 \n"; exit(1);}
  if(L<= 0.0){cerr << "L<=0 \n"; exit(1);}
  if(z0< 0.0){cerr << "z0<0 \n"; exit(1);}
  if(z0> L){cerr << "z0>L \n"; exit(1);}
  if(rxy > R){cerr << "rxy > R\n"; exit(1);}
  if(v0x*v0x + v0y*v0y + v0z*v0z == 0.0){cerr << "v0=0 \n";exit(1);}
  
  i = 0;
  nr = 0; nz = 0;
  t = t0;
  x = x0; y = y0; z = z0; 
  vx = v0x; vy = v0y; vz = v0z; 
  R2 = R*R;
  xc = 0.0;
  yc = 0.0;

  ofstream myfile("Cylinder3D.dat");
  myfile.precision(17);

  while(t <= tf){
    myfile << setw(28) << t << " "
      << setw(28) << x << " "
      << setw(28) << y << " "
      << setw(28) << z << " "
      << setw(28) << vx << " "
      << setw(28) << vy << " "
      << setw(28) << vz << '\n';
    i++;
    t = t0 + i*dt;
    x += vx*dt;
    y += vy*dt;
    z += vz*dt;
    if(z<= 0.0 || z > L){vz = -vz; nz++;}
    r2xy = x*x + y*y;
    if(r2xy > R2){
      reflectVonCircle(vx,  vy,  x,  y, xc, yc, R);
      nr++;
    }

  }
  myfile.close();
  cout << "# Number of collisions: \n";
  cout << "# nr= " << nr << " nz= " << nz << endl; 

}

void reflectVonCircle(double& vx, double& vy, double& x, double& y, const double& xc, const double& yc, const double& R){
  double theta , cth, sth, vr, vth;

  theta = atan2(y-yc, x-xc);
  cth = cos(theta);
  sth = sin(theta);

  vr = vx*cth + vy*sth;
  vth = -vx*sth + vy*cth;

  vx = -vr*cth - vth*sth; 
  vy = -vr*sth + vth*cth;
  
  x = xc + R*cth;
  y = yc + R*sth;
}

