#include <bits/stdc++.h>
#include "validator.h"


using namespace std;


void run() {
	int n = Int(1, Arg("maxN", 100)); Endl();
	string s = Line();
	assert(s.size()==n);
	int b = 0, k = 0;
	for (int j = 0; j < n; j++){
		assert(s[j]>='a'&&s[j]<='z');
		if (s[j]=='b') b++;
		if (s[j]=='k') k++;
	}

	string mode = Arg("mode", "");
	if (mode=="bORk"){
		assert(b+k!=0);
		assert(b+k==max(b,k));
	}

	Eof();
}
