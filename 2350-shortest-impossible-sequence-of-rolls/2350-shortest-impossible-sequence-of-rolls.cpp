class Solution {
public:
    int shortestSequence(vector<int>& rolls, int k) {
        map<int, int> m;
        int c=0, ans=0;
        
        for(auto x:rolls){
            m[x]+=1;
            if(m[x]==1) c+=1;
            
            if(c==k){
                ans+=1;
                m.clear();
                c=0;
            }
        }
        
        return ans+1;
    }
};