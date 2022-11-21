#include<bits/stdc++.h>
using namespace std;

#define rep(i,x,n) for(int i=x;i<n;i++)
#define f first
#define s second

typedef long long ll;
typedef pair<int, int> pi;
typedef tuple<int,int,int> ti;
const int INF = 1e9;
const ll MOD=1000000007;
vector<ll> sumTree,numTree;
int N; 
ll sumf(int idx){
	ll ret=0;
	
	while(idx>0){
		ret+=sumTree[idx];
		idx-=(idx&-idx);
	}	
	return ret;
}

ll cntf(int idx){
	ll ret=0;
	while(idx>0){
		ret+=numTree[idx];
		idx-=(idx&-idx);
	}
	return ret;
}

void updateSum(int idx,ll dif){
	while(idx<=200002){
		sumTree[idx]+=dif;
		idx+=(idx&-idx);
	}
}

void updateNum(int idx,ll dif){
	while(idx<=200002){
		numTree[idx]+=dif;
		idx+=(idx&-idx);
	}
}
void solve(){
	cin>>N;

	
	sumTree.resize(200003);	
	numTree.resize(200003);
	//cout<<sumTree[0]<<"\n";
	vector<int> v(N);
	
	rep(i,0,N){
		int c;cin>>c;
		v[i]=c+1;
	
	}
	
	updateSum(v[0],v[0]);
	updateNum(v[0],1);
	ll ret=1;
	rep(i,1,N){
		ll s=0;
		
		ll leftcnt=cntf(v[i]);
		ll rightcnt=cntf(200002)-leftcnt;
		ll leftsum=sumf(v[i]);
		ll rightsum=sumf(200002)-leftsum;
		
		s=(leftcnt*v[i]-leftsum)+(rightsum-rightcnt*v[i]);
		
//		cout<<leftcnt<<" "<<rightcnt<<" "<<leftsum<<" "<<rightsum<<" "<<s<<"\n";
//		cout<<ret<<"\n";
		ret=(ret*(s%MOD))%MOD;
		
		updateNum(v[i],1);
		updateSum(v[i],v[i]);
	}
	
	cout<<ret;
}

int main() {

	ios_base::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);

	solve();
}
