class Solution {
public:
    string removeDuplicates(string s) {
        string res="";
        for(int i=0;i<s.length();i++){
            
            if(res.length() == 0 || res.back()!=s[i]){
                res += s[i];
            } else {
                while(res.length() >0 && res.back()==s[i]){
                    res.pop_back();
                }
            }
        }
        
        return res;
    }
};