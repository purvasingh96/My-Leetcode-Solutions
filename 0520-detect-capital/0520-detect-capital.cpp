class Solution {
public:
    bool detectCapitalUse(string word) {
        int count=0;
        int idx=-1;
        
        for(int i=0;i<word.length();i++){
            if(isupper(word[i])){
                idx=i;
                count+=1;
            } 
            
        }
        //cout<<count;
        if(count == word.length()) return true;
        else if(count==1 && idx==0) return true;
        else if(count==0) return true;
        
        return false;
    }
};