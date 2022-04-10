class Solution {
public:
    int maximumSwap(int num) {
        vector<int> freq(10, 0);
        vector<int> last_idx(10);
        
        string original = to_string(num);
        
        for(int i=0;i<original.length();i++) {
            freq[original[i]-'0'] +=1;
            last_idx[original[i] - '0'] = i;
        }
        
        int idx=0;
        
        
        for(int i=9;i>=0;i--) {
            
            if(freq[i] > 0) {
                
                int n = freq[i];
            
                while(n>0) {

                    if(i!=original[idx]-'0') {
                            char t = original[idx];
                            original[idx] = original[last_idx[i]];
                            original[last_idx[i]]  = t;
                            return stoi(original);
                    }

                    n-=1;
                    idx += 1;
                }
                
                
            }
            
            
            
        }
        return stoi(original);
    }
};