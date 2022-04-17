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

class Solution_017 {
public:
	vector <string> ans;
	string path;
	
	map<char, string> mapping{
		{'2', "abc"},
		{'3', "def"},
		{'4', "ghi"},
		{'5', "jkl"},
		{'6', "mno"},
		{'7', "pqrs"},
		{'8', "tuv"},
		{'9', "wxyz"}
	};


	void dfs(string digits, int start) {
		if (path.size() == digits.size()) {
			ans.push_back(path);
			return;
		}

		string S = mapping.at(digits[start]);
		for (char i : S) {
			path.push_back(i);

			dfs(digits, start+1);

			path.pop_back();
		}

	}


	vector<string> letterCombinations(string digits) {
		char ch;
		int i;

		if (digits.size() == 0)
			return ans;

		if (digits.size() == 1) {
			ch = digits[0];
			string s = mapping[ch];
			for (i = 0; i < s.size(); i++) {
				path.push_back(s[i]);
				ans.push_back(path);
				path.pop_back();
			}

			return ans;
		}

		dfs(digits, 0);

		return ans;
	}

	

};

/*
int main() {
	cout << "!!!Hello World!!!" << endl; // prints !!!Hello World!!!

	//vector<int> num = { 2147483640,2147483641 };
	vector<int> num = {0}; // { 7, 6, 4, 3, 1 };
	string a = "32";

	Solution_017 sol;
	vector<string> ans = sol.letterCombinations(a);
	//cout << "ans: " << ans << endl;

	for (int i = 0; i < ans.size(); i++) {
		for (int j = 0; j < ans[0].size(); j++) {
			cout << ans[i][j] << " ";
		}
		cout << endl;
	}

	return 0;
}
*/