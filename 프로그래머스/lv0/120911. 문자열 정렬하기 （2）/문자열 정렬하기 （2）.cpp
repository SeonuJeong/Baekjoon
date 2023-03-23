#include <bits/stdc++.h>

using namespace std;

string solution(string my_string) {
    string answer = "";
    
    for(char ch: my_string){
        if(ch>='A'&&ch<='Z')
            ch = 'a' + ch - 'A';
        answer+=ch;
    }
    
    sort(answer.begin(), answer.end());
    return answer;
}