class Solution {
private:
    bool notCommon(vector<int>& a, vector<int>& b){
        for(int i=0;i<26;i++){
            if(a[i]>0 && b[i]>0 ) return false;
        }
        return true;
    }
public:
    int maxProduct(vector<string>& words) {
        
        unordered_map<string, vector<int>> m;
        for(auto word:words){
            vector<int> temp(26, 0);
            for(auto c:word){
                temp[c-'a']+=1;
            }
            m[word] = temp;
        }
        
        //for(auto x:words) cout<<x<<" ";
        
        int n = words.size();
        int maxlen = 0;
        for(int i=n-1;i>=0;i--){
            for(int j=i-1;j>=0;j--){
                
                if(notCommon(m[words[i]],m[words[j]])){
                    int len = words[i].length()*words[j].length();
                    maxlen = max(maxlen,  len);
                }
            }
        }
        
        return maxlen;
    }
};