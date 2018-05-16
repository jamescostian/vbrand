#include <cstdlib>
#include <iostream>
#include "eof_tools.h"

int main(int argc, char **argv) {
  if (argc != 2) {
    cerr << "USAGE: vbrand path/to/file" << endl;
    return 1;
  }
  string filename = argv[1];
  if (!file_ends_in(filename, THE_BRAND)) {
    append_to_file(filename, THE_BRAND);
    cout << "Added brand to " << filename << endl;
  }
  else {
    cout << "Already branded " << filename << endl;
  }
  return 0;
}
