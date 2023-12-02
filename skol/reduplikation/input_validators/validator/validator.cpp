#include "validator.h"


using namespace std;


void run() {
	string s = Line();
	assert(s.size()<=10);
	int k = Int(1, Arg("maxk", 9)); Endl();

	Eof();
}
