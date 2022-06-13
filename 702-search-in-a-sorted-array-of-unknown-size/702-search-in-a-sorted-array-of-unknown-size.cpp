/**
 * // This is the ArrayReader's API interface.
 * // You should not implement it, or speculate about its implementation
 * class ArrayReader {
 *   public:
 *     int get(int index);
 * };
 */

class Solution {
public:
    int search(const ArrayReader& reader, int target) {
        int start=0, end=10001;
        
        // cout<<end;
        
        while(start<end){
            
            int mid = start + (end-start)/2;
            int val = reader.get(mid);
            if(val == target){
                return mid;
            } else if(val > target){
                end=mid;
            } else{
                start = mid+1;
            }
            
        }
        
        if(reader.get(start) == target) return start;
        
        return -1;
    }
};