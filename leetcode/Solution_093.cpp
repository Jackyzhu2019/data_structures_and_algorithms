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

class Solution_093 {
public:
	vector <string> ans;
	vector <string> path;

	void dfs(string s, int start) {
		int i, j;
		int len = path.size();

		if (len == 4 && start == s.size()) {
			string SinglePath = path[0] + "." + path[1] + "." + path[2] + "." + path[3];
			ans.push_back(SinglePath);
			return;
		}

		if (len == 4)
			return;

		if (s[start] == '0') {
			path.push_back("");
			path[len] += s[start];
			
			dfs(s, start + 1);

			path.pop_back();
		}
		else {
			int ss = 0;
			string temp;
			for (i = start; i < s.size(); i++) {
				ss = ss * 10 + (s[i] - '0');
				temp.push_back(s[i]);
				if (ss < 256 && ss > 0) {
					path.push_back("");
					path[len] += temp;
					
					dfs(s, i+1);
				
					path.pop_back();
				}
				else {
					break;
				}
				
			}

		}
	}


	vector<string> restoreIpAddresses(string s) {
		int len = s.size();

		if (len < 4) {
			return ans;
		}

		dfs(s, 0);



		return ans;
	}
};

/*
int main() {
	cout << "!!!Hello World!!!" << endl; // prints !!!Hello World!!!

	//vector<int> num = { 2147483640,2147483641 };
	vector<int> num = { 10,1,2,7,6,1,5 };
	string a = "00000"; // "12345";
	vector<string> str = { "leet", "code", "leet" };
	vector<vector<int>> num2D = {
		{1,3,1} , {1,5,1}, {4,2,1}
								};

	Solution_093 sol;
	vector<string> ans = sol.restoreIpAddresses(a);
	//cout << "ans: " << ans << endl;

	for (int i = 0; i < ans.size(); i++) {
		//for (int j = 0; j < ans[i].size(); j++) {
			cout << ans[i] << endl;
		//}
		//cout << endl;
	}

	return 0;
}
*/