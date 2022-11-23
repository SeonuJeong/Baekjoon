#include<bits/stdc++.h>
using namespace std;

#define rep(i,x,n) for(int i=x;i<n;i++)
#define f first
#define s second

typedef long long ll;
typedef pair<int, int> pi;
typedef tuple<int,int,int> ti;
const int INF = 1e9;

int N,k;
vector<pi> v;
priority_queue<ti,vector<ti>,greater<ti>> minheap;
priority_queue<ti,vector<ti>,greater<ti>> pq;
void solve(){
	cin>>N>>k;
	
	rep(i,0,N){
		int id,w; cin>>id>>w;
		v.push_back({id,w});
	}

	for(int i=0;i<N&&i<k;i++)
		minheap.push(make_tuple(v[i].s,i+1,v[i].f));
	
	ll ret=0;
	int cnt=1;
	rep(i,k,N){
		int w,id,kth;
		tie(w,kth,id)=minheap.top();
		minheap.pop();
		
		minheap.push(make_tuple(w+v[i].s, kth,v[i].f));
		pq.push(make_tuple(w,-kth,id));
	}
	
	while(minheap.size()){
		int w,id,kth;
		tie(w,kth,id)=minheap.top();
		minheap.pop();
		pq.push(make_tuple(w,-kth,id));
	}
	
	while(pq.size()){
		int w,id,kth;
		tie(w,kth,id)=pq.top();
		pq.pop();
		ret+=1L*cnt*id;
		cnt++;
	}
	
	cout<<ret;
}

int main() {

	ios_base::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);

	solve();
}
