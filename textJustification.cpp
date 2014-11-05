/*************************************************************************
	> File Name: textJustification.cpp
	> Author: Haoming Wang
	> Mail: haoming.exe@gmail.com
	> Created Time: Tue 04 Nov 2014 01:49:38 AM CET
	> url: https://oj.leetcode.com/problems/text-justification/
 ************************************************************************/

#include<iostream>
#include<vector>
#include<string>
using namespace std;

void addSpace(string &s, int count)
    {
        for(int i = 1; i <= count; i++)
            s.push_back(' ');
    }


vector<string> fullJustify(vector<string> &words, int L) {
	vector<string> res;
	int i = 0, len = words.size();


	while (i < len) { //reshape all the words
		int cnt = 0,j = i;
		while (j < len && (cnt + words[j].size()) <= L)
			cnt += (words[j++].size()+1); //number of letters with space
		if(j-i==1) {
			res.push_back(words[i]);
			addSpace(res.back(),L-words[i].size());
			i=j;continue;
		}
		int num=cnt-(j-i); //j-i words
		int meanSpace = j<len?(L-num)/(j-i-1):1;
		int leftSpace = j<len?(L-num)%(j-i-1):L-num-(j-i-1);

		string str;
		for(int k=i;k<j-1;k++){
			str+=words[k];
			addSpace(str,meanSpace);
			if(j<len && leftSpace>0){
				str.push_back(' ');
				leftSpace--;
			}
		}
		str+=words[j-1]; // add the last word
		if(leftSpace>0)
			addSpace(str,leftSpace);
		res.push_back(str);
		i=j;
	}
	return res;
}




int main() {
	string ss[]={"This", "is", "an", "example", "of", "text", "justification."};
	vector<string> words(ss,ss+7);

	vector<string> res = fullJustify(words,16);
	int size=res.size();
	//cout << size;
	for(int i=0;i<size;i++)
		cout << res[i]<<" len= "<<  res[i].size() << endl;

	return 0;

}
