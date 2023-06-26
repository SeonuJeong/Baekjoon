import java.util.*;
import java.io.*;

class Solution {
    boolean solution(String s) {
        boolean answer = true;

        s = s.toLowerCase();
        int ret=0;
        for(int i=0;i<s.length();i++){
            char ch = s.charAt(i);
            if(ch=='p') ret++;
            else if(ch=='y') ret--;
        }

        return ret==0?true:false;
    }
}