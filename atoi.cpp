/*************************************************************************
	> File Name: atoi.cpp
	> Author: Haoming Wang
	> Mail: haoming.exe@gmail.com
	> Created Time: Wed 05 Nov 2014 02:47:25 AM CET
	> url: https://oj.leetcode.com/problems/string-to-integer-atoi/
 ************************************************************************/

#include<iostream>
#include <climits>
#include <string.h>

using namespace std;

int atoi(const char *str) {
	int res = 0,sign=1,i=0,increm=0;
	int len=strlen(str);
	if(str == NULL)
		return 0;
	while (str[i] == ' ' && i < len)
		i++; //skip while spaces
	if (str[i] == '+'){
		i++;
		sign+=increm;
		increm++;
	}
	if (str[i] == '-') {
		sign = -1;
		sign+=increm;
		i++;
	}
	while (str[i] != 0) {
		if (str[i] < '0' || str[i] > '9')
			break;
		if (INT_MAX / 10 < res
				|| (INT_MAX / 10 == res && INT_MAX % 10 < (str[i] - '0')) ) {
			return (sign == -1) ? INT_MIN : INT_MAX;
		}
		res = 10 * res + str[i] - '0';
		//cout << str[i]<< " res= "<< res <<endl;
		i++;

	}
	return res * sign;

}

int main(){
    const char *a = "+-123";
    cout << atoi(a) << endl;

    return 0;
}

