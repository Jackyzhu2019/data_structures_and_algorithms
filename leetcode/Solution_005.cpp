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

class Solution_005 {
public:
	string longestPalindrome(string s) {
		int len = s.size();
		int len1 = 2 * len + 1;
		int i, j, k;
		string s1(2 * len + 1, '#');
		int ans_left, ans_right;
		int max = 0;

		/* manacher algo */
		// normalize odd/even
		for (i = 0; i < len; i++) {
			s1[2 * i + 1] = s[i];
		}

		vector<int> status(len1);
		status[0] = 1;
		status[1] = 2;

		int right_max = 2;
		int mid_max = 1;

		max = 2;
		ans_left = 0;
		ans_right = 2;

		for (i = 2; i < len1; i++) {
			if (i > right_max) {
				j = i - 1;
				k = i + 1;
				right_max = i;
				mid_max = i;
				status[i] = 1;
				while (j >= 0 && k <= len1 - 1) {
					if (s1[j] == s1[k]) {
						right_max = k;
						j--;
						k++;
						status[i]++;
					}
					else {
						break;
					}
				}
			}
			else {
				status[i] = status[2 * mid_max - i];
				if ((i + status[i] - 1)>= right_max) {
					status[i] = right_max - i + 1;

					j = i - status[i];
					k = i + status[i];
					mid_max = i;

					while (j >= 0 && k <= len1) {
						if (s1[j] == s1[k]) {
							right_max = k;
							j--;
							k++;
							status[i]++;
						}
						else {
							break;
						}
					}
				}
			}

			if (status[i] > max) {
				ans_left  = mid_max - status[i] + 1;
				ans_right = mid_max + status[i] - 1;
				max = status[i];
			}
		}


		string ans(s1.begin() + ans_left, s1.begin() + ans_right + 1);

		ans.erase(remove(ans.begin(), ans.end(), '#'), ans.end()); //remove A from string


		return ans;
	}
};

/*
int main() {
	cout << "!!!Hello World!!!" << endl; // prints !!!Hello World!!!

	//vector<int> num = { 2147483640,2147483641 };
	vector<int> num = { 1, 2 };
	string a = "abaabcbb";
	vector<vector<int>> num2D = {
								  { 2,2,-1}//,
								 // { 0,-2,3}
								};

	Solution_005 sol;
	string ans = sol.longestPalindrome(a);
	cout << "ans: " << ans << endl;

	//for (int i = 0; i< ans.size(); i++)
	//	cout << ans[i][0] << " " << ans[i][1] << endl;

	return 0;
}
*/