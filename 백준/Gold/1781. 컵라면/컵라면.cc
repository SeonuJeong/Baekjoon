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
	priority_queue<int,vector<int>,greater<int>> pq;
	vector<pi> v;
	rep(i,0,n){
		int d,c;cin>>d>>c;
		v.push_back({d,c});
	}
	sort(v.begin(),v.end());
	
	rep(i,0,n){
		int d,c;tie(d,c)=v[i];
		
		pq.push(c);
		
		if(pq.size()>d)
			pq.pop();	
	}
	
	int res=0;
	
	while(pq.size()){
		res+=pq.top();pq.pop();
	}
	
	cout<<res;
}


int main() {

	ios_base::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);

	solve();
}
