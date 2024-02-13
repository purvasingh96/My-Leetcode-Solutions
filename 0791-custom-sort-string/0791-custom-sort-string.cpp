class Solution {
public:
    string customSortString(string order, string s) {
        vector<int> count(26, 0);
        string res="";
        
        for(auto c:s){
            count[c-'a']+=1;
        }
        
       for(auto c:order){
           if(count[c-'a']!=0){
               string temp(count[c-'a'], c);
               count[c-'a']=0;
               res+=temp;
           }
       }
        
        for(int i=0;i<26;i++){
            if(count[i]!=0){
                string temp(count[i], (i+'a'));
                res+=temp;
            }
        }
        
        return res;
    }
};