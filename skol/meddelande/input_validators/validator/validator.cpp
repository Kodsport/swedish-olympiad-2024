#include "validator.h"


using namespace std;


void run() {
	int n = Int(1, 6);
	Space();
	int m = Int(1, 6);
	Endl();
	for(int c1 = 0; c1 < n; c1++){
		string s = Line();
		assert(s.size() == m);
	}
	Eof();
}
