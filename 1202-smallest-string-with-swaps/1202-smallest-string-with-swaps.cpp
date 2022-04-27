class UnionFind{
  private:
    vector<int> rank;
    vector<int> root;
public:
    UnionFind(int n): rank(n), root(n) {
        for(int i=0;i<n;i++) {
            rank[i]=1;
            root[i]=i;
        }
    }
    
    int find(int x) {
        if(root[x] == x) return x;
        return root[x] = find(root[x]);
    }
    
    void disjointUnion(int x, int y) {
        int rx = find(x);
        int ry = find(y);
        
        if(rx!=ry) {
            
            if(rank[rx] >= rank[ry]) {
                rank[rx]+=1;
                root[ry]=rx;
            } else{
                rank[ry]+=1;
                root[rx]=ry;
            }
            
            
        }
    }
};

class Solution {
public:
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        int n = s.length();
        UnionFind uf(n);
        
        for(auto p:pairs){
            uf.disjointUnion(p[0], p[1]);
        }
        
        map<int, vector<int>> child;
        
        for(int i=0;i<n;i++) {
            child[uf.find(i)].push_back(i);
        }
        
        
        //string s(n, '');
        
        for(auto p:child) {
            string temp = "";
            for(auto i:p.second) {
                temp += s[i];
            }
            
            sort(temp.begin(), temp.end());
            int j=0;
            for(auto k:p.second) {
                s[k] = temp[j++];
            }
        }
        
        return s;
        
    }
};