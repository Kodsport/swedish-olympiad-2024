#include "validator.h"


using namespace std;


void run() {
	int n = Int(1, 6); Endl();

	for (int i = 0; i < n; i++)
	{
		int p = Int(1, int(1e6));
		Space();
		int c = Int(1, int(1e6));
		Endl();
	}
	
	int t = Int(1, Arg("max_t", int(1e6)));
	Endl();
	Eof();
}
