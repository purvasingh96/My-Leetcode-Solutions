class Solution {
public:
    string customSortString(string order, string s) {
        vector<int> count(26, 0);
        for(char c:s){
            count[c-'a']+=1;
        }
        
        string res="";
        for(char c:order){
            if(count[c-'a']!=0){
                string st(count[c-'a'], c);
                res +=st;
                count[c-'a']=0;
            }
        }
        
        for(int i=0;i<count.size();i++){
            if(count[i]!=0){
                char c = (i+'a');
                string st(count[i], c);
                res+=st;
                count[i]=0;
            }
        }
        
        return res;
    }
};