#include <sstream>
#include <cassert>
#include <cstdlib>
#include <cstdint>
#include "eof_tools.h"

bool file_ends_in(string filename, string ending) {
  ifstream file (filename.c_str(), ios_base::binary | ios_base::ate);
  assert(file.is_open());
  // Read the end of the file to a buffer and then close the file
  file.seekg(-ending.length(), ios_base::cur);
  stringstream end;
  end << file.rdbuf();
  return end.str() == ending;
}

void append_to_file(string filename, string ending) {
  ofstream file (filename.c_str(), ios_base::binary | ios_base::app);
  file << ending;
}

uint64_t file_size(string filename) {
  struct stat stat_buf;
  stat(filename.c_str(), &stat_buf);
  return stat_buf.st_size;
}

void remove_bytes_from_file(string filename, uint64_t bytes) {
  string cmd = "truncate -c -s " + to_string(file_size(filename) - bytes) + " " + filename;
  system(cmd.c_str());
}
