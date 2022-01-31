#include "Grammar.h"
#include <iostream>
#include <stdlib.h>

using namespace std;

int main(int argc, char *argv[]) {
  
  string fname;
  fname = "computergram.txt";
  Grammar g(fname);

  g.show();

}
