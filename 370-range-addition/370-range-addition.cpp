class Solution {
public:
    vector<int> getModifiedArray(int length, vector<vector<int>>& updates) {
        vector<int> res(length, 0);
        
        for(auto update:updates){
            int l =update[0], r=update[1], val=update[2];
            
            res[l]+=val;
            if(r+1<length) res[r+1]-=val;
        }
        
        for(int i=1;i<length;i++){
            res[i] += res[i-1];
        }
        
        return res;
    }
};