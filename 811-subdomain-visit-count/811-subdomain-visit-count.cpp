class Solution {
public:
    vector<string> subdomainVisits(vector<string>& cpdomains) {
        
        map<string, int> m;
        
        for(auto s:cpdomains) {
            
            string digit = "";
            string domain = "";
            
            int i=0;
            
            
                
                while(s[i] != ' ') {
                    digit += s[i];
                    
                    i+=1;
                }
                
                i+=1;
                int d = stoi(digit);
                
                string new_s = s.substr(i);
                m[new_s] += d;
                
                for(i=0;i<new_s.length();i++) {
                    
                    if(new_s[i] == '.') {
                        new_s = new_s.substr(i+1);
                        m[new_s] += d;
                        i=0;
                    }
                    
                }
                
            
            
        }
    
            vector<string> res;
        
        for(auto x:m) {
            
            string ans = "";
            ans = to_string(x.second) + " " + (x.first);
            res.push_back(ans);
            
            
        }
        
        
            return res;
        
    }
};