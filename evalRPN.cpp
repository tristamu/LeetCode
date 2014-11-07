/*************************************************************************
  > File Name: evalRPN.cpp
  > Author: Haoming Wang
  > Mail: haoming.exe@gmail.com
  > Created Time: Fri 07 Nov 2014 12:57:39 AM CET
  > url : https://oj.leetcode.com/problems/evaluate-reverse-polish-notation/

description:
Evaluate the value of an arithmetic expression in Reverse Polish Notation.

Valid operators are +, -, *, /. Each operand may be an integer or another expression.

Some examples:
  ["2", "1", "+", "3", "*"] -> ((2 + 1) * 3) -> 9
  ["4", "13", "5", "/", "+"] -> (4 + (13 / 5)) -> 6
 ************************************************************************/

#include<iostream>
#include<vector>
#include<string>
#include<stack>

using namespace std;

//Reverse Polish Notation
int evalRPN(vector<string> &tokens) {
    int size = tokens.size();
    stack<int> nums;
    for (int i = 0; i < size; i++) {
	string x = tokens[i];
	if ((x == "+") || (x == "-") || (x == "*") || (x == "/")) {
	    int a = nums.top();
	    nums.pop();
	    int b = nums.top();
	    nums.pop();

	    switch (x[0]) {
		case '+':
		    nums.push(b + a);
		    break;
		case '-':
		    nums.push(b - a);
		    break;
		case '*':
		    nums.push(b * a);
		    break;
		case '/':
		    nums.push(b / a);
		    break;
	    }

	} else {
	    int n = x[0]-'0';
	    //int n;
	    //istringstream(x) >> n;
	    nums.push(n);

	}
    }

    return nums.top();
}

int main() {
    string a[] = {"2", "1", "+", "3", "*"};
    int size=sizeof(a)/sizeof(string);

    vector<string> num(a,a+size);
    cout << evalRPN(num) << endl;
    return 0;

}
