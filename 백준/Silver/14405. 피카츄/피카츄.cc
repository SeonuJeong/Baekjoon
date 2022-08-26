#include<bits/stdc++.h>
using namespace std;

#define rep(i,x,n) for(int i=x;i<n;i++)
#define f first
#define s second

typedef long long ll;
typedef pair<int, int> pi;

const int INF = 1e9;


void solve(){
	string s;cin>>s;
	
	int le=0;
	bool error=false;
	while(le<s.length()){
		string tmp;
		if(s[le]=='p'){
			tmp = s.substr(le,2);
			
			if(tmp!="pi")
				error=true;
			else
				le+=2;
		}
		else if(s[le]=='k'){
			tmp = s.substr(le,2);
			
			if(tmp!="ka")
				error=true;
			else
				le+=2;
		}
		else if(s[le]=='c'){
			tmp = s.substr(le,3);
			
			if(tmp!="chu")
				error=true;
			else
				le+=3;
		}
		else{
			error=true;
		}
		if(error) break;
	}
	
	if(error) cout<<"NO";
	else cout<<"YES";
}



int main() {

	ios_base::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);

//	int t;
//	cin>>t;
//	while(t--){
//		//cout<<"Case #"<<i<<": ";
//		solve();
//	}
solve();
}
