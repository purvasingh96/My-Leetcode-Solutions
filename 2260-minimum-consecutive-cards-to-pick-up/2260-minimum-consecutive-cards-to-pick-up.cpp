class Solution {
public:
    int minimumCardPickup(vector<int>& cards) {
        
        int left=0, right=0;
        int n = cards.size();
        int minlen=INT_MAX;
        map<int, int> m;
        
        while(right!=n){
            
            
            //cout<<"m("<<cards[right]<<") = "<<m[cards[right]]<<"\n";
            
            if(m.find(cards[right])!=m.end()) {
                
                minlen=min(minlen, right-m[cards[right]]+1);
                m[cards[right]] = right;
                
            }
            m[cards[right]]=right;
            right+=1;
            
        }
        
        return minlen==INT_MAX?-1:minlen;
    }
};