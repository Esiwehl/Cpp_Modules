#include <iostream>
#include <fstream>
using namespace std;

int main () {
  ofstream myfile;
  myfile.open ("_shrubbery");
  myfile << "	 _                 
				| |                
				| |_ _ __ ___  ___ 
				| __| '__// _ \\/ _ \\
				| |_| | |  __/  __/
				 \\__|_|  \\___|\\___|\"";
  myfile.close();
  return 0;
}

