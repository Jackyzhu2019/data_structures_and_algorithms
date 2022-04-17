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

class Solution_064 {
public:
	int minPathSum(vector<vector<int>>& grid) {
		int ans = 0;
		int m = grid.size();
		int n = grid[0].size();

		int i, j;

		for (i = 0; i < m; i++) {
			for (j = 0; j < n; j++) {
				if (i-1<0 && j-1<0)
					grid[i][j] = grid[i][j];

				if (i - 1 >= 0 && j - 1 < 0)
					grid[i][j] += grid[i-1][j];

				if (i - 1 < 0 && j - 1 >= 0)
					grid[i][j] += grid[i][j-1];

				if (i - 1 >= 0 && j - 1 >= 0)
					grid[i][j] += min(grid[i][j - 1], grid[i-1][j]);

			}
		}

		ans = grid[m-1][n-1];

		return ans;
	}
};

/*
int main() {
	cout << "!!!Hello World!!!" << endl; // prints !!!Hello World!!!

	//vector<int> num = { 2147483640,2147483641 };
	vector<int> num = {0}; // { 7, 6, 4, 3, 1 };
	string a = "abaabcbb";
	vector<vector<int>> num2D = {
		{1,3,1} , {1,5,1}, {4,2,1}
								};

	Solution_064 sol;
	int ans = sol.minPathSum(num2D);
	cout << "ans: " << ans << endl;

	//for (int i = 0; i< ans.size(); i++)
	//	cout << ans[i][0] << " " << ans[i][1] << endl;

	return 0;
}
*/