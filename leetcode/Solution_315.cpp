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

class Solution_316 {
public:
	string removeDuplicateLetters(string s) {
		int size = s.size();
		int i;
		int occu[26] = {0};
		int inStack[26] = { 0 }; // whether char in stack


		for (i = 0; i < size; i++) {
			occu[s[i] - 'a']++;
			//occu1[s[i] - 'a']++;
		}
			
		stack<char> ans;
		i = 0;

		while (i<size) {
			if (ans.empty()) {
				ans.emplace(s[i]);
				occu[s[i] - 'a']--;
				inStack[s[i] - 'a'] = 1;
				i++;
			}
			else {
				char top = ans.top();
				if (s[i] < top && occu[top - 'a'] > 0 && inStack[s[i] - 'a'] == 0) {
					ans.pop();
					inStack[top - 'a'] = 0;

				}
				else if (inStack[s[i] - 'a'] == 1) {
					occu[s[i] - 'a']--;
					i++;
				}else 
				{
					ans.emplace(s[i]);
					inStack[s[i] - 'a'] = 1;
					occu[s[i] - 'a']--;
					i++;
				}
			}
		}
		
		int stlen = ans.size();
		string str(stlen, 'c');

		for (i = 0; i < stlen; i++) {
			str[stlen - i - 1] = ans.top();
			ans.pop();
		}
	

		return str;
	}
};

/*
int main() {
	cout << "!!!Hello World!!!" << endl; // prints !!!Hello World!!!

	string a = "bbcaac";


	Solution_316 sol;
	string ans = sol.removeDuplicateLetters(a);

	cout << ans << endl;
	//for (int i = 0; i < ans.size(); i++)
	//	cout << ans[i] << endl;

	return 0;
}
*/