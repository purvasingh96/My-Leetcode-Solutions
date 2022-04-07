class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        
        priority_queue<int> pq;
        
        for(auto x:stones) {
            pq.push(x);
        }
        
        while(pq.size()>1) {
            
            int a = pq.top();
            pq.pop();
            int b = pq.top();
            pq.pop();
            
            pq.push(a-b);
            
        }
        
        return pq.empty()?0:pq.top();
        
    }
};