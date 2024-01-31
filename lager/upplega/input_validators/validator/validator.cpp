#include <bits/stdc++.h>
#include "validator.h"


using namespace std;


void run() {
	int n = Int(1, Arg("maxn", int(1e5)));
	Space();
	int k = Int(1, Arg("maxk", n));
	Endl();

	vector<int> distances = SpacedInts(n, 0, int(1e9));
	vector<int> degrees = SpacedInts(n, 1, 10);

	bool onlyright = (bool)Arg("onlyRight", 0);

	vector<map<int,vector<int>>> heightmapping;
	vector<vector<int>> allheights;
	for (int i = 0; i < n; i++)
	{
		vector<int> heights = SpacedInts(degrees[i], 1, int(1e9));
		allheights.push_back(heights);
		vector<int> lengths = SpacedInts(degrees[i], -int(1e5), int(1e5));
		for (int j = 0; j < degrees[i]; j++) // check that we do not intersect next tree
		{
			if (i==n-1) break;
			if (lengths[j]>0) assert(distances[i]+lengths[j]<distances[i+1]);
		}

		for (int j = 0; j < degrees[i]; j++) // check that we do not intersect previous tree
		{
			if (i==0) break;
			if (lengths[j]<0) assert(distances[i]-abs(lengths[j])>distances[i-1]);
		}

		for (int j = 0; j < degrees[i]; j++) // check onlyright
		{
			if (onlyright) assert(lengths[j]>0);
		}

		map<int,vector<int>> heightmap; // check that our own branches don't intersect
		for (int j = 0; j < degrees[i]; j++)
		{
			heightmap[heights[j]].push_back(lengths[j]);
		}

		for (int j = 0; j < degrees[i]; j++)
		{
			assert(heightmap[heights[j]].size()<3);
			if (heightmap[heights[j]].size()==2)
			{
				assert(heightmap[heights[j]][0]==-heightmap[heights[j]][1]);
			}
		}
		heightmapping.push_back(heightmap);
	}


	for (int i = 0; i < n-1; i++) // check that branches don't intersect to the right
	{
		for (auto height : allheights[i])
		{
			if (heightmapping[i+1].find(height)==heightmapping[i+1].end()) continue;

			for (auto& b : heightmapping[i][height])
			{
				for (auto& o : heightmapping[i+1][height])
				{
					if (b<0) continue;
					if (o>0) continue;
					assert(distances[i+1]-abs(o)>distances[i]+b);
				}
			}
		}
	}

	//TODO Fix a validator

	Eof();
}
