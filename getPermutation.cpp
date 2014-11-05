/*************************************************************************
  > File Name: getPermutation.cpp
  > Author: Haoming Wang
  > Mail: haoming.exe@gmail.com
  > Created Time: Wed 05 Nov 2014 02:51:36 AM CET
  > url: https://oj.leetcode.com/problems/permutation-sequence/

Description:
The set [1,2,3,…,n] contains a total of n! unique permutations.

By listing and labeling all of the permutations in order,
We get the following sequence (ie, for n = 3):

"123"
"132"
"213"
"231"
"312"
"321"
Given n and k, return the kth permutation sequence.

Note: Given n will be between 1 and 9 inclusive.

 ************************************************************************/

#include<iostream>
#include<string>
#include<vector>
#include <sstream>

using namespace std;

string getPermutation(int n, int k) {
    vector<int> num;
    int total = 1;
    for (int i = 1; i <= n; i++) {
	num.push_back(i);
	total *= i;
    }

    //invalid k;
    if (total < k)
	return "";
    int index, group = total;
    stringstream ss;
    while(n>0){
	group = group/n;
	index = (k-1)/group;
	k=(k-1)%group+1;
	ss << num[index];
	num.erase(num.begin()+index);
	n--;

    }
    return ss.str();
}

int main(){
    cout << getPermutation(3,3) << endl;
    return 0;
}
