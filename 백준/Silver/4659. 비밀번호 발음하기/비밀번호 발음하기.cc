#include<bits/stdc++.h>
using namespace std;

#define ll long long
const int INF = 1e9;


void solve(){
	vector<string> v;
	string s;
	while(cin>>s){
		if(s=="end") break;
		v.push_back(s);
	}
	
	set<char> _set;
	_set.insert('a');_set.insert('e');_set.insert('i');_set.insert('o');_set.insert('u');
	
	for(int i=0; i<v.size();i++){
		
		bool rule1=false;
		bool rule2=true;
		bool rule3=true;
		
		int same=0;
		for(int j=0; j<v[i].length();j++){
			if(_set.find(v[i][j])!=_set.end())
				rule1=true;
			
			if(_set.find(v[i][j])==_set.end())
				if(same>=0) same++;
				else same=1;
			else
				if(same<=0) same--;
				else same=-1;
			
			if(abs(same)==3) rule2=false;
			
			if(j!=0&&v[i][j-1]==v[i][j]){
				string two=v[i].substr(j-1,2);
				if(two!="oo"&&two!="ee")
					rule3=false;
			}
		}
		
		if(rule1&&rule2&&rule3)
			cout<<"<"<<v[i]<<"> is acceptable.\n";
		else
			cout<<"<"<<v[i]<<"> is not acceptable.\n";
	}
}



int main() {

	ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);

	solve();
}
