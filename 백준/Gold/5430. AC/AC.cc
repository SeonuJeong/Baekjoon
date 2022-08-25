#include<bits/stdc++.h>
using namespace std;

#define rep(i,x,n) for(int i=x;i<n;i++)
#define f first
#define s second

typedef long long ll;
typedef pair<int, int> pi;

const int INF = 1e9;

string p;
int n;
int x[100001];

void split(string input){
	int idx=0;
	
	int le=0,ri=0;
	
	rep(i,0,input.length()){
		
		if(i==input.length()-1)
			x[idx]=stoi(input.substr(le,i-le+1));
			
		if(input[i]==','){
			x[idx++]=stoi(input.substr(le,ri-le+1));
			le=i+1;
		}
		else{
			ri=i;
		}
		
	}
	
}


void solve(){
	
	cin>>p;cin>>n;
	string s; cin>>s;
	s=s.substr(1,s.length()-2);
	split(s);
	
	int le=0, ri=n-1;
	int cur=le;
	
	bool error=false;
	rep(i,0,p.length()){
		
		if(p[i]=='R'){
			if(cur==le) cur=ri;
			else cur=le;
		}	
		else{
			if(ri<le){
				cout<<"error";
				error=true;
				break;
			}
			
			if(cur==le){
				le++; cur++;
			}
			else{
				ri--; cur--;
			}
		}
	}
	
		
	if(!error){
		cout<<"[";
		if(ri<le){
			cout<<"]";
		}
		else{
			
			if(cur==le){
				
				for(int i=le;i<=ri;i++){
					cout<<x[i];
					
					if(i!=ri){
						cout<<",";
					}
				}
				
			}
			else{
				for(int i=ri;i>=le;i--){
					cout<<x[i];
					
					if(i!=le){
						cout<<",";
					}
				}
			}
			cout<<"]";
		}
	}
	cout<<"\n";
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
