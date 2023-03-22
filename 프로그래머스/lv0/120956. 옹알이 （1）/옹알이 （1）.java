import java.util.Arrays;

class Solution {
    
    String[] words={"aya","ye","woo","ma"};
    
    boolean go(String s){
        
        int[] range = new int[s.length()];
        Arrays.fill(range, 0);
        for(String word:words){
            int pos=s.indexOf(word);
            if(pos==-1) continue;
            
            for(int i=pos;i<pos+word.length();i++){
                
                if(range[i]==1) return false;
                
                range[i]=1;
            }
        }
        
        for(int x:range){
            if(x==0) return false;
        }
        
        return true;
    }
    
    public int solution(String[] babbling) {
        int answer = 0;
        
        for(String s:babbling){
            if(go(s))
                answer++;
        }
        
        return answer;
    }
}