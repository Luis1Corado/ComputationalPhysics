#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <fstream>
#include <string> 
#include <cmath>

using namespace std;

int main(){
  float L, x0 , v0, t0, tf, dt, t, x, v;
  string buf;

  cout << "# Enter L: \n";
  cin >> L; getline(cin, buf);
  cout << "# L = " << L << endl;
  cout << "# Enter x0, v0: \n";
  cin >> x0 >> v0; getline(cin, buf);
  cout << "# x0= " << x0 << " v0= " << v0<< endl;
  cout << "# Enter t0, tf, dt: \n";
  cin >> t0 >> tf >> dt; getline(cin, buf);
  cout << "# t0 = " << t0 << " tf= " << tf << " dt= " << dt << endl;
  if(L <= 0.0f){cerr << "L <= 0\n"; exit(1);}
  if(x0 < 0.0f){cerr << "x0 < 0\n"; exit(1);}
  if(x0 > L){cerr << "x0 > L\n"; exit(1);}
  if(v0 == 0.0f){cerr << "v0 = 0\n"; exit(1);}

  //Initilize 

  t = t0;
  x = x0; 
  v = v0;

  ofstream myfile("box1D_2.dat");
  myfile.precision(9);

  //compute 

  while(t <= tf){
    x = x0 + v0*(t-t0);
    myfile << setw(17) << t << " " << setw(17) << x << " " << setw(17) << v0 << '\n';
    if(x < 0.0f || x > L){
      x0 = x;
      t0 = t;
      v0 = -v0;
    } 
    t += dt;

  }
  myfile.close();
}
