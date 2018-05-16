#include <sstream>
#include <cassert>
#include "eof_tools.h"

bool file_ends_in(string filename, string ending) {
  ifstream file (filename.c_str(), ios_base::binary | ios_base::ate);
  assert(f.is_open());
  // Read the end of the file to a buffer and then close the file
  f.seekg(-ending.length(), ios_base::cur);
  stringstream end;
  end << f.rdbuf();
  return end.str() == ending;
}

void append_to_file(string filename, string ending) {
  ofstream file (filename.c_str(), ios_base::binary | ios_base::app);
  f << ending;
}
