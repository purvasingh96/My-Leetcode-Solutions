class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char, int> m;
        int n = s.length(),res = 0, i=0;
        
        m['I'] = 1;
        m['V'] = 5;
        m['X'] = 10;
        m['L'] = 50;
        m['C'] = 100;
        m['D'] = 500;
        m['M'] = 1000;
    
        
        while(i<n){
            
            if(s[i] == 'I' || s[i] == 'X' || s[i] == 'C'){
                
                if(i+1<n){
                    
                    string sub = s.substr(i, 2);
                    
                    if(sub == "IV") {
                        res += 4;
                        i+=2;
                    }
                    else if(sub == "IX"){
                        res+=9;
                        i+=2;
                    } else if(sub == "XL"){
                        res+= 40;
                        i+=2;
                    } else if(sub == "XC"){
                        res+=90;
                        i+=2;
                    } else if(sub == "CD"){
                        res+= 400;
                        i+=2;
                    } else if(sub == "CM"){
                        res += 900;
                        i+=2;
                    } else {
                        res += m[s[i]];
                        i+=1;
                    } 
                    
                } else{ 
                    res += m[s[i]];
                    i+=1;
                }
                
            } else {
                res+= m[s[i]];
                i+=1;
            }
            
        }
        
        return res;
        
    }
};