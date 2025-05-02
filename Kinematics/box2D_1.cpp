#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <fstream>
#include <string> 
#include <cmath>

using namespace std;

int main(){
  double Lx, Ly, x0, y0, v0x, v0y, t0, tf, dt, t, x, y, vx, vy;
  int i, nx, ny;
  string buf; 

  cout << "#Enter Lx, Ly:\n";
  cin >> Lx >> Ly; getline(cin, buf);
  cout << "# Lx = " << Lx << " Ly = " << Ly << endl;
  cout << "# Enter x0, y0, v0x, v0y: \n";
  cin >> x0 >> y0 >> v0x >> v0y; getline(cin, buf);
  cout << "# x0= " << x0 << " y0= " << y0 << " v0x= " << v0x << " v0y= " << v0y << endl;
  cout << "# Enter t0, tf, dt: \n";
  cin >> t0 >> tf >> dt; getline(cin, buf);
  cout << "# t0= " << t0 << " tf= " << tf << " dt= " << dt << endl;
  if(Lx<= 0.0){cerr << "Lx<=0 \n"; exit(1);}
  if(Ly<= 0.0){cerr << "Ly<=0 \n"; exit(1);}
  if(x0< 0.0){cerr << "x0<=0 \n"; exit(1);}
  if(x0> Lx){cerr << "x0> Lx \n"; exit(1);}
  if(y0< 0.0){cerr << "y0<=0 \n"; exit(1);}
  if(y0> Ly){cerr << "y0> Ly \n"; exit(1);}
  if(v0x*v0x+v0y*v0y == 0.0){cerr << "v0 =0 \n"; exit(1);}

  i = 0;
  nx = 0;
  ny = 0;
  t = t0;
  x = x0; y = y0;
  vx = v0x; vy = v0y;
  ofstream myfile("box2D_1.dat");
  myfile.precision(17);

  while(t <= tf){
    myfile << setw(28) << t << " " << setw(28) << x << " " << setw(28) << y << " " << setw(28) << vx << " " << setw(28) << vy << '\n';
    i += 1; 
    t = t0 + i*dt; 
    x += vx*dt;
    y += vy*dt;

    if(x < 0.0 || x > Lx){
      vx = -vx;
      nx++;
    }
    if(y < 0.0 || y > Ly){
      vy = -vy;
      ny++;
    }   
  }
  myfile.close();
  cout << "# Number of collisions: \n";
  cout << "# nx= " << nx << " ny= " << ny << endl;
}


