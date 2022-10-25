#include<bits/stdc++.h>
using namespace std;

#define rep(i,x,n) for(int i=x;i<n;i++)
#define f first
#define s second

typedef long long ll;
typedef pair<int, int> pi;
typedef tuple<int,int,int> ti;
const int INF = 1e9;

int S,m,n;
int A[1001];
int B[1001];
int cnt=0;
map<int,int> mp;

void solve(){
	cin>>S>>m>>n;
	
	rep(i,0,m){
		cin>>A[i];
	}
	rep(i,0,n){
		cin>>B[i];
	}
	

	//피자 B의 모든 경우의 수 map에 저장
	
	rep(i,0,n){
		int le=i,ri=i;
		int sum=0;
		///전체 제외 
		do{
			sum+=B[ri];
			mp[sum]++;
			
			if(sum==S) cnt++;
			
			ri=(ri+1)%n;
		}while(le!=(ri+1)%n);
		
	}
	
	//전체 
	int sum=0;
	rep(j,0,n){
		sum+=B[j];
	}
	mp[sum]++;
	
	if(sum==S) cnt++;
	
	// 피자 A의 모든 경우에서 필요한 값 찾기
	
	rep(i,0,m){
		int le=i,ri=i;
		int sum=0;
		do{
			sum+=A[ri];
			cnt+=mp[S-sum];
			
			if(sum==S) cnt++;
			
			ri=(ri+1)%m;
		}while(le!=(ri+1)%m);
	} 
	
	//전체 
	sum=0;
	rep(j,0,m){
		sum+=A[j];
	}
	cnt+=mp[S-sum];
	
	if(sum==S) cnt++;
	
	 
	cout<<cnt;
}

int main() {

	ios_base::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);

	solve();
}
