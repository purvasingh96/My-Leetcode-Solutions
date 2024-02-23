class Solution {
public:
    string removeDuplicates(string s) {
       string res="";
        
        for(auto c:s){
            if(res.length() == 0 || res[res.length()-1]!=c){
                res.push_back(c);
            } else {
                res.pop_back();
            }
        }
        
        
        return res;
    }
};