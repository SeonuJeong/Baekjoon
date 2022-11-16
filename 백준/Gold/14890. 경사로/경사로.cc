#include<bits/stdc++.h>
using namespace std;

#define rep(i,x,n) for(int i=x;i<n;i++)
#define f first
#define s second

typedef long long ll;
typedef pair<int, int> pi;

const int INF = 1e9;

int N,L;
int maps[100][100];
vector<int> v;

bool go(){
	vector<pi> p;
	
	int cnt=0;
	
	rep(i,0,N){
		cnt++;
		
		if(i==N-1){
			p.push_back({v[i],cnt});
			break;
		}
		
		if(v[i]!=v[i+1]){
			p.push_back({v[i],cnt});
			cnt=0;
		}
	}
	
	rep(i,0,p.size()-1){
		
		if(abs(p[i].f-p[i+1].f)>1) return false;
		
		if(p[i].f<p[i+1].f){
			p[i].s-=L;
			if(p[i].s<0) return false;
		}
		else{
			p[i+1].s-=L;
			if(p[i+1].s<0) return false;
		}
	}
	
	return true;
}

void solve(){
	cin>>N>>L;
	
	rep(i,0,N)
		rep(j,0,N)	
			cin>>maps[i][j];
	
	int cnt=0;
	
	rep(i,0,N){
		rep(j,0,N)
			v.push_back(maps[i][j]);
		
		
		if(go()) cnt++;
		
		v.clear();
	}
	
	rep(i,0,N){
		rep(j,0,N)
			v.push_back(maps[j][i]);
		
		
		if(go()) cnt++;
		
		v.clear();
	}
	
	cout<<cnt;
}

int main() {

	ios_base::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);

	solve();
}
