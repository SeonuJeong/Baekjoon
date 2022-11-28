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
vector<int> v;

bool cal(int mid){
	
	int cnt=0;
	rep(i,0,v.size()){
		cnt+=v[i]/mid;
		
		if(v[i]%mid)
			cnt++;
	}
	
	return cnt<=N;
}

void solve(){
	cin>>N>>M;
	v.resize(M);
	int le=1,ri=1;
	rep(i,0,M){
		cin>>v[i];
		ri=max(ri,v[i]);
	}
	
	
	int ret=INF;
	while(le<=ri){
		int mid=(le+ri)/2;
		
		if(cal(mid)){
			ret=min(ret,mid);
			ri=mid-1;
		}
		else{
			le=mid+1;
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
