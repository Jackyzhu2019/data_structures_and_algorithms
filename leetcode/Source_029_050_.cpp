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

class Solution_029_050 {
public:
	double quickMul(double x, long long N) {
		if (N == 0) {
			return 1.0;
		}
		double y = quickMul(x, N / 2);
		return N % 2 == 0 ? y * y : y * y * x;
	}

	double myPow(double x, int n) {
		long long N = n;
		return N >= 0 ? quickMul(x, N) : 1.0 / quickMul(x, -N);
	}


    int binSearch(int& sum, int div) {
        if (sum < div) {
            return 0;
        }


        int iCnt = 1;
        int numRep = 1;
        int accu = div;
        sum = sum - div;

        if (div > (INT_MAX >> 1))
            return (sum >= 0) ? 1 : 0;


        while (sum >= 0 && accu <= (INT_MAX >> 1)) {
            accu += accu;
            sum = sum - accu;
            iCnt = iCnt + (1 << (numRep++));
        }

        //if (accu <= (INT_MAX >> 1)) {
            iCnt = iCnt >> 1;
            sum = sum + accu;
       // }

        iCnt += binSearch(sum, div);

        return iCnt;
    }



    int divide(int dividend, int divisor) {

        if (divisor == dividend){
            return 1;
        }

        if (divisor == INT_MIN) {
            return 0;
        }
        
        
        int absDividend = abs(dividend);
        int absDivisor = abs(divisor);




        int minInt = 0x80000000;
        if (dividend == minInt && divisor == -1) {
            return 0x7fffffff;
        }

        if (dividend == minInt && divisor == 1) {
            return 0x80000000;
        }

        int reminder = 0;
        if (dividend == minInt) {
            absDividend = 0x7fffffff;
            reminder = 1;
        }

        if (absDivisor > absDividend) {
            return 0;
        }

        if (divisor == -1 || divisor == 1)
            return dividend * divisor;

        if (divisor == -2 || divisor == 2)
            return (dividend >> 1) * (divisor >> 1);


        int iCnt = binSearch(absDividend, absDivisor);

        if (absDividend + reminder >= absDivisor)
            iCnt++;

        if ((dividend < 0 && divisor > 0) || (dividend > 0 && divisor < 0))
            iCnt *= -1;


        return iCnt;
    }

};

/*
int main() {
	cout << "!!!Hello World!!!" << endl; // prints !!!Hello World!!!

	//vector<int> num = { 2147483640,2147483641 };
	vector<int> num = {0}; // { 7, 6, 4, 3, 1 };
	string a = "abbac";
	vector<string> str = { "leet", "code", "leet" };
	vector<vector<int>> num2D = {
		{1,3,1} , {1,5,1}, {4,2,1}
								};

	Solution_029_050 sol;
	double ans = sol.myPow(8.66731, 4);

    int ans1 = sol.divide(1100540749, 
                         -1090366779);

	cout << "ans: " << ans1 << endl;

	return 0;
}
*/