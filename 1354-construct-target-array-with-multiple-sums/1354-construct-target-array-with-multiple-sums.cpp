class Solution {
public:
    bool isPossible(vector<int>& target) {
        if(target.size()==1){
            return target[0]==1;
        }
        
        priority_queue<int> pq;
        long ts=0;
        for(auto x:target){
            pq.push(x);
            ts+=x;
        }
        
        while(pq.top()>1){
            
            int largest = pq.top();
            pq.pop();
            int rest = (ts-largest);
            if(rest==1) return true;
            
            int x = largest % rest;
            if(x==0 || x==largest) return false;
            pq.push(x);
            ts = ts - largest + x;
            
        }
        
        return true;
    }
};