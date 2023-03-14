#include<bits/stdc++.h>
using namespace std;

#define rep(i,x,n) for(int i=x;i<n;i++)
#define f first
#define s second

typedef long long ll;
typedef pair<int, int> pi;
typedef tuple<int,int,int> ti;
const int INF = 1e9;

ll A,B,C;

ll go(ll a,ll b){
	
	if(b==0)
		return 1;
	
	
	if(b%2)
		return (go(a,b-1)*a)%C;
	else{
		ll ret = go(a,b/2)%C;
		return (ret*ret)%C;
	}
		
}

void solve(){
	
	cin>>A>>B>>C;
	
	
	cout<<go(A,B)<<"\n";
	
}

int main() {

	ios_base::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);

	solve();
}
