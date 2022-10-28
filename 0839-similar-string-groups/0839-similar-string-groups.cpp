class UnionFind{
private:
    vector<int> root;
    int components;
public:
    
    UnionFind(int n){
        components=n;
        root.resize(n);
        for(int i=0;i<n;i++){
            root[i] = i;
        }
    }
    
    
    
    int find(int x){
        if(root[x] == x) return x;
        return root[x] = find(root[x]);
    }
    
    void connect(int i, int j) {
        
        int ra = find(i);
        int rb = find(j);
        
        if(ra!=rb){
            root[ra] = rb;
            
            components -= 1;
        } 
        //cout<<i<<" "<<j<<" "<<components<<"\n";
        
    }
    
    int returnComponents(){
        return components;
    }
 
};

class Solution {
private:
    bool isOneHop(string& a, string& b){
        if(a == b) return true;
        int count=0;
        
        for(int i=0;i<a.length();i++){
            if(a[i]!=b[i]){
                count+=1;
                if(count>2) return false;
                
            }
        }
        
        return true;
    }
    
public:
    int numSimilarGroups(vector<string>& res) {
        int n = res.size();
        UnionFind uf(n);
        
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                
                if(isOneHop(res[i], res[j])){
                    uf.connect(i, j);
                }
            }
        }
            
            
          return uf.returnComponents();  
            
            
    }
};