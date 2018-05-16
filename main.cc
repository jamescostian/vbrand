#include <cassert>
#include <cstdlib>
#include <iostream>
#include "eof_tools.h"
#include "the_brand.h"

int main(int argc, char **argv) {
  assert(argc == 2);
  string filename = argv[1];
  bool be_silent = getenv("SILENCE_VBRAND") != NULL;
  if (!file_ends_in(filename, THE_BRAND)) {
    append_to_file(filename, THE_BRAND);
    if (!be_silent) {
      cout << "Added brand" << endl;
    }
  }
  else if (!be_silent) {
    cout << "Already branded" << endl;
  }
  return 0;
}
