/*************************************************************************
  > File Name: maxProduct.cpp
  > Author: Haoming Wang
  > Mail:
  > Created Time: Tue 04 Nov 2014 11:24:58 PM CET
  > url: https://oj.leetcode.com/problems/maximum-product-subarray/
Description:
Find the contiguous subarray within an array (containing at least one number) which has the largest product.

For example, given the array [2,3,-2,4],
the contiguous subarray [2,3] has the largest product = 6.
 *************************************************************************
 My thoughts:
 we have to consider the sign. so if product is negative, we have odd number of negatives; then the max product is the bigger of:

 a) product of all excluding elements on the left, up to the first negative element.

 b) product of all excluding elements on the right, up to the last negative element.

 so the solution is calculate product, first from left to right, then from right to left; during the process we are guaranteed to encounter the max product; and whenever 0 is encountered, reset product to 1 and continue.
ps: odd negtive numbers can be considered as 1

 ************************************************************************/

#include<iostream>
#include <climits>

using namespace std;


int maxProduct(int A[], int n) {
    int b=1, f=1, res=INT_MIN;
    for(int i=0; i<n; i++){
	res=max(res, max(b*=A[i],f*=A[n-1-i]));
	if(b==0) b=1; if(f==0) f=1;
    }
    return res;
}

int main() {
    int a[] = {-1,3,-2,-2,4};
    int size=sizeof(a)/sizeof(int);
    cout << "max product: "<<maxProduct(a,size) << endl;
    return 0;

}
