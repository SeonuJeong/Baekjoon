#include<bits/stdc++.h>
using namespace std;

#define rep(i,x,n) for(int i=x;i<n;i++)
#define f first
#define s second

typedef long long ll;
typedef pair<int, int> pi;
typedef tuple<int,int,int> ti;
const int INF = 1e9;


int n;
vector<pi> v;
vector<pi> xv;
vector<pi> yv;

void solve(){
	cin>>n;
	
	rep(i,0,n){
		int x,y; cin>>x>>y;
		v.push_back({x,y});
	}
	
	
	rep(i,1,n){
		if(v[i-1].f==v[i].f){
			yv.push_back({min(v[i-1].s,v[i].s),max(v[i-1].s,v[i].s)});
		}
		else{
			xv.push_back({min(v[i-1].f,v[i].f),max(v[i-1].f,v[i].f)});
		}
	}
	
	if(v[0].f==v[n-1].f){
		yv.push_back({min(v[0].s,v[n-1].s),max(v[0].s,v[n-1].s)});
	}
	else{
		xv.push_back({min(v[0].f,v[n-1].f),max(v[0].f,v[n-1].f)});
	}
		
	
	//minheap
	priority_queue<int,vector<int>,greater<int>> pq;
	
	int ret=1;
	sort(xv.begin(),xv.end());
	pq.push(xv[0].s);
	rep(i,1,xv.size()){
		
		while(!pq.empty()&&pq.top()<=xv[i].f){
			pq.pop();
		}
		
		pq.push(xv[i].s);
		
		int tmp=pq.size();
		ret=max(ret, tmp);
	}
	
	while(!pq.empty())
		pq.pop();
	
	
	sort(yv.begin(),yv.end());
	pq.push(yv[0].s);
	rep(i,1,yv.size()){
		
		while(!pq.empty()&&pq.top()<=yv[i].f){
			pq.pop();
		}
		
		pq.push(yv[i].s);
		
		int tmp=pq.size();
		ret=max(ret,tmp);
	}

	cout<<ret;
}

int main() {

	ios_base::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);

	solve();
}
