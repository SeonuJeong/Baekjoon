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
vector<int> hp;
vector<int> ej;


int go(int h,int pos){
	//cout<<"h: "<<h<<" pos: "<<pos<<"\n";
	if(h<=0){
		return 0;
	}
	
	int val=0;
	rep(i,pos+1,N){
		if(h<=hp[i]) continue;
		
		val=max(val,go(h-hp[i],i)+ej[i]);
	}
	
	return val;
}

void solve(){
	cin>>N;
	
	rep(i,0,N){
		int c;cin>>c;
		hp.push_back(c);
	}
	
	rep(i,0,N){
		int c;cin>>c;
		ej.push_back(c);
	}
	
	cout<<go(100,-1);
}

int main() {

	ios_base::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);

	solve();
}
