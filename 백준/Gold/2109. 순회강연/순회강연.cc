#include<bits/stdc++.h>
using namespace std;

#define rep(i,x,n) for(int i=x;i<n;i++)
#define f first
#define s second

typedef long long ll;
typedef pair<int, int> pi;

const int INF = 1e9;


vector<pi> v;
void solve(){
	int n;cin>>n;
	
	rep(i,0,n){
		int d,p; cin>>p>>d;
		v.push_back({d,p});
	}
	
	sort(v.begin(), v.end());
	
	priority_queue<int,vector<int>,greater<int>> pq;
	
	rep(i,0,n){
		int td,tp; tie(td,tp)=v[i];
		
		pq.push(tp);
		
		if(pq.size()>td){
			pq.pop();
		}
	}
	
	int result=0;
	while(pq.size()>0){
		result += pq.top(); pq.pop();
	}
	
	cout<<result;
}

int main() {

	ios_base::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);

	solve();
}
