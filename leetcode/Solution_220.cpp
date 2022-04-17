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

class Solution_220 {
public:
	bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
		int len = nums.size();
		set<int> kset;
		int i;
		if (k == 0)
			return false;

		for (i = 0; i < len; i++) {
			auto it = kset.lower_bound(max(nums[i], INT_MIN + t) -t);

			if (it != kset.end() && (*it <= min(nums[i], INT_MAX - t) + t)) {
				return true;
			}
		
			if (kset.size() < k) {
				kset.insert(nums[i]);
			}
			else {
				kset.erase(nums[i - k]);
				kset.insert(nums[i]);
			}
		
		}

		return false;
	}

};

/*
int main() {
	cout << "!!!Hello World!!!" << endl; // prints !!!Hello World!!!

	//vector<int> num = { 2147483640,2147483641 };
	vector<int> num = { 1, 2 };
	string a = "abcabcbb";
	vector<vector<int>> num2D = {
								  { 0,2,3},
								  { 2,5,3}
								};

	Solution_220 sol;
	bool ans = sol.containsNearbyAlmostDuplicate(num, 0, 1);
	cout << "ans: " << ans << endl;

	//for (int i = 0; i< ans.size(); i++)
	//	cout << ans[i][0] << " " << ans[i][1] << endl;

	return 0;
}
*/