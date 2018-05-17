#include <cstdlib>
#include <iostream>
#include "eof_tools.h"

bool XOR(bool p, bool q) {
  return (p || q) && !(p && q);
}

int main(int argc, char **argv) {
  if (argc == 1 || XOR(strcmp(argv[1], "rm"), argc == 2) || argc > 3) {
    cerr << "USAGE:" << endl;
    cerr << endl;
    cerr << "  vbrand path/to/file" << endl;
    cerr << "  vbrand rm path/to/file" << endl;
    cerr << endl;
    cerr << "The first will add the brand to the file (if it's not already there)" << endl;
    cerr << "The second will remove the brand from the file (if it's already there)" << endl;
    return 1;
  }
  const bool should_be_branded = argc == 2;
  string filename = argc == 2 ? argv[1] : argv[2];
  if (!file_ends_in(filename, THE_BRAND)) {
    if (should_be_branded) {
      append_to_file(filename, THE_BRAND);
      cout << "Added brand to " << filename << endl;
    }
    else {
      cout << filename << " wasn't even branded" << endl;
    }
  }
  else {
    if (should_be_branded) {
      cout << "Already branded " << filename << endl;
    }
    else {
      string brand = THE_BRAND;
      remove_bytes_from_file(filename, brand.length());
      cout << "Removed branding from " << filename << endl;
    }
  }
  return 0;
}
