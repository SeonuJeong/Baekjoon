#include<bits/stdc++.h>
using namespace std;

#define rep(i,x,n) for(int i=x;i<n;i++)
#define f first
#define s second

typedef long long ll;
typedef pair<int, int> pi;
typedef tuple<int,int,int> ti;
const int INF = 1e9;

struct Dragon{
	int x,y,d,g;
};
Dragon dr[21];
int N;
int dy[4]={0,-1,0,1};
int dx[4]={1,0,-1,0};
int maps[101][101];

int sy[3]={1,1,0};
int sx[3]={1,0,1};

void solve(){
	cin>>N;
	
	rep(i,0,N){
		int x,y,d,g;
		cin>>x>>y>>d>>g;
		dr[i].x=x; dr[i].y=y; dr[i].d=d; dr[i].g=g;
	}
	
	rep(i,0,N){
		
		vector<int> rout;
		int r,c,dir;
		
		// g==0은 그냥 하기 
		r=dr[i].y; c=dr[i].x; dir=dr[i].d;
		maps[r][c]=1;
		
		r+=dy[dir]; c+=dx[dir];
		maps[r][c]=1;
		
		rout.push_back(dir);
		
		
		//g>=1 이상일 때 
		rep(j,0,dr[i].g){
			
			//새루트 생성 
			vector<int> newr;
			
			for(int k=rout.size()-1;k>=0;k--)
				newr.push_back( (rout[k]+1)%4 );
			
			//새 루트 이동
			rep(k,0,newr.size()){
				//새루트 추가 
				rout.push_back(newr[k]);
				
				r+=dy[newr[k]];
				c+=dx[newr[k]];
				
				maps[r][c]=1;
			} 
			
		}
		
	}
	

	
	//사각형 찾기 
	int R=101,C=101; 
	
	int cnt=0;
	rep(i,0,R)
		rep(j,0,C)
			if(maps[i][j]==1){
				bool isOK=true;
				rep(k,0,3){
					int ny=i+sy[k];
					int nx=j+sx[k];
					
					if(ny<0||ny>=R||nx<0||nx>=C||!maps[ny][nx])
						isOK=false;
				}
				
				if(isOK) cnt++;
			}
	
	
	cout<<cnt;	
	
}

int main() {

	ios_base::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);

	solve();
}
