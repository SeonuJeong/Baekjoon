#include<bits/stdc++.h>
using namespace std;

#define rep(i,x,n) for(int i=x;i<n;i++)
#define f first
#define s second

typedef long long ll;
typedef pair<int, int> pi;
typedef tuple<int,int,int> ti;
const int INF = 2e9+1;


void solve(){
	int N;
	cin>>N;
	vector<int> v(N,0);
	
	rep(i,0,N)
		cin>>v[i];
		
	sort(v.begin(),v.end());
	
	int retVal=INF;
	int ret1,ret2;
	rep(i,0,N){
		int val=v[i];
		int le=i+1;
		int ri=N-1;
		
		while(le<=ri){
			int mid=(le+ri)/2;
			//cout<<val<<" "<<v[mid]<<"\n";
			if(retVal>abs(val+v[mid])){
				retVal=abs(val+v[mid]);
				ret1=val;
				ret2=v[mid];
			}
			
			if(val+v[mid]<=0){
				le=mid+1;					
			}
			else {
				ri=mid-1;
			}
		}
	}
	
	
	if(ret1<ret2)
		cout<<ret1<<" "<<ret2;
	else
		cout<<ret2<<" "<<ret1;
	
}

int main() {

	ios_base::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);

	solve();
}
