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

class Solution_077_216 {
public:
	vector <vector <int>> ans;
	vector<int> path;
	
	
	void dfs(int s, int e, int k) {
		if (path.size() == k) {
			ans.push_back(path);
			//path.pop_back();
			return;
		}

		for (int i = s; i <= e; i++) {
			path.push_back(i);
			dfs(i+1, e, k);
			path.pop_back();
		}
	}


	vector<vector<int>> combine(int n, int k) {
		int i, j;

		dfs(1, n, k);

		return ans;
	}

	void dfsSum(int s, int n, int k) {
		if (path.size() == k) {
			int sum = 0;
			for (auto it = path.begin(); it != path.end(); it++) {
				sum += *(it);
			}
			if (sum == n)
				ans.push_back(path);
			//path.pop_back();
			return;
		}

		for (int i = s; i <= 9; i++) {
			path.push_back(i);
			dfsSum(i + 1, n, k);
			path.pop_back();
		}
	}

	vector<vector<int>> combinationSum3(int k, int n) {
		int maxK = 0;
		int minK = 0;
		int i;

		if (k > n) {
			return ans; 
		}

		for (i = 9; i > (9 - k); i--) {
			maxK += i;
		}

		for (i = 1; i < (k+1); i++) {
			minK += i;
		}

		if (n < minK || n > maxK)
			return ans;


		dfsSum(1, n, k);


		return ans;
	}



	void dfsSum2(int s, int n, vector<int>& candidates) {
		if (0 == n){
			ans.push_back(path);
			return;
		} 

		if (n < 0)
			return;


		int prev = 100;

		for (int i = s; i < candidates.size(); i++) {
			if (prev != candidates[i]) {
				path.push_back(candidates[i]);
				dfsSum2(i + 1, n - candidates[i], candidates);
				path.pop_back();
			}
			prev = candidates[i];
		}
	}

	vector<vector<int>> combinationSum2(vector<int>& candidates, int n) {
		sort(candidates.begin(), candidates.end());

		dfsSum2(0, n, candidates);

		return ans;
	}
};

/*
int main() {
	cout << "!!!Hello World!!!" << endl; // prints !!!Hello World!!!

	//vector<int> num = { 2147483640,2147483641 };
	vector<int> num = { 10,1,2,7,6,1,5 };
	string a = "leetcode";
	vector<string> str = { "leet", "code", "leet" };
	vector<vector<int>> num2D = {
		{1,3,1} , {1,5,1}, {4,2,1}
								};

	Solution_077_216 sol;
	vector<vector<int>> ans = sol.combinationSum2(num, 8);
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