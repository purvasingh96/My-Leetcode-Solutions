class Solution {
public:

    
    string removeKdigits(string s, int k) {
        
        if(s.length() == k) return "0";
        
        // monotonic increasing queue
        
        deque<char> q;
        
        q.push_back(s[0]);
        
        for(int i=1;i<s.length();i++) {
            
            if((s[i]-'0' < (q.back() - '0')) && k>0) {
                
                while(!q.empty() && (s[i]-'0' < (q.back() - '0')) && k>0) {
                    q.pop_back();
                    k-=1;
                }
                
                
            } 
            
            q.push_back(s[i]);
            
        }
        
        
        // edge case 1: increasing string
        if(k!=0) {
            
            while(!q.empty() && k!=0) {
                q.pop_back();
                k-=1;
            }
            
        }
        
        // edge case 2: Trailing zeroes
        while(!q.empty() && q.front() == '0') {
            q.pop_front();
        }
        
        string res = "";
        while(!q.empty()) {
            
            res += q.front();
            q.pop_front();
            
        }
        
        return res.length()==0?"0":res;
        
    }
};