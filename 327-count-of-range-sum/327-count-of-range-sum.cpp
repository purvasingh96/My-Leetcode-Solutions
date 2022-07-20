 class Solution {
public:
    int countRangeSum(vector<int>& nums, int lower, int upper) {
        int size=nums.size();
        if(size==0)  return 0;
        vector<long> sums(size+1, 0);
        for(int i=0; i<size; i++)  sums[i+1]=sums[i]+nums[i];
        return help(sums, 0, size+1, lower, upper);
    }
    
    /*** [start, end)  ***/
    int help(vector<long>& sums, int start, int end, int lower, int upper){
        /*** only-one-element, so the count-pair=0 ***/
        if(end-start<=1)  return 0;
        int mid=(start+end)/2;
        int count=help(sums, start, mid, lower, upper)
                + help(sums, mid, end, lower, upper);
        
        int m=mid, n=mid, t=mid, len=0;
        /*** cache stores the sorted-merged-2-list ***/
        /*** so we use the "len" to record the merged length ***/
        vector<long> cache(end-start, 0);
        for(int i=start, s=0; i<mid; i++, s++){
            /*** wrong code: while(m<end && sums[m++]-sums[i]<lower);  ***/
            while(m<end && sums[m]-sums[i]<lower) m++;
            while(n<end && sums[n]-sums[i]<=upper) n++;
            count+=n-m;
            /*** cache will merge-in-the-smaller-part-of-list2 ***/
            while(t<end && sums[t]<sums[i]) cache[s++]=sums[t++];
            cache[s]=sums[i];
            len=s;
        }
        
        for(int i=0; i<=len; i++)  sums[start+i]=cache[i];
        return count;
    }
};