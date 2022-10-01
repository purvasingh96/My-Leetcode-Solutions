class Solution {
private:
    bool checkAllCountsEqual(vector<int>& counts){
        int val=0;
        for(int i=0;i<26;i++){
            if(counts[i]!=0) {
                val=counts[i];
                break;
            }
        }
        
        
        for(int i=0;i<26;i++) if(counts[i]!=0 && counts[i]!=val) return false;
        return true;
    }
    
public:
    bool equalFrequency(string word) {
        vector<int> counts(26, 0);
        
        for(auto c:word) counts[c-'a']+=1;
        
        
        for(int i=0;i<26;i++){
            if(counts[i]!=0){
                counts[i]-=1;
                if(checkAllCountsEqual(counts)) return true;
                counts[i]+=1;
            }
        }
        
        return false;
    }
};