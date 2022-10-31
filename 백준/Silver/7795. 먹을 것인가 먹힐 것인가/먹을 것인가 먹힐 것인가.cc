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
int a[20001];
vector<int> b;

void solve(){
	cin>>N>>M;
	
	memset(a,0,sizeof(a));
	b.clear();
	
	rep(i,0,N)
		cin>>a[i];
		
	rep(i,0,M){
		int c;cin>>c;
		b.push_back(c);
	}
		
		
	sort(b.begin(),b.end());
	
	int sum=0;
	rep(i,0,N){
	
		int lo=0,hi=M-1;
		int ret=0;
		while(lo<=hi){
			int mid=(lo+hi)/2;
			
			if(b[mid]<a[i]){
				lo=mid+1;
				ret=max(ret,mid+1);
			}
			else{
				hi=mid-1;
			}
		}
		
		sum+=ret;
	}
	
	cout<<sum<<"\n";
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
