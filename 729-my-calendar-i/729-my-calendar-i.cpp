class Node {
 public:
    int startDate;
    int endDate;
    Node* left;
    Node* right;
    Node(int startDate, int endDate){
        this->startDate = startDate;
        this->endDate = endDate;
        this->left=NULL;
        this->right=NULL;
    }
    
};
class MyCalendar {
public:
    Node* root;
    
    bool canBook(Node* root, int start, int end){
        if(!root) return true;
        
        if(root->startDate>=end){
            if(!root->left) return true;
            else return canBook(root->left, start, end);
        } else if(root->endDate <= start){
            if(!root->right) return true;
            else return canBook(root->right, start, end);
        }
        return false;
    }
    
    Node* update(Node* root, int start, int end){
        if(!root){
            Node* node = new Node(start, end);
            return node;
        }
        
        else if(root->startDate>=end){
            root->left = update(root->left, start, end);
        } else if(root->endDate<=start){
            root->right = update(root->right, start, end);
        }
        
        return root;
    }
    
    
    MyCalendar() {
        this->root=NULL;
    }
    
    bool book(int start, int end) {
        bool bookable = canBook(root, start, end);
        if(bookable){
            root = update(root, start, end);
        }
        return bookable;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */