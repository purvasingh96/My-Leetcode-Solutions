class TrieNode{
public:
    map<string, TrieNode*> m;
    bool is_fp;
    string content;
    
    TrieNode(){
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
        path = path.substr(1);
        stringstream ss(path);
        string t;
        vector<string> res;
        
        while(getline(ss, t, '/')){
            res.push_back(t);    
        }
        
        return res;
    }
    
    vector<string> ls(string path) {
        vector<string> res = split(path);
        TrieNode* node= root;
        for(int i=0;i<res.size();i++){
            node = node->m[res[i]];
        }
        
        if(node->is_fp) return {res.back()};
        
        vector<string> ans;
        for(auto it:node->m){
            ans.push_back(it.first);
        }
        
        sort(ans.begin(), ans.end());
        return ans;
    }
    
    void mkdir(string path) {
        TrieNode* node = root;
        vector<string> res = split(path);
        for(int i=0;i<res.size();i++){
            if(node->m.find(res[i]) == node->m.end()) {
                node->m[res[i]] = new TrieNode();
            }
            node = node->m[res[i]];
        }
        
    }
    
    void addContentToFile(string filePath, string content) {
        TrieNode* node = root;
        vector<string> res = split(filePath);
        for(int i=0;i<res.size();i++){
            if(node->m.find(res[i]) == node->m.end()){
                node->m[res[i]] = new TrieNode();
            }
            node = node->m[res[i]];
        }
        node->is_fp = true;
        node->content += content;
    }
    
    string readContentFromFile(string filePath) {
        TrieNode* node = root;
        vector<string> res = split(filePath);
        for(int i=0;i<res.size();i++){
            node = node->m[res[i]];
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