class Node{
public:
    unordered_map<string, Node*> children;
    int val;
    Node() {
        val=-1;
    }
    
};
class FileSystem {
private:
    Node* root;
    vector<string> splitString(string path){
        vector<string> res;
        path = path.substr(1);
        
        stringstream ss(path);
        string s;
        
        while(getline(ss, s, '/')){
            res.push_back(s);
        }
        
        return res;
    }
    
public:
    FileSystem() {
        root = new Node();
    }
    
    bool insertWord(Node* temp, string word, int val){
        
        if(temp->children.find(word)==temp->children.end()){
            temp->children[word] = new Node();
        }
        //cout<<"insertion done";
        if(temp->children[word]->val!=-1) return false;
        temp->children[word]->val = val;
        return true;
    }
    
    bool createPath(string path, int val) {
        vector<string> words = splitString(path);

        //cout<<words.size()<<"\n";
        
        if(words.size()==1) {
            Node* temp =root;
            return insertWord(temp, words[0], val);
            
        } else {
            Node* temp = root;
            string targetWord = words.back();
            
            for(int i=0;i<words.size()-1;i++){
                
                    if(temp->children.find(words[i]) == temp->children.end()) return false;
                    else temp = temp->children[words[i]];
                
            }
            
            if(!insertWord(temp, targetWord, val)) return false;
        }
        return true;
    }
    
    int get(string path) {
        Node* temp = root;
        vector<string> words = splitString(path);
        
        
        for(auto word:words){
            //cout<<"word: "<<word;
            
                //cout<<c<<"\n";
                if(temp->children.find(word) == temp->children.end()) return -1;
                else temp = temp->children[word];
            
        }
        //cout<<" temp->val: "<<temp->val<<"\n";
        return temp->val;
    }
};

/**
 * Your FileSystem object will be instantiated and called as such:
 * FileSystem* obj = new FileSystem();
 * bool param_1 = obj->createPath(path,value);
 * int param_2 = obj->get(path);
 */