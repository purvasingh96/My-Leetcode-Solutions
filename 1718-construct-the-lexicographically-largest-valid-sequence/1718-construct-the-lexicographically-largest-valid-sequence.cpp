class Solution {
private:
    bool backtrack(int i, int n, vector<int>& temp, unordered_set<int>& st){
        if(st.size()==0) return true;
        if(temp[i]!=-1) return backtrack(i+1, n, temp, st);
        else {
            
            for(int j=n;j>=1;j--){
                
                int dist = j==1?0:j;
                if(st.count(j) && i+dist < temp.size() && temp[i+dist]==-1){
                    
                    temp[i] = temp[i+dist] = j;
                    st.erase(j);
                    if(backtrack(i+1, n, temp, st)) return true;
                    st.insert(j);
                    temp[i] = temp[i+dist] = -1;
                }
                
            }
            
        }
        return false;
    }
public:
    vector<int> constructDistancedSequence(int n) {
        unordered_set<int> st;
        for(int i=1;i<=n;i++) st.insert(i);
        vector<int> temp(2*n-1, -1);
        backtrack(0, n, temp, st);
        return temp;
    }
};