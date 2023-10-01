class Solution {
private:
    string reverse(string& s){
        string res="";
        for(int i=s.length()-1;i>=0;i--){
            res.push_back(s[i]);
        }
        return res;
    }
public:
    string reverseWords(string s) {
        string temp="", ans="";
        s+=" ";
        
        for(int i=0;i<s.length();i++){
            if(s[i] == ' '){
                ans += reverse(temp);
                temp = "";
                ans+= " ";
            } else {
                temp.push_back(s[i]);
            }
        }
        
        ans.pop_back();
        return ans;
    }
};