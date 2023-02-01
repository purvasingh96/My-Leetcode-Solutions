class Solution {
private:
    string generateString(int n, string s){
        string ans="";
        while(n--) ans+=s;
        
        return ans;
    }
    
public:
    string gcdOfStrings(string long_string, string short_string) {
        if(long_string+short_string!=short_string+long_string) return "";
        int m = long_string.length(), n = short_string.length();
        
        int len = __gcd(m, n);
        
        
        string temp = short_string.substr(0, len);
        
        return temp;
    }
};