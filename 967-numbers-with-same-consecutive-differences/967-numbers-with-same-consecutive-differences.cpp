class Solution {

public:
    vector<int> numsSameConsecDiff(int n, int k) {
        queue<int> q;
        vector<int> res;
        
        for(int i=1;i<10;i++){
            q.push(i);
        }
        
        
        
        while(--n){
            int sz = q.size();
            
            while(sz--){
                int f = q.front();
                q.pop();
                
                for(int i=0;i<10;i++){
                    int r = f%10;
                    
                    if(abs(r-i)==k){
                        
                        q.push(f*10+i);
                    }
                }
                
            }
        }
        
        while(!q.empty()){
            res.push_back(q.front());
            q.pop();
        }
        
        
        
        return res;
    }
};