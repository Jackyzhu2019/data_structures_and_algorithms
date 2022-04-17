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

using namespace std;

class Solution_218 {
public:
	struct cmp {
		bool operator()(vector<int>& a, vector<int>& b) {
			if (a[0] == b[0]) return a[1] > b[1];
			return a[0] < b[0];
		}
	};

	vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
		vector<vector<int>> ans;
		vector<vector<int>> lines;
		vector<int> aux, aux1;

		int num = buildings.size();
		int i, j, k;

		for (i = 0; i < num; i++) {
			aux  = { buildings[i][0], buildings[i][2] };
			aux1 = { buildings[i][1], -buildings[i][2] };
			lines.emplace_back(aux);
			lines.emplace_back(aux1);
		}

		// sort by x-axis
		sort(lines.begin(), lines.end(), cmp());

		//priority_queue<int, vector<int>, less<int>> lineQue;
		multiset<int> lineQue({ 0 });
		int len = lines.size();
		//lineQue.emplace(0);


		for (int i = 0; i < len; i++) {
			int top = *lineQue.rbegin();
			
			// rising edge
			if (lines[i][1] > 0) {
				lineQue.emplace(lines[i][1]);

				if (lines[i][1] > top) {
					aux = { lines[i][0], lines[i][1] };
					ans.emplace_back(aux);
				}			
			}

			// falling edge
			if (lines[i][1] < 0) {
				int temp = -lines[i][1];
				lineQue.erase(lineQue.find(temp));

				if (temp >= top) {
					top = *lineQue.rbegin();
					
					if (temp > top) {
						aux = { lines[i][0], top };
						ans.emplace_back(aux);
					}
				}
			
			}
		}

		return ans;

	}

};

/*
int main() {
	cout << "!!!Hello World!!!" << endl; // prints !!!Hello World!!!

	vector<int> num = {3,2,1,5,6,4};
	string a = "abcabcbb";
	vector<vector<int>> num2D = {
								  { 0,2,3},
								  { 2,5,3}
								};

	Solution_218 sol;
	vector<vector<int>> ans = sol.getSkyline(num2D);
	cout << "ans: " << endl;

	for (int i = 0; i< ans.size(); i++)
		cout << ans[i][0] << " " << ans[i][1] << endl;

	return 0;
}
*/