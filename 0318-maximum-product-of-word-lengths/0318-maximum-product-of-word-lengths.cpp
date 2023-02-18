class Solution {
private:
    int bitNumber(char ch){
    return (int)ch - (int)'a';
  }
    int computeBitmask(string s){
        int bitmask=0;
        for(auto c:s){
            bitmask |= 1 << bitNumber(c);
        }
        return bitmask;
    }
    
public:
    int maxProduct(vector<string>& words) {
        
        unordered_map<string, int> m;
        for(auto word:words){
           m[word] = computeBitmask(word);
            cout<<"word: "<<word<<" bitmask: "<<computeBitmask(word)<<"\n";
        }
        
        //for(auto x:words) cout<<x<<" ";
        
        int n = words.size();
        int maxlen = 0;
        for(auto x:m){
            for(auto y:m){
                if((x.second&y.second)==0) {
                    int len = x.first.length()*y.first.length();
                    maxlen = max(maxlen, len);
                }
            }
        }
        
        return maxlen;
    }
};