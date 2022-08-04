#include<bits/stdc++.h>
using namespace std;

#define rep(i,x,n) for(int i=x;i<n;i++)
#define f first
#define s second

typedef long long ll;
typedef pair<int, int> pi;

const int INF = 1e9;

int M;
int state=0;
void calcu(int v,string s){
	if(s=="add"){
		state|=(1<<v);
	}
	else if(s=="remove"){
		state&=~(1<<v);
	}
	else if(s=="check"){
		
		if(state&(1<<v)) cout<<"1\n";
		else cout<<"0\n";
	}
	else if(s=="toggle"){
		state^=(1<<v);
	}
	else if(s=="all"){
		state|=~(1<<21);
	}
	else if(s=="empty"){
		state&=(1<<21);
	}
}

void solve(){
	cin>>M;
	
	rep(i,0,M){
		string s;cin>>s;
		if(s=="all"||s=="empty"){
			calcu(0,s);
			continue;
		}
			
			
		int n;cin>>n;
			calcu(n,s);
	}
}

int main() {

	ios_base::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);

solve();
}
