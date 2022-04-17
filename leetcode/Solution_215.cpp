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
#include "string.h"
#include "stdlib.h"

using namespace std;

class Solution_215 {
public:
	int findKthLargest(vector<int>& nums, int k) {
		int ans = 0;
		int i, j;
		int len = nums.size();
		priority_queue <int, vector<int>, less<int>> Kheap;
		
		if (len < k)
			return 0;

		for (i = 0; i < k; i++) {
			Kheap.emplace(nums[i]);
		}

		for (i = k; i < len; i++) {
			int temp = Kheap.top();

			if (temp > nums[i]) {
				Kheap.pop();
				Kheap.emplace(nums[i]);
			}

		}

		ans = Kheap.top();



		return ans;
	}

};

/*
int main() {
	cout << "!!!Hello World!!!" << endl; // prints !!!Hello World!!!

	vector<int> num = {3,2,1,5,6,4};
	string a = "abcabcbb";

	Solution_215 sol;
	int ans = sol.findKthLargest(num, 2);


	cout << "ans: " << ans << endl;

	return 0;
}
*/