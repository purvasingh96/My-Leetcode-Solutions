class Solution {
  
public:
    bool isPossible(vector<int>& nums) {
     
        map<int, priority_queue<int, vector<int>, greater<int>>> m;
        
        for(int i=0;i<nums.size();i++){
            int target = nums[i]-1;
            
            if(m.find(target)==m.end()){
                m[nums[i]].push(1);
            } else {
                
                if(m.find(target)!=m.end()){
                    
                    int top = m[target].top();
                    m[target].pop();
                    
                    if(m[target].size()==0) m.erase(target);
                    
                    m[nums[i]].push(top+1);
                    
                } 
                
            }
            
        }
        
        for(auto x:m){
            auto pq = x.second;
            while(!pq.empty()){
                if(pq.top()<3) return false;
                pq.pop();
            }
        }
        return true;
        
    }
};