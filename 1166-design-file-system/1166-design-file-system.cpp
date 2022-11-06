class TrieNode{
 public:
    int val;
    unordered_map<string, TrieNode*> memo;
    TrieNode(){
        val=-1;
    }
};


class FileSystem {
private:
    TrieNode* root;
    
    vector<string> splitString(string path) {
        vector<string> res;
        path = path.substr(1);
        stringstream ss(path);
        string temp;
        
        while(getline(ss, temp, '/')){
            res.push_back(temp);
        }
        
        return res;
    }
public:
    FileSystem() {
        root = new TrieNode();
    }
    
    // bool searchPath(TrieNode* node, int start, int end, vector<string>& res){
    //     for(int i=start;i<=end;i++){
    //         if(node->memo.find(res[i])==node->memo.end()) return false;
    //         node = node->memo[res[i]];
    //     }
    //     return true;
    // }
    
    bool insert(TrieNode* node, string word, int val){
        if(node->memo.find(word) == node->memo.end()){
            node->memo[word] = new TrieNode();
        }
        node = node->memo[word];
        if(node->val != -1) return false;
        node->val = val;
        return true;
    }
    
    
    bool createPath(string path, int value) {
        vector<string> res = splitString(path);
        
        if(res.size() == 1){
            TrieNode* node = root;
            return insert(node, res[0], value);
        } else{
            
            TrieNode* node = root;
            string target = res.back();
            
            for(int i=0;i<res.size()-1;i++){
                if(node->memo.find(res[i]) == node->memo.end()) return false;
                node =node->memo[res[i]];
            }
            
            if(!insert(node, target, value)) return false;
            return true;
        }
    }
    
    int get(string path) {
        TrieNode* node = root;
        vector<string> res = splitString(path);
        
        for(int i=0;i<res.size();i++){
            if(node->memo.find(res[i]) == node->memo.end()) return -1;
            else node = node->memo[res[i]];
        }
        return node->val;
    }
};

/**
 * Your FileSystem object will be instantiated and called as such:
 * FileSystem* obj = new FileSystem();
 * bool param_1 = obj->createPath(path,value);
 * int param_2 = obj->get(path);
 */