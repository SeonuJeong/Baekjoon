#include<bits/stdc++.h>
using namespace std;

#define rep(i,x,n) for(int i=x;i<n;i++)
#define f first
#define s second

typedef long long ll;
typedef pair<int, int> pi;
typedef tuple<int,int,int> ti;
const int INF = 1e9;

int a[9];
void solve(){
	
	rep(i,0,9)
		cin>>a[i];
	
	sort(a,a+9);
		
	do{
		int sum=0;
		
		rep(i,0,7) sum+=a[i];
		
		if(sum==100) break;
	}while(next_permutation(a,a+9));
	
	rep(i,0,7)
		cout<<a[i]<<"\n";
	
	
	
}

int main() {

	ios_base::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);

	solve();
}
