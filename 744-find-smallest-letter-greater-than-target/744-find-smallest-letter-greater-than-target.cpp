class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        int left=0, right=letters.size();
        while(left<right) {
            int mid = left + (right-left)/2;
            if(letters[mid] <= target){
                left=mid+1;
            } else{
                right=mid;
            }
        }
        
        return letters[left%(int)(letters.size())];
    }
};