#include<bits/stdc++.h>
using namespace std;

#define rep(i,x,n) for(int i=x;i<n;i++)
#define f first
#define s second

typedef long long ll;
typedef pair<int, int> pi;

const int INF = 1e9;

ll a[100001], v[100001];
ll le,ri,ret,c;
void solve(){
	
	int n;cin>>n;
	
	rep(i,0,n){
		cin>>v[i];
	}
	
	for(;ri<n;ri++){
		
		if(a[v[ri]]==0){
			a[v[ri]]++;
			ret+=ri-le+1;
		}
		else{
			while(a[v[ri]]){
				a[v[le++]]--;
			}
			a[v[ri]]++;
			ret+=ri-le+1;
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
