class Solution {
private:
    
    int find(int x, vector<int>& root){
        if(root[x]==x){
            return x;
        }
        return root[x] = find(root[x], root);
    }
public:
    bool equationsPossible(vector<string>& equations) {
        vector<int> root(26);
        
        
        for(int i=0;i<26;i++) root[i]=i;
        
        for(auto e:equations){
            int x = e[0]-'a', y=e[3]-'a';
            if(x>y) swap(x, y);
            
            char op = e[1];
            
            if(op=='='){
                root[find(x, root)] = find(y, root);
            } 
            
        }
        
        for(auto e:equations){
            int x = e[0]-'a', y=e[3]-'a';
            if(x>y) swap(x, y);
            
            char op = e[1];
            
            if(op=='!' && find(x, root)==find(y, root)) return false;
            
        }
        
        return true;
        
    }
};