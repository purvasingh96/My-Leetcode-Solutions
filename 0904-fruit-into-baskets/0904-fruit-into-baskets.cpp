class Solution {

public:
    int totalFruit(vector<int>& fruits) {
        
        int left=0, right=0, n = fruits.size();
        map<int, int> m;
        int c=0, ans=0;
        
        while(right<n){
            while(right<n && m.size()<=2){
                m[fruits[right]]+=1;
                right+=1;
                c+=1;
            }
            
            ans = m.size()<=2 ? max(ans, c):max(ans, c-1);
            //cout<<"right: "<<right<<"ans: "<<ans<<"\n";
            
           m[fruits[left]]-=1;
            if(m[fruits[left]]==0) m.erase(fruits[left]);
            left+=1;
            c-=1;
            
        }
        
        return ans;
    }
};