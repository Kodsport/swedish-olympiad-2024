#include <bits/stdc++.h>
#include "validator.h"


using namespace std;


void run() {
	int N = Int();

	for (int i = 0; i < N; i++) {
		string s = Line();
		assert(s.size() == N);
		for (int j = 0; j < N; j++) {
			assert(s[j] == '0' || s[j] == '1');
		}
	}

	Eof();
}
