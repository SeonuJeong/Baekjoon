#include<bits/stdc++.h>
using namespace std;

#define rep(i,x,n) for(int i=x;i<n;i++)
#define f first
#define s second

typedef long long ll;
typedef pair<int, int> pi;
typedef tuple<int,int,int> ti;
const int INF = 1e9;

int N,M,K;
vector<ll> v(1e6+1,0);

vector<ll> tree(1e6+1,0);

void update(ll idx, ll diff){
	while(idx<N+1){
		tree[idx]+=diff;
		idx+=(idx&-idx);
	}
}

ll sum(ll idx){
	ll ret=0;
	while(idx>0){
		ret+=tree[idx];
		idx-=(idx&-idx);
	}
	return ret;
}

void solve(){
	cin>>N>>M>>K;
	
	rep(i,0,N){
		cin>>v[i+1];
		update(i+1, v[i+1]);
	}
	
	ll a,b,c;
	rep(i,0,M+K){
		cin>>a>>b>>c;
		if(a==1){
			update(b,c-v[b]);
			v[b]=c;	
		}
		else if(a==2){
			cout<<(sum(c)-sum(b-1))<<"\n";
		}
	}
	
}

int main() {

	ios_base::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);

	solve();
}
