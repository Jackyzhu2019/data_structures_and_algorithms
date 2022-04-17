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
//#include <hash_map>
#include <stack>
#include "string.h"
#include "stdlib.h"

using namespace std;

class Solution_003 {
public:

	int lengthOfLongestSubstring(string s) {
		int len = s.size();
		int temp = 0;
		int max = 0;
		unordered_map<char, int> unMap;
		int start = 0;

		for (int i = 0; i < len; i++) {
			auto it = unMap.find(s[i]);
			if (it != unMap.end()) {
				int idx = it->second;

				auto it_begin = unMap.begin();
				
				while (start <= idx) {
					unMap.erase(s[start++]);
				}

				temp = (i - idx);
			}
			else {
				temp++;
			}

			unMap[s[i]] = i;

			max = (max > temp) ? max : temp;
		}


		return max;
	}

};

/*
int main() {
	cout << "!!!Hello World!!!" << endl; // prints !!!Hello World!!!

	vector<int> num = { 2, 7, 11, 15 };
	string a = "abcabcbb";

	Solution_003 sol;
	int ans = sol.lengthOfLongestSubstring(a);


	cout << "ans: " << ans << endl;

	return 0;
}
*/