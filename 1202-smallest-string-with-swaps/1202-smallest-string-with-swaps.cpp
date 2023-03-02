class Solution {
private:
    vector<int> root;
    vector<int> rank;
    
    int find(int x){
        if(root[x]==x) return x;
        return root[x]=find(root[x]);
    }
    
    void merge(int x, int y){
        int rx = find(x);
        int ry = find(y);
        
        if(rx!=ry){
            if(rank[rx]>=rank[ry]){
                root[ry]=rx;
                rank[rx]+=rank[ry];
            } else{
                root[rx]=ry;
                rank[ry]+=rank[rx];
            }
        }
    }
public:
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        int n = s.length();
        root.resize(n);
        rank.resize(n, 1);
        for(int i=0;i<n;i++){
            root[i]=i;
        }
        
        for(auto x:pairs){
            merge(x[0], x[1]);
        }
        
        unordered_map<int, priority_queue<char, vector<char>, greater<char>>> m;
        for(int i=0;i<n;i++){
            m[find(root[i])].push(s[i]);
        }
        
        string res="";
        for(int i=0;i<n;i++){
            int rx = find(root[i]);
            string temp(1, m[rx].top());
            m[rx].pop();
            res+=temp;
        }
        return res;
        
    }
};