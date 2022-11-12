#include<bits/stdc++.h>
using namespace std;

#define ll long long

int main() {

	vector<int> person(9,0);
	int totalSum=0;
	for(int i=0; i<9; i++){
		cin>>person[i];
		totalSum+=person[i];
	}
	
	bool isOut=false;
	vector<int> result;
	for(int i=0; i<9; i++){
		for(int j=i+1; j<9; j++){
			int twoSum = person[i]+person[j];
			
			if(totalSum-twoSum==100){
				
				for(int k=0; k<9; k++){
					
					if(k!=i&&k!=j)
						result.push_back(person[k]);
					
				}
			
				isOut=true;	
				break;
				
			}
		}
		
		if(isOut) break;
	}
	
	
	sort(result.begin(), result.end());
	
	for(int i=0; i<result.size(); i++)
		cout<<result[i]<<"\n";
	
	return 0;
}
