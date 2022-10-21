#include<bits/stdc++.h>
using namespace std;

#define rep(i,x,n) for(int i=x;i<n;i++)
#define f first
#define s second

typedef long long ll;
typedef pair<int, int> pi;
typedef tuple<int,int,int> ti;
const int INF = 1e9;

int n,l;
vector<pi> v;

void solve(){
	
	cin>>n>>l;
	
	rep(i,0,n){
		int s,e;cin>>s>>e;
		v.push_back({s,-e});
	}
	
	sort(v.begin(),v.end());
	
	int end=-1,cnt=0;
	rep(i,0,n){
		
		int s,e;tie(s,e)=v[i];
		e=-e;
		if(end>=(e-1)) continue;
		
		int len = e-max(end+1,s);
		
		int tmp = len/l;
		if(len%l!=0) tmp++;
		cnt+=tmp;
		end=max(end+1,s)+l*tmp-1;
	}
	
	cout<<cnt;
	
}

int main() {

	ios_base::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);

	solve();
}
