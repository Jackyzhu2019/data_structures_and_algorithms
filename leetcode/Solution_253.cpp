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

class Solution_253 {
public:
	struct cmp {
		bool operator()(vector<int>& a, vector<int>& b) {
			if (a[0] == b[0]) return a[1] < b[1];
			return a[0] < b[0];
		}
	};

	int minMeetingRooms(vector<vector<int>>& intervals) {
		int ans = 0;
		int top;
		int len = intervals.size();
		sort(intervals.begin(), intervals.end(), cmp());

		priority_queue<int, vector<int>, greater<int>> endtime_queue;
		for (int i = 0; i < len; i++) {
			int starttime = intervals[i][0];
			int endtime   = intervals[i][1];
			
			while (!endtime_queue.empty()) {
				top = endtime_queue.top();
				if (top > starttime) {
					endtime_queue.emplace(endtime);
					break;
				}
				else {
					endtime_queue.pop();
				}

			}

			if (endtime_queue.empty())
				endtime_queue.emplace(endtime);

			ans = ans > endtime_queue.size() ? ans : endtime_queue.size();
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
								  { 3, 20 }, 
								  { 5, 15 },
								  { 16, 30 }
								};

	Solution_253 sol;
	int ans = sol.minMeetingRooms(num2D);

	cout << "ans: " << ans << endl;

	return 0;
}
*/