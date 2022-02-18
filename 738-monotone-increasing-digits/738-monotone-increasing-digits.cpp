class Solution {
public:
    int monotoneIncreasingDigits(int n) {
        string res ="";
        string num = to_string(n);
        
        deque<char> q;
        q.push_back(num[0]);
        
        for(int i=1;i<num.length();i++) {
            
            if(!q.empty() && (q.back() - '0' > num[i] - '0')) {
                
                
                if(q.front() - '0' < q.back() - '0') {
                    
                     while((q.front()!=q.back())) {
                    
                        res += q.front();
                        q.pop_front();
                    
                    }
                    
                }
                
                
                
                int remaining = (q.front() - '0') - 1;
                res += (remaining + '0');
                
                int rem_len = num.length() - res.length();
                
                for(int j=0;j<rem_len;j++) {
                    res+= '9';
                }
                
                return stoi(res);
                
            } 
            
            else {
                
                q.push_back(num[i]);
                
            }
            
        }
        
        return n;
    }
};