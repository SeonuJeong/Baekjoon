#include<bits/stdc++.h>
using namespace std;
#define rep(i,x,n) for(int i=x;i<n;i++)
typedef tuple<int,int,int> ti;
vector<vector<int>> maps;
int M,N,T;
vector<ti> t;
int dy[4]={1,-1,0,0};
int dx[4]={0,0,1,-1};
void solve(){
	cin>>N>>M>>T;
	rep(i,0,N){
		maps.push_back(vector<int>(0));
		rep(j,0,M){
			int tmp; cin>>tmp;
			maps[i].push_back(tmp);
		}
	}
	rep(i,0,T){
		int x,d,k;
		cin>>x>>d>>k;
		t.push_back(make_tuple(x,d,k));
	}
	rep(i,0,T){
		int x,d,k; tie(x,d,k)=t[i];
		
		if(d==0) k=(M-k);
		k=k%M;
	
		for(int j=x;j<=N;j+=x)
			rotate(maps[j-1].begin(),maps[j-1].begin()+k,maps[j-1].end());
	
		int sum=0;
		
		rep(r,0,N)
			rep(c,0,M)
				sum+=max(maps[r][c],0);
		
		if(sum==0) break;
		
		bool isSame=false;
		vector<vector<int>> mm(N,vector<int>(M,0));
		rep(r,0,N)
			rep(c,0,M)
				if(maps[r][c]){
					rep(k,0,4){
						int nr=r+dy[k];
						int nc=c+dx[k];		
						if(nc<0) nc=M+nc;
						else if(nc>=M) nc=nc-M;
										
						if(nr<0||nr>=N) continue;						
						if(maps[r][c]==maps[nr][nc]){
							mm[r][c]=1;mm[nr][nc]=1;isSame=true;
						}
					}
				}
		
		rep(r,0,N)
			rep(c,0,M)
				if(mm[r][c]) maps[r][c]=0;
		if(isSame) continue;
		int cnt=0;
		sum=0;
		rep(r,0,N)
			rep(c,0,M)
				if(maps[r][c]){
					sum+=maps[r][c]; cnt++;	
				}		
		int mean=sum/cnt;	
		rep(r,0,N)
			rep(c,0,M){
				if(maps[r][c]==0) continue;
				if(sum%cnt==0&&mean==maps[r][c]) continue;
				
				if(mean<maps[r][c]) maps[r][c]--;
				else maps[r][c]++;
			}
	}
	int ret=0;
	rep(r,0,N)
		rep(c,0,M)
			ret+=maps[r][c];
	cout<<ret;	
}
int main() {
	ios_base::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
	solve();
}