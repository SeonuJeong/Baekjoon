#include<bits/stdc++.h>
using namespace std;

#define rep(i,x,n) for(int i=x;i<n;i++)
#define f first
#define s second

typedef long long ll;
typedef pair<int, int> pi;
typedef tuple<int,int,int> ti;
const int INF = 1e9;


void solve(){
	
	string s;
	getline(cin,s);
	
	if(s[0]==' ')
		s.erase(0,1);
		
	if(s[s.size()-1]==' ')
		s.erase(s.size()-1,1);
	
	if(s.size()==0){
		cout<<"0";
		return;
	}
		
		
	int cnt=1;
	
	rep(i,0,s.size())
		if(s[i]==' ')
			cnt++;
	
	cout<<cnt;
}

int main() {

	solve();
}
