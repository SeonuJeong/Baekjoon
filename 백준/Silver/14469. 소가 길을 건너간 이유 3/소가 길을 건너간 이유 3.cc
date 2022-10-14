#include<bits/stdc++.h>
using namespace std;

#define rep(i,x,n) for(int i=x;i<n;i++)
#define f first
#define s second

typedef long long ll;
typedef pair<int, int> pi;

const int INF = 1e9;


void solve(){
	int n;cin>>n;
	
	vector<pi> v;
	rep(i,0,n){
		int d,g; cin>>d>>g;
		
		v.push_back({d,-g});
	}
	
	sort(v.begin(),v.end());
	
	int last=0;
	ll res=0;
	rep(i,0,n){
		int d,g;tie(d,g)=v[i];
		g=abs(g);
		
		if(last<d){
			res+=d-last+g;
			last=d+g;
		}
		else{
			last=last+g;
			res+=g;
		}
	}
	
	cout<<res;
	
}

int main() {

	ios_base::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);

	solve();
}
