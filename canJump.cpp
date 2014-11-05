/*************************************************************************
	> File Name: canJump.cpp
	> Author: Haoming Wang
	> Mail: haoming.exe@gmail.com
	> Created Time: Wed 05 Nov 2014 05:24:02 PM CET
	> url: https://oj.leetcode.com/problems/jump-game/

Description:
Given an array of non-negative integers, you are initially positioned at the first index of the array.

Each element in the array represents your maximum jump length at that position.

Determine if you are able to reach the last index.

For example:
A = [2,3,1,1,4], return true.

A = [3,2,1,0,4], return false.
 ************************************************************************/

#include<iostream>
using namespace std;

bool canJump(int A[], int n) {
	int i=n-2,pos=n-1;
	while(i>=0){
		if(A[i]>=(pos-i)){
			pos=i;
		}
		i--;
	}
	if(pos==0)
		return true;
	else
		return false;
}

int main() {
	int a[] = {0,0,3};
	int size=sizeof(a)/sizeof(int);
	cout << canJump(a,size) << endl;
	return 0;
}
