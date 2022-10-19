#include<bits/stdc++.h>
using namespace std;

#define rep(i,x,n) for(int i=x;i<n;i++)
#define f first
#define s second

typedef long long ll;
typedef pair<int, int> pi;

const int INF = 1e9;

int n,k,l;
int m[101][101];
int c[101][101];
queue<pair<int,char>> ro;
queue<pi> que;
int t;

int dy[4]={0,-1,0,1};
int dx[4]={-1,0,1,0};
int d=2;

void solve(){
	cin>>n>>k;
	memset(m,0,sizeof(m));
	memset(c,0,sizeof(m));
	rep(i,0,k){
		int r,c;cin>>r>>c;
		m[r-1][c-1]=1;
	}
	
	cin>>l;
	
	rep(i,0,l){
		int x;char c;
		cin>>x>>c;
		ro.push({x,c});
	}
	
	//
	
	que.push({0,0});
	c[0][0]=1;
	
	while(1){
		
		int ny = que.back().f+dy[d];
		int nx = que.back().s+dx[d];
		
		t++;
		
		if(ny<0||ny>=n||nx<0||nx>=n) break;
		
		if(c[ny][nx]) break;
		
		if(m[ny][nx]){
			m[ny][nx]=0;
			que.push({ny,nx});
			c[ny][nx]=1;
		}
		else{
			que.push({ny,nx});
			c[ny][nx]=1;
			
			c[que.front().f][que.front().s]=0;
			que.pop();
		}
		
		while(!ro.empty()&&ro.front().f==t){
			if(ro.front().s=='L')
				d = (d+3)%4;
			else
				d = (d+1)%4;
			
			ro.pop();
		}
	}
	
	cout<<t;
	
}



int main() {

	ios_base::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);

	solve();
}
