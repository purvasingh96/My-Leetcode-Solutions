class Solution {
public:
    string removeDigit(string s, char digit) {
        string maxval = "0";
        string ans;
        
        for(int i=0;i<s.length();i++){
            if(s[i] == digit){
                string temp = s;
                temp.erase(i, 1);
                //auto x = stoll(temp);
               if(temp > maxval){
                   maxval=temp;
                   //ans = temp;
               }
            }
        }
        
        return maxval;
    }
};