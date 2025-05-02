#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <cmath>

using namespace std;

int main(){
  int NSTEPS, i;
  double rs[5] = {0.5, 0.99, 0.9, 0.88, 0.86};
  double x0s[5];
  double r, x0, x1;
  string buf;

  cout << "Enter NSTEPS, r, x0: \n";
  cin >> NSTEPS >> r >> x0; getline(cin, buf);
  cout << "NSTEPS: " << NSTEPS << endl; 
  cout << "r: " << r << endl;
  cout << "x0: " << x0 << endl;
  
  for(int j = 0; j < 5; j ++){
    x0s[j] = x0;
  }
  ofstream myfile("log.dat");
  myfile.precision(17);

  myfile << 0 << x0;
  for (i = 1; i <= NSTEPS; i++){
    myfile << i << " ";
    for (int j = 0 ; j < 5; j++){
        x1 = rs[j]*x0s[j]* (1-x0s[j]);
        myfile << x1 << " ";
        x0s[j] = x1;
       }
    myfile << "\n";
     }
  myfile.close();
}
