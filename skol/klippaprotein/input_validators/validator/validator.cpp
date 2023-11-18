#include "validator.h"


using namespace std;


void run() {
	string s = Line();

	int k = Int(1, Arg("maxk", s.size())); Endl();

	Eof();
}
