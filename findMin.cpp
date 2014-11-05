/*************************************************************************
  > File Name: findMin.cpp
  > Author: Haoming Wang
  > Mail: haoming.exe@gmail.com
  > Created Time: Wed 05 Nov 2014 05:38:39 PM CET
url: https://oj.leetcode.com/problems/find-minimum-in-rotated-sorted-array-ii/
Description:
    Suppose a sorted array is rotated at some pivot unknown to you beforehand.

    (i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).

    Find the minimum element.

    The array may contain duplicates.
 ************************************************************************/

#include<iostream>
#include<string>
#include<vector>
using namespace std;

int findMin(vector<int> &num) {
    int left = 0, right = num.size() - 1;
    int mid;

    if (num[0] < num[right]) //not rotated
	return num[0];
    else {
	while (left != right) {
	    mid = (left + right) / 2; //lower mid
	    if (num[mid] > num[right])
		left = mid + 1;
	    else
		right = mid;
	}
	return num[left];
    }
}

int findMinIIv1(vector<int> &num) {
    int left = 0, right = num.size() - 1;
    int mid;


    if (num[0] < num[right]) //not rotated
	return num[0];
    else {
	while (left != right) {
	    mid = (left + right) / 2; //lower mid
	    //cout << left << endl;
	    if (num[mid] > num[right])
		left = mid + 1;
	    else if (num[mid] == num[right]) {
		if(num[mid]==num[mid-1])
		    left = mid + 1;
		else
		    right = mid;
	    } else
		right = mid;
	}
	return num[left];
    }

}

int findMinIIv2(vector<int> &A) {
    int L = 0, R = A.size() - 1;
    while (L < R && A[L] >= A[R]) {
	int M = (L + R) / 2;
	if (A[M] > A[R]) {
	    L = M + 1;
	} else if (A[M] < A[L]) {
	    R = M;
	} else {   // A[L] == A[M] == A[R]
	    L = L + 1;
	}
    }
    return A[L];
}

int main(){
    int a[] = {1,2,3,4,5};
    int size = sizeof(a)/sizeof(int);
    vector<int> num(a,a+size);
    cout << findMinIIv1(num) << endl;
    return 0;
}
