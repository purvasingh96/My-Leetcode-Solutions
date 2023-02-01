class Solution {
private:
    string generateString(int n, string s){
        string ans="";
        while(n--) ans+=s;
        
        return ans;
    }
    
public:
    string gcdOfStrings(string long_string, string short_string) {
        int m = long_string.length(), n = short_string.length();
        if(m < n){
            swap(long_string, short_string);
            swap(m, n);
        }
        
        for(int i=0;i<n;i++){
            if(long_string[i]!=short_string[i]) return "";
        }
        
        int len = __gcd(m, n);
        
        
        string temp = short_string.substr(0, len);
        int concat1 = m/len, concat2 = n/len;
        
        
        if(generateString(concat1, temp) == long_string && generateString(concat2, temp)  == short_string) return temp;
        return "";
    }
};