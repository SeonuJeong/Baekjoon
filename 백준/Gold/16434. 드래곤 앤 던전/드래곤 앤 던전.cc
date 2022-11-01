#include<bits/stdc++.h>
using namespace std;

#define rep(i,x,n) for(int i=x;i<n;i++)
#define f first
#define s second

typedef long long ll;
typedef pair<int, int> pi;
typedef tuple<int,int,int> ti;
const int INF = 1e9;

int N,ATK;
vector<tuple<ll,ll,ll>> r;

bool check(ll val){
	ll curHP=val;
	ll atk=ATK;
	rep(i,0,N){
		ll t,a,h; tie(t,a,h)=r[i];
		
		if(t==2){
			curHP = min(val,curHP+h);
			atk += a;
			continue;
		}
		
		if(atk>=h) continue;
		
		ll f=h/atk;
		
		if(h%atk==0)
			f--;	
		
		curHP -= a*f;
		
		if(curHP<=0) return false;
	}
	
	return true;
}

void solve(){
	cin>>N>>ATK;
	
	ll lo=1,hi=1;
	
	rep(i,0,N){
		ll t,a,h; cin>>t>>a>>h;
		r.push_back(make_tuple(t,a,h));
		
		if(t==2) continue;
		
		hi+=a*(h/ATK);
	}
	
	ll ret=1e18;
	while(lo<=hi){
		ll mid=(lo+hi)/2;
		
		if(check(mid)){
			hi=mid-1;
			ret=min(ret,mid);
		}
		else
			lo=mid+1;
		
	}
	
	cout<<ret;
	
}

int main() {

	ios_base::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);

	solve();
}
