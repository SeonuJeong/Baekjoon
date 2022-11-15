#include<bits/stdc++.h>
using namespace std;

#define rep(i,x,n) for(int i=x;i<n;i++)
#define f first
#define s second

typedef long long ll;
typedef pair<int, int> pi;

const int INF = 1e9;


void solve(){
	vector<int> v = {0,1,2,3,4,5,6,7,8,9};
	
	int k;cin>>k;
	vector<char> op(k);
	rep(i,0,k)
		cin>>op[i];
	
	
	string maxVal,minVal;
	
	rep(i,0,k+1){
		maxVal+='0';
		minVal+='9';
	}
	
	do{
		bool isOk=true;
		rep(i,0,k){
			if(op[i]=='<'){
				if(v[i]>v[i+1]) isOk=false;
			}
			else{
				if(v[i]<v[i+1]) isOk=false;
			}
		}	
		
		if(!isOk) continue;
			
		string s="";
		rep(i,0,k+1){
			s+='0'+v[i];
		}
		
		rep(i,0,k+1){
			if(maxVal[i]>s[i])
				break;	
			else if(maxVal[i]<s[i])	{
				maxVal=s; break;
			}
		}
		
		rep(i,0,k+1){
			if(minVal[i]<s[i])
				break;	
			else if(minVal[i]>s[i])	{
				minVal=s; break;
			}
		}	
		
	}while(next_permutation(v.begin(),v.end()));
	
	cout<<maxVal<<"\n";
	cout<<minVal;
}

int main() {

	ios_base::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);

	solve();
}
