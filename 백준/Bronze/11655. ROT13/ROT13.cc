#include<bits/stdc++.h>
using namespace std;

#define ll long long
const int INF = 1e9;


void solve(){

	string s;
	getline(cin,s);
	
	for(int i=0; i<s.length(); i++){
		bool isSpace = s[i]==' ';
		bool isNum = s[i]>='0'&&s[i]<='9';
		if(isSpace||isNum) continue;
		
		char c;
		if(isupper(s[i])) c='A';
		else c='a';
		
		s[i] = (((s[i]-c)+13)%26)+c;
	}
	
	cout<<s;
}



int main() {

	ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);

	int t,i=1;
//	cin>>t;
//	while(t--){
//		//cout<<"Case #"<<i<<": ";
//		solve();
//		i++;
//	}

	solve();
	return 0;
}
