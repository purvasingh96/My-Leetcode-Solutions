class TrieNode {
public:
    bool is_fp;
    string content;
    unordered_map<string, TrieNode*> children;
    TrieNode() {
        is_fp=false;
        content = "";
    }
};

class FileSystem {
public:
    TrieNode* root;
    FileSystem() {
        root = new TrieNode();
    }
    
    vector<string> split(string path){
        vector<string> res;
        path = path.substr(1);
        
        stringstream ss(path);
        string s;
        
        while(getline(ss, s, '/')){
            res.push_back(s);
        }
        
        return res;
    }
    
    vector<string> ls(string path) {
        TrieNode* node = root;
        vector<string> res = split(path);
        
        for(int i=0;i<res.size();i++){
            node = node->children[res[i]];
        }
        
        if(node->is_fp) return {res.back()};
        
        vector<string> ans;
        for(auto x:node->children){
            ans.push_back(x.first);
        }
        
        sort(ans.begin(),ans.end());
        return ans;
        
    }
    
    void mkdir(string path) {
        TrieNode* node = root;
        vector<string> res = split(path);
        
        for(int i=0;i<res.size();i++){
            if(node->children.find(res[i]) == node->children.end()){
                node->children[res[i]] =  new TrieNode();
            }
            node = node->children[res[i]];
        }
    }
    
    void addContentToFile(string filePath, string content) {
        TrieNode* node = root;
        vector<string> res = split(filePath);
        
        for(int i=0;i<res.size();i++){
            if(node->children.find(res[i]) == node->children.end()){
                node->children[res[i]] =  new TrieNode();
            }
            node = node->children[res[i]];
        }
        
        
        node->is_fp = true;
        node->content += content;
    }
    
    string readContentFromFile(string filePath) {
        TrieNode* node = root;
        vector<string> res = split(filePath);
        for(int i=0;i<res.size();i++){
            node = node->children[res[i]];
        }
        
        return node->content;
    }
};

/**
 * Your FileSystem object will be instantiated and called as such:
 * FileSystem* obj = new FileSystem();
 * vector<string> param_1 = obj->ls(path);
 * obj->mkdir(path);
 * obj->addContentToFile(filePath,content);
 * string param_4 = obj->readContentFromFile(filePath);
 */