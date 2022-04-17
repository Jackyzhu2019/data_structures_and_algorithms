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

class Solution_131 {
public:
	vector<vector<string>> ans;
	vector<string> path;

	int isPalindrome(string s, int left, int right) {
		int len = s.size();

		while (left < right) {
			if (s[left++] != s[right--]) {
				return 0;
			}
		}

		return 1;
	}


	void dfs(string s, int start) {
		int len = s.size();
		int i, j;
		if (start == len) {
			ans.push_back(path);
			return;
		}

		int pathLen = path.size();

		//for (i = start; i < len; i++) {
			for (j = start; j < len; j++) {
				if (isPalindrome(s, start, j)) {
					path.push_back("");
					path[pathLen] += s.substr(start, j-start+1);

					dfs(s, j+1);

					path.pop_back();
					
				}
			}
		//}
	}


	vector<vector<string>> partition(string s) {

		dfs(s, 0);


		return ans;
	}
};

/*
int main() {
	cout << "!!!Hello World!!!" << endl; // prints !!!Hello World!!!

	//vector<int> num = { 2147483640,2147483641 };
	vector<int> num = {0}; // { 7, 6, 4, 3, 1 };
	string a = "abbac";
	vector<string> str = { "leet", "code", "leet" };
	vector<vector<int>> num2D = {
		{1,3,1} , {1,5,1}, {4,2,1}
								};

	Solution_131 sol;
	vector<vector<string>> ans = sol.partition(a);
	//cout << "ans: " << ans << endl;
	for (int i = 0; i < ans.size(); i++) {
		for (int j = 0; j < ans[i].size(); j++) {
			cout << ans[i][j] << " ";
		}
		cout << endl;
	}

	return 0;
}
*/