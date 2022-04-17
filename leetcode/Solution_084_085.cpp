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

class Solution__084_085 {
public:

	int largestRectangleArea(vector<int>& heights) {
		int n = heights.size();
		int i;
		stack<pair<int, int>> st;
		int ans = 0;
		int temp;
		pair<int, int> top;

		for (i = 0; i < n; i++) {
			if (st.empty()) {
				if (heights[i] != 0) {
					st.push({ heights[i], 1 });
					ans = max(ans, heights[i]);
				}
			}
			else {
				top = st.top();
				if (heights[i] > top.first) {
					top.first = heights[i];
					top.second = 1;

					st.push(top);
				}
				else {
					temp = 0;
					while (!st.empty() && heights[i] <= top.first)
					{
						ans = max(ans, top.first * (top.second + temp));
						temp += (top.second);
						st.pop();
						if (st.empty()) {
							break;
						}
						top = st.top();
					}

					if (heights[i] != 0) {
						st.push({ heights[i], temp + 1 });
					}
				}
			}
		}

		temp = 0;
		while (!st.empty()) {
			top = st.top();
			ans = max(ans, top.first * (top.second + temp));
			temp += (top.second);
			st.pop();
		}

		return ans;
	}


    int maximalRectangle(vector<vector<char>>& matrix) {
		int ans = 0;
		int m = matrix.size();
		int n = matrix[0].size();

		vector<vector<int>> grid(m, vector<int>(n, 0));
		vector<int> heights(n);

		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				if (matrix[i][j] == '1') {
					grid[i][j] = 1 ;
				}
				if (matrix[i][j] == '0') {
					grid[i][j] = 0;
				}
			}
		}


		for (int i = 0; i < m; i++) {
			if (i > 0) {
				for (int j = 0; j < n; j++) {
					if (grid[i][j] == 1){
						grid[i][j] += grid[i - 1][j];
					}
				}
			}

			heights = grid[i];

			
			ans = max(ans, largestRectangleArea(heights));
		}

		return ans;
	}
};

/*
int main() {
	cout << "!!!Hello World!!!" << endl; // prints !!!Hello World!!!

	//vector<int> num = { 2147483640,2147483641 };
	vector<int> num = { 1, 1 };
	string a = "abaabcbb";
	vector<vector<int>> num2D = {
		{1,3,1} , {1,5,1}, {4,2,1}
								};

	vector<vector<char>> numc2D = { {'1','0','1','0','0'},{'1','0','1','1','1'},{'1','1','1','1','1'},{'1','0','0','1','0'} };


	Solution__084_085 sol;
	int ans = sol.largestRectangleArea(num);
	cout << "ans: " << ans << endl;

	ans = sol.maximalRectangle(numc2D);
	cout << "ans: " << ans << endl;


	//for (int i = 0; i< ans.size(); i++)
	//	cout << ans[i][0] << " " << ans[i][1] << endl;

	return 0;
}
*/