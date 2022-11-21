#include<bits/stdc++.h>
using namespace std;

#define rep(i,x,n) for(int i=x;i<n;i++)
#define f first
#define s second

typedef long long ll;
typedef pair<int, int> pi;
typedef tuple<int,int,int> ti;
const int INF = 1e9;

int N,M,T,D;
int maps[26][26];
int dist[26][26];
int dy[4]={1,0,-1,0};
int dx[4]={0,1,0,-1};
void solve(){
	cin>>N>>M>>T>>D;
	fill(&dist[0][0],&dist[0][0]+26*26,INF);
	rep(i,0,N){
		string s;cin>>s;
		
		rep(j,0,M){
			if(s[j]<='Z')
				maps[i][j]=s[j]-'A';
			else
				maps[i][j]=s[j]-'a'+26;
		}
	}
	
//	cout<<"\n";
//	rep(i,0,N){
//		rep(j,0,M){
//			cout<<maps[i][j]<<" ";
//		}
//		cout<<"\n";
//	}
	
	priority_queue<ti> pq;
	pq.push(make_tuple(0,0,0));
	dist[0][0]=0;
	while(pq.size()){
		int y,x,here_dist;tie(here_dist,y,x)=pq.top(); pq.pop();
		
		if(dist[y][x]!=here_dist)
			continue;
		
		rep(i,0,4){
			int ny=y+dy[i];
			int nx=x+dx[i];
			
			if(ny<0||ny>=N||nx<0||nx>=M) continue;
			if(abs(maps[y][x]-maps[ny][nx])>T) continue;
			
			int next_dist=1;
			if(maps[y][x]<maps[ny][nx]) 
				next_dist=abs(maps[ny][nx]-maps[y][x])*abs(maps[ny][nx]-maps[y][x]);
				
			if(dist[ny][nx]>here_dist+next_dist){
				dist[ny][nx]=here_dist+next_dist;
				pq.push(make_tuple(dist[ny][nx],ny,nx));
			}
		}
	}
	
//	cout<<"\n";
//	rep(i,0,N){
//		rep(j,0,M){
//			cout<<dist[i][j]<<" ";
//		}
//		cout<<"\n";
//	}
	
	int ret=0;
	priority_queue<ti,vector<ti>,less<ti>> pq2;
	rep(i,0,N)
		rep(j,0,M){
			pq2.push(make_tuple(maps[i][j],i,j));
		}
	
	
	
	while(pq2.size()){
			
		int i,j,val; tie(val,i,j)=pq2.top(); pq2.pop();
		
		if(dist[i][j]+(i+j)>D) continue;
		
		int dist2[26][26];
		fill(&dist2[0][0],&dist2[0][0]+26*26,INF);
		pq.push(make_tuple(0,i,j));
		dist2[i][j]=0;
		
		while(pq.size()){
			int y,x,here_dist;tie(here_dist,y,x)=pq.top(); pq.pop();
			
			if(dist2[y][x]!=here_dist)
				continue;
			
			rep(i,0,4){
				int ny=y+dy[i];
				int nx=x+dx[i];
				
				if(ny<0||ny>=N||nx<0||nx>=M) continue;
				if(abs(maps[y][x]-maps[ny][nx])>T) continue;
				
				int next_dist=1;
				if(maps[y][x]<maps[ny][nx]) 
					next_dist=abs(maps[ny][nx]-maps[y][x])*abs(maps[ny][nx]-maps[y][x]);
					
				if(dist2[ny][nx]>here_dist+next_dist){
					dist2[ny][nx]=here_dist+next_dist;
					pq.push(make_tuple(dist2[ny][nx],ny,nx));
				}
			}
		}
//				cout<<"\n";
//				rep(i,0,N){
//					rep(j,0,M){
//						cout<<dist2[i][j]<<" ";
//					}
//					cout<<"\n";
//				}
//		
		
		if(dist[i][j]+dist2[0][0]<=D){
			ret=val;
			break;
		}
	}
	
	cout<<ret;
}

int main() {

	ios_base::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);

	solve();
}
