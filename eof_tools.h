#include <string>
#include <fstream>
using namespace std;

bool file_ends_in(string filename, string ending);
void append_to_file(string filename, string ending);
void remove_bytes_from_file(string filename, int bytes);
