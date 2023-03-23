class Solution {
    
    
    int cut(int M, int N){
        if(M==1&&N==1)
            return 0;
        
        if(M%2==0)
            return cut(M/2,N)*2+1;    
        
        if(N%2==0)
            return cut(M,N/2)*2+1;
        
        if(M>N)
            return cut(M-1,N)+cut(1,N)+1;
        else
            return cut(M,N-1)+cut(M,1)+1;
    }
    
    public int solution(int M, int N) {
        int answer = 0;
        
        answer= cut(M,N);
        return answer;
    }
}