#include<bits/stdc++.h>
using namespace std;

#define rep(i,x,n) for(int i=x;i<n;i++)
#define f first
#define s second

typedef long long ll;
typedef pair<int, int> pi;
typedef tuple<int,int,int> ti;
const int INF = 1e9;

int S,C;
ll ret=0;
vector<ll> v(1000001);
 
bool check(ll mid){
	
	ll cnt=0;
	rep(i,0,S){
		cnt+=v[i]/mid;
	}	
	
	return cnt>=C;
}
void solve(){
	cin>>S>>C;
	ll sum=0;
	rep(i,0,S)
		cin>>v[i],sum+=v[i];
	
	ll lo=1,hi=1000000004;
	
	
	while(lo<=hi){
		ll mid=(lo+hi)/2;
		
		if(check(mid)){
			ret=max(ret,mid);
			lo=mid+1;
		}
		else hi=mid-1;
	}
	
//	ll output=0;
//	
//	rep(i,0,S){
//		output+=v[i]%ret;	
//	}
	cout<<sum-ret*C;
}

int main() {

	ios_base::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);

	solve();
}
