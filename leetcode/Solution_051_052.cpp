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

class Solution_051_052 {
public:
#define MAX_N 9
	vector<vector<string>> ans;
	vector<pair <int, int>> path;
	vector<string> singlePath;
	int ansNum;

	void dfs(int n, int curRow) {
		int i;
		int len = path.size();
		int row, col;

		if (len == n) {
			string a(n, '.');
			for (i = 0; i < n; i++) {
				col = path[i].second;
				a[col] = 'Q';

				singlePath.push_back(a);
				a[col] = '.';
			}


			ansNum++;
			ans.push_back(singlePath);
			singlePath.clear();
			return;
		}

		int conflict[MAX_N] = {0};
		for (i = 0; i < len; i++) {
			row = path[i].first;
			col = path[i].second;
			
			conflict[col] = 1;

			if ((col + (curRow - row)) < n) {
				conflict[col + (curRow - row)] = 1;
			}

			if ((col - (curRow - row)) >= 0) {
				conflict[col - (curRow - row)] = 1;
			}
		}





		for (i = 0; i < n; i++) {
			if (conflict[i] == 0) {
				path.push_back(make_pair(len, i));

				dfs(n, len + 1);

				path.pop_back();

			}
		}
	}


	vector<vector<string>> solveNQueens(int n) {

		dfs(n, 0);

		return ans;
	}
	


	 int totalNQueens(int n) {
		 ansNum = 0;
		 dfs(n, 0);

		 return ansNum;
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

	Solution_051_052 sol;
	vector<vector<string>> ans = sol.solveNQueens(4);
	int ans1 = sol.totalNQueens(4);

	cout << ans1 << endl;

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