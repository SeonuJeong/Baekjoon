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
int dy[4]={1,0,-1,0};
int dx[4]={0,1,0,-1};
int dist[150][150];
int maps[150][150];
int visited[150][150];
int cnt=1;
int solve(){
	cin>>N;
	if(N==0)
		return 0;
		
	fill(&dist[0][0],&dist[0][0]+150*150,INF);
	memset(visited,0,sizeof(visited));
	rep(i,0,N)
		rep(j,0,N)
			cin>>maps[i][j];
			
	dist[0][0]=maps[0][0];
	
	for(int i=0;i<(N*N)-1;i++){
		int hy,hx,val=INF;
		
		rep(y,0,N)
			rep(x,0,N)
				if(val>dist[y][x]&&!visited[y][x]){
					val=dist[y][x];
					hy=y;
					hx=x;
				}
		
		//cout<<"hy: "<<hy<<" hx: "<<hx<<"\n";
		visited[hy][hx]=true;
		
		rep(y,0,N)
			rep(x,0,N){
				int d=INF;
				if(abs(y-hy)+abs(x-hx)==1)
					d=maps[y][x];
					
				if(visited[y][x]) continue;
				if(d==INF) continue;
				if(dist[y][x]>dist[hy][hx]+d)
					dist[y][x]=dist[hy][hx]+d;
			}
		
	}
	
	
//	rep(i,0,N){
//		rep(j,0,N)
//			cout<<dist[i][j]<<" ";
//		cout<<"\n"; 
//	}
		
	
	cout<<"Problem "<<cnt<<": "<<dist[N-1][N-1]<<"\n";
	cnt++;

	return 1;
}

int main() {

	ios_base::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);

	while(solve()){
		
	}
}
