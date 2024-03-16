#include "validate.h"

#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define debug(...) //ignore
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef long double ld;



bool check(vi &answer, vvi &signs, int size, int m){
	
	rep(j,0,m){
		rep(i,0,size-1){
			if (signs[answer[i]-1][j] >= signs[answer[i+1]-1][j]) continue;
			return false;
		}
	}

	return true;
}

int main(int argc, char **argv) {
	init_io(argc, argv);
	

	int n, m;
	judge_in >> n >> m;

	vvi signs(n);

	rep(i,0,n){
		rep(j,0,m){
			int temp;
			judge_in >> temp;
			signs[i].push_back(temp);
		}
	}

	int correct_ans;
	if(!(judge_ans >> correct_ans)) judge_error("Expected more output");
	
	vi judge_nums;
	rep(i,0,correct_ans){
		int temp;
		if(!(judge_ans >> temp)) judge_error("Expected more output (sign indicies)");
		judge_nums.push_back(temp);
	}

	string trailing;
	if(judge_ans >> trailing) judge_error("Trailing output");

	if (!check(judge_nums, signs, correct_ans, m)) judge_error("Judge's solution is invalid.");


	int auth_ans;
	// Check if the output has the same answer (number) as the Judge.
	if(!(author_out >> auth_ans)) wrong_answer("Expected more output");
	
	if (auth_ans != correct_ans) wrong_answer("The answer (maximum number of signs) is wrong.");

	vi auth_nums;
	rep(i,0,correct_ans){
		int temp;
		if(!(author_out >> temp)) judge_error("Expected more output (sign indicies)");
		auth_nums.push_back(temp);
	}

	string trailing2;
	if(author_out >> trailing2) judge_error("Trailing output");


	if (!check(auth_nums, signs, correct_ans, m)) wrong_answer("Judge's solution is invalid.");

	accept();
}
