#include <bits/stdc++.h>

using namespace std;

int r,c;
int dy[4] = {1,-1,0,0};
int dx[4] = {0,0,1,-1};
bool isOk(char command, int move, vector<string>& park){
    
    int dir;
    switch(command)
    {
        case 'E':
            dir = 2;
            break;
        case 'W':
            dir = 3;
            break;
        case 'N':
            dir = 1;
            break;
        case 'S':
            dir = 0;
            break;
    }
    
    int H = park.size();
    int W = park[0].size();
    
    for(int i=1;i<=move;i++){
        int y = r+dy[dir]*i;
        int x = c+dx[dir]*i;
        
        if(y<0||y>=H||x<0||x>=W||park[y][x]=='X')
            return false;
    }
    
    return true;
}

vector<int> solution(vector<string> park, vector<string> routes) {
    
    for(int i=0;i<park.size();i++)
        for(int j=0;j<park[i].size();j++)
            if(park[i][j]=='S'){
                r=i,c=j;
                park[r][c]='O';
                goto ol;
            }
ol:
    
    for(string s: routes){
        char cm = s[0];
        int move = s[2]-'0';
        
        if(!isOk(cm,move,park)) continue;
        
        switch(cm)
        {
            case 'E':
                c+=move;
                break;
            case 'W':
                c-=move;
                break;
            case 'N':
                r-=move;
                break;
            case 'S':
                r+=move;
                break;
        }
    }
    
    return {r,c};
}