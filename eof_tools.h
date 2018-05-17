#include <string>
#include <cstring>
#include <fstream>
#include <cstdint>
#include <sys/stat.h>
using namespace std;

bool file_ends_in(string filename, string ending);
void append_to_file(string filename, string ending);
void remove_bytes_from_file(string filename, int64_t bytes);
