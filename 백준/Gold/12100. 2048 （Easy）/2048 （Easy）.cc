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
int m[21][21];

//{0,n-1,0,0}
int init_pos_y[4]={0,};
//{0,0,0,n-1}
int init_pos_x[4]={0,};

int next_step_y[4]={0,0,1,1};
int next_step_x[4]={1,1,0,0};

int dy[4] = {1,-1,0,0};
int dx[4] = {0,0,1,-1};

int result=0;

void go(int index){
	
	if(index==5)
		return;
		
	int tmp[21][21];
	memset(tmp,0,sizeof(tmp));
	memcpy(tmp,m,sizeof(m));
	
	rep(i,0,4){
		
		memcpy(m,tmp,sizeof(tmp));
		
		int initY=init_pos_y[i];
		int initX=init_pos_x[i];
		
		int rm[21][21];
		memset(rm,0,sizeof(rm));
		

		rep(t,0,N){
			
			int y=initY; int x=initX;
			
			vector<int> st; 
			if(m[y][x]!=0) st.push_back(m[y][x]);
			
			vector<int> ret; 
			
			rep(j,0,N-1){
				int ny=y+dy[i];
				int nx=x+dx[i];
				
				
				y=ny; x=nx;
				if(m[ny][nx]==0)
					continue;
				
				if(!st.empty()&&st.back()==m[ny][nx]){
                    ret.push_back(m[ny][nx]*2);
                    st.pop_back();
                }
                else if(!st.empty()&&st.back()!=m[ny][nx]){
                    ret.push_back(st.back());
                    st.pop_back();
                    st.push_back(m[ny][nx]);
                }
                else{
                	
                    st.push_back(m[ny][nx]);
                }

			}
		
			while(!st.empty()){
				
				ret.push_back(st.back());
				st.pop_back();
			}
            
            y=initY; x=initX;
            rep(j,0,ret.size()){
                rm[y][x]=ret[j];
                result=max(rm[y][x],result);
                y = y+dy[i];
                x = x+dx[i];
            }
            

            initY+=next_step_y[i];
            initX+=next_step_x[i];
		}

        	
		memcpy(m,rm,sizeof(rm));
		go(index+1);
	}
}


void solve(){
	cin>>N;
	
	init_pos_y[1]=N-1;
	init_pos_x[3]=N-1;
	
	rep(i,0,N)
		rep(j,0,N)
			cin>>m[i][j];
	
	rep(i,0,N)
		rep(j,0,N)
			result=max(result,m[i][j]);
	
	go(0);
	
	cout<<result;
}

int main() {

	ios_base::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);

	solve();
}
