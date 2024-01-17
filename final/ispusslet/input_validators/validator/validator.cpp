#include "validator.h"

void run() {
	int n = Int(1, 1000);
	Space();
	int retstart = Int(0,1);
	Endl();
	int ret = Arg("r",-1);
	if (ret!=-1) assert(retstart==ret);

	int xcnt = 0;
	vector<string> rows;
	int r = -1;
	int c = -1;
	vector<int> good(250);
	good['X']=1;
	good['O']=1;
	good['.']=1;
	int ocnt = 0;
	for (int i = 0; i < n; i++)
	{
		string row = Line();
		rows.push_back(row);
		for (int j = 0; j < n; j++) assert(good[row[j]]);

		for (int j = 0; j < n; j++) xcnt += row[j]=='X';
		for (int j = 0; j < n; j++) if (row[j]=='O') xcnt++, ocnt++, r=i,c=j;

	}
	assert(ocnt==1);
	assert(rows[r][c]=='O');
	assert(xcnt<=int(Arg("maxX", int(1e5))));
	
	Eof();
}
