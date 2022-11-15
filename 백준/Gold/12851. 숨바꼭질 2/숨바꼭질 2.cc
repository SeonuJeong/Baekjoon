#include<bits/stdc++.h>
using namespace std;

#define rep(i,x,n) for(int i=x;i<n;i++)
#define f first
#define s second

typedef long long ll;
typedef pair<int, int> pi;
typedef tuple<int,int,int> ti;
const int INF = 1e9;

int N,K;
int visited[200001];
void solve(){
	cin>>N>>K;
	
	queue<int> que;
	que.push(N);
	visited[N];
	fill(&visited[0],&visited[200000],INF);
	int time=0;
	int cnt=0;
	while(!que.empty()){
		int s=que.size();
		while(s--){
			
			int cur=que.front();que.pop();
			//cout<<cur<<"\n";
			
			if(cur==K)
				cnt++;
				
			if(cur-1>=0&&visited[cur-1]>=time){
				que.push(cur-1);
				visited[cur-1]=time;
			}
				
				
			if(cur+1<=100000&&visited[cur+1]>=time){
				que.push(cur+1);
				visited[cur+1]=time;
			}
				
			
			if(cur*2<=200000&&visited[cur*2]>=time){
				que.push(cur*2);
				visited[cur*2]=time;
			}
		}
		//cout<<"\\\\\n";
		if(cnt)
			break;
			
		time++;
	}
	
	cout<<time<<"\n"<<cnt;
	
}

int main() {

	ios_base::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);

	solve();
}
