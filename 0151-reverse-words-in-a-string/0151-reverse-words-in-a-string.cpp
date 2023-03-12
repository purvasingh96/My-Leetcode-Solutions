class Solution {
public:
    string reverseWords(string s) {
        int n = s.length();
        int i=n-1;
        while(i>=0 && s[i]==' ') i--;
        string res;
        
        
        while(i>=0){
            int j=i;
            string temp="";
            while(j>=0 && s[j]!=' '){
                temp.push_back(s[j--]);
            }
            int k=temp.length()-1;
            while(k>=0){
                res.push_back(temp[k]);
                k-=1;
            }
            
            res.push_back(' ');
            i=j;
            
            while(i>=0 && s[i]==' '){
                i-=1;
            }
        }
        
        while(res.length()>0 && res.back() == ' ') res.pop_back();
        return res;
            
    }
};