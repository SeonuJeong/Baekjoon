#include<bits/stdc++.h>
using namespace std;

#define rep(i,x,n) for(int i=x;i<n;i++)
#define f first
#define s second

typedef long long ll;
typedef pair<int, int> pi;

const int INF = 1e9;


void solve(){
	string a,b;
	cin>>a; cin>>b;
	
	reverse(a.begin(),a.end());
	reverse(b.begin(),b.end());
	
	char carry=0;
	int i;
	string res="";
	for(i=0;i<min(a.length(),b.length());i++){
		
		int ad=a[i]-'0';
		int bd=b[i]-'0';
		
		res += ((ad+bd+carry)%10)+'0';
		carry = (ad+bd+carry)/10;
	
	}
	
	for(;i<max(a.length(),b.length());i++){
		
		char ad = a.length()<=i?0:(a[i]-'0');
		char bd = b.length()<=i?0:(b[i]-'0');
		
		res+=((ad+bd+carry)%10)+'0';
		carry = (ad+bd+carry)/10;
	}
	
	if(carry!=0){
		res+=carry+'0';
	}
	
	reverse(res.begin(),res.end());
	cout<<res;
}



int main() {

	ios_base::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);

//	int t;
//	cin>>t;
//	while(t--){
//		//cout<<"Case #"<<i<<": ";
//		solve();
//	}
solve();
}
