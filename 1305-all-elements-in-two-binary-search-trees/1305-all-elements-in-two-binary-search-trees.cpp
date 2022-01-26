/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void inorder(TreeNode* root, vector<int>& traversal) {
	if(!root) return;
	if(root) {
		inorder(root->left, traversal);
		traversal.push_back(root->val);
		inorder(root->right, traversal);	
}

}

vector<int> merge(vector<int> list1, vector<int> list2) {
		
	int i = 0, j=0;
    
    vector<int> l1 = list1;
    vector<int> l2 = list2;

    if(l1.size() != l2.size()) {
        l1 = list1.size() > list2.size() ? list1:list2;
	    l2 = list1.size() < list2.size() ? list1:list2;
    } 
    
        
    for(auto x:l1) {
        cout<<x<<" ";
    }
    
    for(auto x:l2) {
        cout<<x<<" ";
    }
    
	
	vector<int> res;
	
    
    
	while(i < l1.size() && j < l2.size()) {
		if(l1[i] < l2[j]) {
			res.push_back(l1[i]);
            i+=1;
		} else if(l1[i] == l2[j]) {
			res.push_back(l1[i]);
            res.push_back(l1[i]);
            i+=1;
            j+=1;
		} else {
            res.push_back(l2[j]);
			j+=1;
		}

	}
    
    if(i < l1.size()) {
        
        while(i<l1.size()) {
            res.push_back(l1[i]);
            i+=1;
        }
        
    } else if(j < l2.size()) {
        
        while(j < l2.size()) {
            res.push_back(l2[j]);
            j+=1;
        }
        
    }

	return res;
}

vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
	
	vector<int> traversal1;
    vector<int> traversal2;

	inorder(root1, traversal1);
	inorder(root2, traversal2);
	
    return merge(traversal1, traversal2);
        
    }



};