#include<bits/stdc++.h>
using namespace std;
int main(){
string s,tmp;
cin>>s;
tmp=s;
reverse(s.begin(),s.end());
cout<<(s==tmp?1:0);}