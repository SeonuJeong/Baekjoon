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
int maps[9][9];
int dirs[9][9];
int ret=INF;
int C;//CCTV 개수 

int dy[4]={-1,0,1,0};
int dx[4]={0,1,0,-1};
vector<vector<int>> rotates;

vector<pi> cs;

void go(int idx){
	if(idx==C){
		
		/*cctv */
		int tmp[9][9];	
		memcpy(tmp,maps,sizeof(maps));
		
		rep(i,0,cs.size()){
			int y,x; tie(y,x)=cs[i];
			int dir=dirs[y][x];
			int type=maps[y][x]-1;
			
			rep(j,0,rotates[type].size()){
				int r=y,c=x;
				
				while(1){
					int nr=r+dy[(dir+rotates[type][j])%4];
					int nc=c+dx[(dir+rotates[type][j])%4];
					
					if(nr<0||nr>=N||nc<0||nc>=M||maps[nr][nc]==6) break;
					
					tmp[nr][nc]=-1;
					r=nr;c=nc;
				}
			}
		}
		
		/*사각지대 크기*/
		int cnt=0;
		rep(i,0,N)
			rep(j,0,M)
				if(tmp[i][j]==0) cnt++;
			
		ret=min(ret,cnt);
	
		return;
	}
	
	int y,x; tie(y,x)=cs[idx];
	
	rep(i,0,4){
		dirs[y][x]=i;
		go(idx+1);
	}
}

void solve(){
	cin>>N>>M;
	rotates={{0},{0,2},{0,1},{0,3,1},{0,1,2,3}};
	rep(i,0,N)
		rep(j,0,M){
			cin>>maps[i][j];
			if(maps[i][j]&&maps[i][j]!=6)
				cs.push_back({i,j});
		}

	C=cs.size();
	
	go(0);
	
	cout<<ret;
}

int main() {

	ios_base::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);

	solve();
}
