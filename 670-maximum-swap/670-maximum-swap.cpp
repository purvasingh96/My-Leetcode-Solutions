class Solution {
public:
    int maximumSwap(int num) {
        //vector<int> freq(10, 0);
        vector<int> last_idx(10,-1);
        
        string s = to_string(num);
        
        // O(N)
        for(int i=0;i<s.length();i++) {
            //freq[original[i]-'0'] +=1;
            last_idx[s[i] - '0'] = i;
        }
        
        int idx=0;
        
        // O(10)
        for(int i=0, j=0;i<s.length();i++) {
            
            for(j=9;j>s[i]-'0' && last_idx[j]==-1; j--);
            
            if(j > s[i]-'0') {
                swap(s[i], s[last_idx[j]]);
                break;
            }
            
            if(i == last_idx[s[i] - '0']) last_idx[s[i] - '0'] = -1;
            
        }
        return stoi(s);
    }
};