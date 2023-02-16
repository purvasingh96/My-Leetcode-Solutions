class Solution {
public:
    int romanToInt(string s) {
        // TC: O(N), SC: O(1)
        unordered_map<char, int> m;
        m['I'] = 1;
        m['V'] = 5;
        m['X'] = 10;
        m['L'] = 50;
        m['C'] = 100;
        m['D'] = 500;
        m['M'] = 1000;
        
        int val=0, n = s.length(), i=0;
        
        while(i<n){
            
            if(s[i] == 'I'){
                    if(i+1<n && s[i+1] == 'V') {
                        val += 4;
                        i+=2;
                    }
                    else if(i+1<n && s[i+1] == 'X') {
                        val+= 9;
                        i+=2;
                    } else {
                        
                    val += m[s[i]];
                    i+=1;
                }
                
                
            }
            else if(s[i] == 'X') {
                
                    if(i+1<n && s[i+1] == 'L'){
                        val += 40;
                        i+=2;
                    } else if(i+1<n && s[i+1] == 'C'){
                        val += 90;
                        i+=2;
                    } else {
                    val += m[s[i]];
                    i+=1;
                }
                
            }
            else if(s[i]=='C'){
                
                    if(i+1<n && s[i+1] == 'D'){
                        val += 400;
                        i+=2;
                    } else if(i+1<n && s[i+1] == 'M') {
                        val += 900;
                        i+=2;
                    } else {
                    val += m[s[i]];
                    i+=1;
                }
                
            } else {
                    val += m[s[i]];
                    i+=1;
                }
            
        }
        
        return val;
        
    }
};