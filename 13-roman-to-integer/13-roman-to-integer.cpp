class Solution {
public:
    int romanToInt(string s) {
        map<char, int> m;
        m['I'] = 1;
        m['V'] = 5;
        m['X'] = 10;
        m['L'] = 50;
        m['C'] = 100;
        m['D'] = 500;
        m['M'] = 1000;
        
        int ans=0;
        
        for(int i=0;i<s.length();i++){
            
            if(s[i] == 'I' || s[i] == 'X' || s[i] == 'C'){
                
                if(i<s.length()-1){
                    string sub = s.substr(i,2);
                    if(sub == "IV"){
                        ans+=4;
                        i+=1;
                    } else if(sub=="IX"){
                        ans+=9;
                        i+=1;
                    } else if(sub == "XL"){
                        ans+=40;
                        i+=1;
                    } else if(sub == "XC"){
                        ans+=90;
                        i+=1;
                    } else if(sub == "CD"){
                        ans+=400;
                        i+=1;
                    } else if(sub == "CM"){
                        ans+=900;
                        i+=1;
                    } else{
                        ans+= m[s[i]];
                    }
                    
                    //cout<<s[i]<<" "<<ans<<"\n";
                    
                } 
                
                else{
                    ans += m[s[i]];
                    //cout<<s[i]<<" "<<ans<<"\n";
                }
                
                
            } else{
                ans += m[s[i]];
                //cout<<s[i]<<" "<<ans<<"\n";
            }
            
        }
        return ans;
     }
};