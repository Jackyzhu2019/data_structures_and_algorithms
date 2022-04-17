//============================================================================
// Name        : e.cpp
// Author      :
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <vector>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <stack>
#include <set>
#include "string.h"
#include "stdlib.h"
#include "algorithm"

using namespace std;

class Solution_139 {
public:
	bool wordBreak(string s, vector<string>& wordDict) {
		int ans = false;
		set<string> dict;

		for (auto wd: wordDict) {

			dict.insert(wd);
		}

		int n = s.size();
		vector<bool> dp(n+1);

		dp[0] = true;
		bool temp;

		for (int i = 1; i < n + 1; i++) {
			for (int j = 0; j < i; j++) {
				string stt = s.substr(j, i-j);
				temp = (dict.find(stt) != dict.end());
				dp[i] = dp[j] && temp;

				if (dp[i] == true)
					break;
			}
		}

		ans = dp[n];
		//for (auto it = dict.begin(); it != dict.end(); it++)
		//	cout << *it << endl;


		return ans;
	}
};

/*
int main() {
	cout << "!!!Hello World!!!" << endl; // prints !!!Hello World!!!

	//vector<int> num = { 2147483640,2147483641 };
	vector<int> num = {0}; // { 7, 6, 4, 3, 1 };
	string a = "leetcode";
	vector<string> str = { "leet", "code", "leet" };
	vector<vector<int>> num2D = {
		{1,3,1} , {1,5,1}, {4,2,1}
								};

	Solution_139 sol;
	bool ans = sol.wordBreak(a, str);
	cout << "ans: " << ans << endl;

	//for (int i = 0; i< ans.size(); i++)
	//	cout << ans[i][0] << " " << ans[i][1] << endl;

	return 0;
}
*/