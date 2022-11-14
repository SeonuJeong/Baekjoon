#include<bits/stdc++.h>
using namespace std;

#define rep(i,x,n) for(int i=x;i<n;i++)
#define f first
#define s second

typedef long long ll;
typedef pair<int, int> pi;
typedef tuple<int,int,int> ti;
const int INF = 1e9;


void solve(){
	ll N;cin>>N;
	
	ll cnt=0;
	
	for(int i=5;i<=N;i=i*5){
		cnt+=N/i;
	}
	
	
	cout<<cnt<<"\n";	
}

int main() {

	ios_base::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);

	int t;
	cin>>t;
	while(t--){
		//cout<<"Case #"<<i<<": ";
		solve();
	}
}
