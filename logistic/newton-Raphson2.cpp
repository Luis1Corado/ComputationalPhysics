#include <iostream> 
#include <cmath> 
#include <cstdlib> 
#include <string>
#include <fstream> 

using namespace std;

void solve2x2(double A[2][2], double b[2], double dx[2]);

int main(){
  const double eps = 1.0e-6;
  const int NMAX = 1000;
  double A[2][2], b[2], dx[2];
  double x, y, err; 
  int i; 
  string buf;

  cout << "# Enter x0, y0: \n";
  cin >> x >> y; getline(cin, buf);
  err = 1.0;
  cout << "Iter         x               y                  error   \n";
  cout << "--------------------------------------------------------\n";
  cout << 0 << " " << x << " " << y << " " <<  err << '\n';

  cout.precision(17);
  for(i = 1; i<= NMAX; i++){
    b[0] = -(2.0*x*x -3.0*x*y + y -2.0); // -g1(x,y)
    b[1] = -(3.0*x + x*y + y -1.0); // -g2(x, y)
    // dg1/dx
    A[0][0] = 4.0*x -3.0*y; A[0][1] = 1.0 - 3.0*x;
    // dg2/dx            dg2/dy
    A[1][0] = 3.0 + y; A[1][1] = x + 1.0;
    
    solve2x2(A, b, dx);
    x += dx[0];
    y += dx[1];
    err = 0.5*sqrt(dx[0]*dx[0] + dx[1]*dx[1]);
    cout << i << " " << x << " " << y << " " << err << endl; 
    if(err < eps) break;
  }
}

void solve2x2(double A[2][2], double b[2], double dx[2]){
  double num0, num1, det;

  num0 = A[1][1] *b[0] - A[0][1]*b[1];
  num1 = A[0][0] *b[1] - A[1][0]*b[0];
  det = A[0][0]*A[1][1] - A[1][0]*A[0][1]; 
  if(det == 0.0){cerr << "solve2x2: det = 0 \n"; exit(1);}
  dx[0] = num0/det;
  dx[1] = num1/det;

}
