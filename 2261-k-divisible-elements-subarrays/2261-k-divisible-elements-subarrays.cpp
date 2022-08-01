class trie{
  public:
    map<int, trie*> children;
    trie(){
        
    }
};
class Solution {
public:
    int countDistinct(vector<int>& nums, int k, int p) {
        trie* root = new trie();
        int n = nums.size();
        
        int ans=0;
        
        for(int i=0;i<n;i++){
            
            trie* temp = root;
            int count=0;
            
            for(int j=i;j<n;j++){
                if(nums[j]%p==0){
                    count+=1;
                }
                
                if(count>k) break;
                
                if(!temp->children[nums[j]]){
                    temp->children[nums[j]] = new trie();
                    ans+=1;
                }
                temp = temp->children[nums[j]];
            }
            
        }
        
        return ans;
    }
};