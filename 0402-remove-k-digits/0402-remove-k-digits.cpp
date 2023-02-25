class Solution {
public:
    string removeKdigits(string num, int k) {
        deque<int> q;
        string ans="";
        int i=0;
        for(;i<num.length();i++){
                if(k==0) break;
                else {
                    while(!q.empty() && q.back()>(num[i]-'0') && k>0){
                        q.pop_back();
                        k-=1;
                    }
                    
                }
            q.push_back(num[i]-'0');
            
        }
        
        while(i<num.length()){
            q.push_back(num[i++]-'0');
        }
        
        // remove trailing zeros
        while(!q.empty() && (q.front()==0)){
            q.pop_front();
        }
        
        // further shorten an increasing sequence
        while(!q.empty() && k--){
            q.pop_back();
        }
        
        while(!q.empty()){ 
            string temp(1, q.front()+'0');
            ans+=temp;
            q.pop_front();
        }
        
        
        return ans==""?"0":ans;
        
    }
};