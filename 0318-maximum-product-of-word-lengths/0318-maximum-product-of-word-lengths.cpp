class Solution {
private:
    int mask(string& s){
        int bitmask =0;
        for(auto c:s){
            bitmask |= (1 << (c-'a'));
        }
        return bitmask;
    }
public:
    int maxProduct(vector<string>& words) {
        int n = words.size();
        unordered_map<string, int> m;
        for(auto x:words) {
            int bitmask = mask(x);
            
            m[x] = bitmask;
        }
        
        
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if((m[words[i]] & m[words[j]]) == 0){
                    int prod = words[i].length() * words[j].length();
                    ans = max(ans, prod);
                }
            }
            
        }
        
        return ans;
    }
};