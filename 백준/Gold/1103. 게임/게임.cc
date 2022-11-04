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
char m[51][51];
int visited[51][51];

int dy[4]={0,1,0,-1};
int dx[4]={1,0,-1,0};

int dp[51][51];

int go (int y,int x){
	
	//cout<<"y: "<<y<<" x: "<<x<<"\n";
	if(y<0||y>=N||x<0||x>=M) return 0;
	
	if(visited[y][x]) return INF;
	
	if(m[y][x]=='H')	
		return 0;
	
	int &ret=dp[y][x];
	if(ret!=-1)
		return ret;
	
	
	visited[y][x]=1;
	
	int cnt=0;
	
	rep(i,0,4){
		int ny=y+(m[y][x]-'0')*dy[i];
		int nx=x+(m[y][x]-'0')*dx[i];	
		
		int ret=go(ny,nx);
	
		if(ret==INF){
			cnt=INF;break;
		}
		
		cnt=max(cnt,1+ret);
	}
	
	visited[y][x]=0;
	ret=cnt;
	
	return cnt;
	
}

void solve(){
	cin>>N>>M;
	memset(visited,0,sizeof(visited));
	memset(dp,-1,sizeof(dp));
	
	rep(i,0,N){
		string s;cin>>s;
		rep(j,0,s.length())
			m[i][j]=s[j];
	}
	
	int ret=go(0,0);
	
	cout<<(ret==INF?-1:ret);
		
}

int main() {

	ios_base::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);

	solve();
}
