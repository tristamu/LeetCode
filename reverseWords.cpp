/*************************************************************************
	> File Name: reverseWords.cpp
	> Author: Haoming Wang
	> Mail:
	> Created Time: Wed 05 Nov 2014 02:24:41 AM CET
> url: 	https://oj.leetcode.com/problems/reverse-words-in-a-string/
 ************************************************************************/

#include<iostream>
#include<string>
using namespace std;

void reverseWords(string &s) {
	int size = s.size();
	int cnt = 0;
	string str;

	string::iterator fin = s.end();
	for (int i = size - 1; i >= 0; i--) {
		if (s[i] != ' ') {
			cnt++;
		} else {
			//cout << cnt << endl;
			str.append(fin - cnt, fin);
			if (cnt != 0 )
				str.append(" ");
			fin -= (cnt + 1);
			cnt = 0;
		}
	}
	if(cnt!=0)
		str.append(fin-cnt,fin);
	else
		str = str.substr(0,str.size()-1); //eliminate the last space

	//cout << "size = "<<str.size() << endl;
	s = str;
}

void reverseWordsV2(string &s) {
        string word; //tmp string to store each word
        string res; // result string
        int i=0;
        while (i<s.size()){
            if (char(s[i])==' ' && word.empty()){i++;continue;} //multiple spaces
            if (char(s[i])==' ' && !word.empty()){ //first space after a word
                res = word+" "+ res; //store the word
                word=""; //reset the word
                i++; continue;
            }
	    //non-space chars
            if (char(s[i])!=' '){word=word+char(s[i]);i++; continue;}
        }

        if (!word.empty()){ //last word
            s = word+" "+res;
        }else{
            s = res;
        }
        s = s.substr(0,s.size()-1); //eliminate the last space

}


int main() {
	string s="the sky is blue";
	reverseWords(s);
	cout << s << endl;
	return 0;
}
