#include<bits/stdc++.h>
using namespace std;

#define rep(i,x,n) for(int i=x;i<n;i++)
#define f first
#define s second

typedef long long ll;
typedef pair<int, int> pi;
typedef tuple<int,int,int> ti;
const int INF = 1e9;

ll X,Y,Z;

ll go(ll x,ll y){
	return ((y*10)/x)*10+((y*10)%x)*10/x;
}

void solve(){
	cin>>X>>Y;
	
	Z=go(X,Y);
	
	ll lo=0,hi=0;
	
	if(Z==99){
		cout<<"-1";
		return ;
	}
	
	hi = (100*Y-(Z+1)*X)/(Z+1-100)+1;
	
	ll ret=1e18;
	while(lo<=hi){
		ll mid = (lo+hi)/2;
		
		if(go(X+mid,Y+mid)>Z){
			hi=mid-1;
			ret=min(ret,mid);
		}
		else
			lo=mid+1;
	}
	
	if(ret==(ll)1e18)
		cout<<"-1";
	else
		cout<<ret;
}

int main() {

	ios_base::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);

	solve();
}
