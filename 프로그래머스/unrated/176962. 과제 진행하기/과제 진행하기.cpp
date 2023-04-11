#include<bits/stdc++.h>

using namespace std;

bool cmp(vector<string>& a, vector<string>& b){
    return a[1]<b[1];
}

int trans(string s){
    return stoi(s.substr(0,2))*60 + stoi(s.substr(3,2));
}

vector<string> solution(vector<vector<string>> plans) {
    vector<string> answer;
    
    sort(plans.begin(), plans.end(), cmp);
    
    vector<vector<string>> remains;
    
    for(int i=0;i<plans.size();i++){
        
        if(i==plans.size()-1){
            answer.push_back(plans[i][0]);
            break;
        }
        
        
        int cur = trans(plans[i][1]);
        int nextstart = trans(plans[i+1][1]);
        
        int diff = nextstart - cur;
        
        if(stoi(plans[i][2])>diff){
            remains.push_back({plans[i][0],to_string(stoi(plans[i][2])-diff)});
            continue;
        }
        
        answer.push_back(plans[i][0]);
        int remainTime = diff-stoi(plans[i][2]);
        
        while(remainTime>0&&!remains.empty()){
            int t = stoi(remains.back()[1]);
            
            t -= remainTime;
            remainTime -= stoi(remains.back()[1]);
            
            if(t<=0){
                answer.push_back(remains.back()[0]);
                remains.pop_back();
            }
            else
                remains.back()[1] = to_string(t);
        }
    }
    
    for(int i=remains.size()-1;i>=0;i--){
        answer.push_back(remains[i][0]);
    }
    
    return answer;
}