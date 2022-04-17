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

class Solution_332 {
public:
#define MAX_N 9
	vector<string> ans;
	vector<pair <int, int>> path;
	vector<string> singlePath;
	
	vector<string> findItinerary(vector<vector<string>>& tickets) {


		return ans;
	}

};


int main() {
	cout << "!!!Hello World!!!" << endl; // prints !!!Hello World!!!

	//vector<int> num = { 2147483640,2147483641 };
	vector<int> num = { 0 }; // { 7, 6, 4, 3, 1 };
	string a = "abbac";
	vector<string> str = { "leet", "code", "leet" };
	vector<vector<int>> num2D = {
		{1,3,1} , {1,5,1}, {4,2,1}
	};


	vector<vector<string>> tickets = { {"MUC","LHR" }, { "JFK","MUC" }, { "SFO","SJC" }, { "LHR","SFO" } };

	Solution_332 sol;
	vector<string> ans = sol.findItinerary(tickets);

	//cout << "ans: " << ans << endl;
	for (int i = 0; i < ans.size(); i++) {
		cout << ans[i] << endl;
	}

	return 0;
}