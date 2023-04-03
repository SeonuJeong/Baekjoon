#include<bits/stdc++.h>

using namespace std;

int n;
vector<int> tree[102];
int nexts[102];
int counts[102];
vector<int> seq;
vector<int> leapArr[102];

void falling(int cur){
    if(tree[cur].empty()){
        seq.push_back(cur);
        counts[cur]++;
        return;
    }
    
    int nxt = nexts[cur];
    falling(tree[cur][nxt]);
    nexts[cur] = (nxt+1)%tree[cur].size();
    
}

void func(int pos, int value){
    
    for(int i=0;i<counts[pos];i++){
        leapArr[pos].push_back(1);
    }
    
    int x = value-counts[pos];
    
    for(int i=0,j=0;i<x;i++){
        
        leapArr[pos][j]++;
        
        if(leapArr[pos][j]==3)
            j++;
    }
    
}


vector<int> solution(vector<vector<int>> edges, vector<int> target) {
    vector<int> answer;
    
    n = target.size();
    fill(nexts, nexts+102, -1);
    fill(counts, counts+102, 0);
    
    sort(edges.begin(), edges.end());
    
    for(int i=0;i<edges.size();i++)
        tree[edges[i][0]].push_back(edges[i][1]);
    
    for(int i=1;i<=n;i++)
        if(tree[i].size())
            nexts[i]=0;
    
    
    while(true){
        falling(1);
        
        bool flag=true;    
        for(int i=0;i<n;i++){
            
            if(!target[i] && counts[i+1]){
                answer.push_back(-1);
                goto loopbreak;
            }
            
            if(!(counts[i+1]<=target[i] && counts[i+1]*3>=target[i]))
                flag=false; 
            
            if(counts[i+1]>target[i]){
                answer.push_back(-1);
                goto loopbreak;
            }
            
        }
        
        if(flag){
            
            for(int i=0;i<n;i++){
                if(target[i])
                    func(i+1,target[i]);
            }
            
            break;
        }
    }
    

    
    for(int cur:seq){
        answer.push_back(leapArr[cur].back());
        leapArr[cur].pop_back();
    }
loopbreak:
    return answer;
}