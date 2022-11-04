#include<bits/stdc++.h>
using namespace std;

#define rep(i,x,n) for(int i=x;i<n;i++)
#define f first
#define s second

typedef long long ll;
typedef pair<int, int> pi;
typedef tuple<int,int,int> ti;
const int INF = 1e9;
// 세로 대각 가로 0 1 2 
int stt[4]={0,0,1,1};
int dy[4]={1,0,1,1};
int dx[4]={0,1,1,1};
int N;
int m[17][17];
int dp[17][17][17][17];
bool check(int y,int x,int state){
	
	
	if(stt[state]==1){
		if(y+1>N||x+1>N||m[y+1][x+1]) return false;
		if(y+1>N||x>N||m[y+1][x]) return false;
		if(y>N||x+1>N||m[y][x+1]) return false;
	}
	else{
		if(y+dy[state]>N||x+dx[state]>N||m[y+dy[state]][x+dx[state]]) return false;
	}
		
		
	return true;
}

int go(int ly,int lx,int ry,int rx){
	
	if(ry==N&&rx==N){
		return 1;
	}
	
	int& ret=dp[ly][lx][ry][rx];
	
	if(ret!=-1)
		return ret;
	
	int s,dif;
	
	if(ly!=ry&&lx!=rx){
		s=2;dif=-1;
	}
	else{
		s=ly==ry?1:0;
		dif=2;
	}
	int cnt=0;
	
	if(check(ry,rx,s)){
		//cout<<"GET IN1 "<<s<<"\n";
		cnt+=go(ly+dy[s],lx+dx[s],ry+dy[s],rx+dx[s]);
	}
	int t=s+dif;
	
	while(t>=0&&t<4){
		if(check(ry,rx,t)){
			//cout<<"GET IN2\n";
			cnt+=go(ly+dy[s],lx+dx[s],ry+dy[t],rx+dx[t]);
		}
		t+=dif;
	}
	
	ret=cnt;
	return cnt;
}

void solve(){
	
	cin>>N;
	memset(dp,-1,sizeof(dp));
	rep(i,1,N+1)
		rep(j,1,N+1)
			cin>>m[i][j];
			
	cout<<go(1,1,1,2);
}

int main() {

	ios_base::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);

	solve();
}
