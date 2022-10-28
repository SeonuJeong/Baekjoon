#include<bits/stdc++.h>
using namespace std;

#define rep(i,x,n) for(int i=x;i<n;i++)
#define f first
#define s second

typedef long long ll;
typedef pair<int, int> pi;
typedef tuple<int,int,int> ti;
const int INF = 1e9;

int N,M;
int v[100001];

bool check(ll mid){
	
	int cnt=0;
	int sum=0;
	rep(i,0,N){
		if(mid<v[i]) return false;
		
		sum+=v[i];
		
		if(sum>mid){
			cnt++;
			sum=v[i];
		}
	}
	
	cnt++;
	
	return cnt<=M;
}

void solve(){
	cin>>N>>M;
	
	ll lo=1,hi=0;
	rep(i,0,N){
		cin>>v[i];
		hi+=v[i];
	} 
	
	ll ret=1e18;
	while(lo<=hi){
		ll mid=(hi+lo)/2;
		
		if(check(mid)){
			ret=min(ret,mid);
			hi=mid-1;
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
