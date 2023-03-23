class Solution {
    
    int sevenFinder(int n){
        int cnt=0;
        while(n!=0){
            if(n%10==7) cnt++;
            n/=10;
        }
        return cnt;
    }
    
    public int solution(int[] array) {
        int answer = 0;
        for(int n:array){
            answer+=sevenFinder(n);
        }
        return answer;
    }
}