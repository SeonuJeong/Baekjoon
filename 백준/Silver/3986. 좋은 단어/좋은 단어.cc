#include<bits/stdc++.h>
using namespace std;

#define ll long long
const int INF = 1e9;


void solve(){

	int N;
	cin>>N;
	
	int cnt=0;
	for(int i=0; i<N; i++){
		string s;
		cin>>s;
		
		vector<char> v;
		for(int j=0; j<s.length();j++){
			
			char c = s[j];
			
			if(v.empty())
				v.push_back(c);
			else if(v.back()!=c)
				v.push_back(c);
			else
				v.pop_back();
		}
		
		if(v.empty()) cnt++;
	}
	
	cout<<cnt<<"\n";
}



int main() {

	ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);

//	int t,i=1;
//	cin>>t;
//	while(t--){
//		//cout<<"Case #"<<i<<": ";
//		solve();
//		i++;
//	}
	solve();
}
