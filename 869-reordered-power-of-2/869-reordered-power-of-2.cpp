class Solution {
private:
    // 23456
    vector<long> powersOfTwo(){
        vector<long> res;
        for(int i=0;pow(2,i)<=1e9;i++){
            res.push_back(pow(2, i));
        }
        return res;
    }
    
public:
    bool reorderedPowerOf2(int n) {
        auto res = powersOfTwo();
        vector<int> og(10, -1);
        
        while(n!=0){
            int t = n%10;
            if(og[t]==-1) {
                og[t]=0;
            }
            og[t]+=1;
            n=n/10;
        }
        
        // 2256 , 625
        
        for(int i=0;i<res.size();i++){
            if(res[i] == n) return true;
            vector<int> ans(10, -1);
            int temp = res[i];
            
            while(temp!=0){
                int t = temp%10;
                if(ans[t]==-1) ans[t]=0;
                ans[t]+=1;
                temp=temp/10;
            }
            
            bool potential=true;
            for(int i=0;i<10;i++){
                if(ans[i] != og[i]){
                    potential=false;
                    break;
                } 
                
            }
            //cout<<res[i]<<" "<<potential<<"\n";
            if(potential) return true;
        }
        
        return false;
        
    }
};