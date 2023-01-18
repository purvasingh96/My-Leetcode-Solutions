class UnionFind{
private:
    vector<int> parent;
public:
    UnionFind() {
        parent.resize(26);
        for(int i=0;i<26;i++){
            parent[i] = i;
        }
    }
    
    int find(int x){
        if(parent[x] == x) return x;
        return parent[x] = find(parent[x]);
    }
    
    void merge(int x, int y){
        int px = find(x);
        int py = find(y);
        
        if(px == py) return;
        
        if(px <py){
            parent[py]=px;
        } else{
            parent[px]=py;
        }
    }
    
    vector<int> returnParent(){
        return parent;
    }
};

class Solution {
public:
    string smallestEquivalentString(string s1, string s2, string baseStr) {
        UnionFind* uf = new UnionFind();
        for(int i=0;i<s1.length();i++){
            uf->merge(s1[i]-'a', s2[i]-'a');
        }
        
        vector<int> p = uf->returnParent();
        
        string ans="";
        for(int i=0;i<baseStr.length();i++){
            string temp(1, uf->find(baseStr[i]-'a')+'a');
            ans += temp;
        }
        
        return ans;
    }
};