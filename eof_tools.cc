#include <sstream>
#include <cassert>
#include <cstdlib>
#include <sys/stat.h>
#include "eof_tools.h"

bool file_ends_in(string filename, string ending) {
  ifstream file(filename.c_str(), ios_base::binary | ios_base::ate);
  assert(file.is_open());
  // Read the end of the file to a buffer and then close the file
  file.seekg(-ending.length(), ios_base::cur);
  stringstream end;
  end << file.rdbuf();
  return end.str() == ending;
}

void append_to_file(string filename, string ending) {
  ofstream file(filename.c_str(), ios_base::binary | ios_base::app);
  file << ending;
}

#ifdef _WIN32
#include <Windows.h>
void remove_bytes_from_file(string filename, int64_t bytes) {
  LPCWSTR filenameW = wstring(filename.begin(), filename.end()).c_str();
  HANDLE h = CreateFileW(filenameW, GENERIC_WRITE, FILE_SHARE_READ, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
  assert(h != INVALID_HANDLE_VALUE);
  LARGE_INTEGER size_modifier;
  size_modifier.QuadPart = -bytes;
  assert(SetFilePointerEx(h, size_modifier, NULL, FILE_END));
  assert(SetEndOfFile(h));
  CloseHandle(h);
}
#else
#include <unistd.h>
#include <sys/stat.h>
void remove_bytes_from_file(string filename, int64_t bytes) {
  struct stat stat_buf;
  stat(filename.c_str(), &stat_buf);
  assert(truncate(filename.c_str(), stat_buf.st_size - bytes) == 0);
}
#endif
