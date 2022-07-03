/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        vector<vector<int>> dp(m, vector<int>(n, -1));
        int row=0, col=0, rf=m-1, cf=n-1;
        
        while(head && row<=rf && col<=cf){
            
            if(row<=rf){
                for(int j=col;j<=cf && head;j++){
                    dp[row][j] = head->val;
                    head=head->next;
                }
                row+=1;
            }
            
            if(col<=cf){
                for(int i=row;i<=rf && head;i++){
                    dp[i][cf] = head->val;
                    head=head->next;
                }
                cf-=1;
            }
            if(row<=rf){
                for(int j=cf;j>=col && head;j--){
                    dp[rf][j] = head->val;
                    head=head->next;
                }
                rf-=1;
            }
            
            if(col<=cf){
                for(int i=rf;i>=row && head;i--){
                    dp[i][col] = head->val;
                    head=head->next;
                }
                col+=1;
            }
            
        }
        
        return dp;
    }
};