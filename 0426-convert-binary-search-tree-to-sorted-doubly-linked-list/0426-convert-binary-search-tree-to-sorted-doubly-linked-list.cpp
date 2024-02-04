class Solution {
public:
    Node* treeToDoublyList(Node* root) {
        if(!root) return root;
        Node* head = new Node();
        Node* last = head;
        Node* node = root;
        
        while(node){
            if(node->left){
                Node* pred = node->left;
                while(pred->right && pred->right!=node){
                    pred = pred->right;
                }
                if(pred->right == NULL){
                    pred->right = node;
                    node = node->left;
                } else {
                    last->right = node;
                    node->left = last;
                    last = node;
                    node = node->right;
                }
            } else {
                last->right = node;
                node->left = last;
                last = node;
                node = node->right;
            }
        }
        
        last->right = head->right;
        head->right->left = last;
        return head->right;
        
    }
};