#include<bits/stdc++.h>
using namespace std;

#define rep(i,x,n) for(int i=x;i<n;i++)
#define f first
#define s second

typedef long long ll;
typedef pair<int, int> pi;
typedef tuple<int,int,int> ti;
const int INF = 1e9;

int N;
vector<pi> v;
void solve(){
	cin>>N;
	rep(i,0,N){
		int l,r;cin>>l>>r;
		v.push_back({l,r});
	}
	
	sort(v.begin(),v.end());
	
	int len=0;
	int le=v[0].f,ri=v[0].s;
	for(int i=1;i<v.size();i++){
		
		if(v[i].s<=ri) continue;
		
		if(v[i].f<=ri&&v[i].s>ri)
			ri=v[i].s;
		else if(v[i].f>ri){
			len+=ri-le;
			le=v[i].f; ri=v[i].s;
		}
	}
	
	len+=ri-le;
	
	cout<<len;
}

int main() {

	ios_base::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);

	solve();
}
