class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        return quickSelect(points, k);
    }
    
private:
    vector<vector<int>> quickSelect(vector<vector<int>>& points, int k) {
        int left = 0, right = points.size() - 1;
        int pivotIndex = points.size();
        while (pivotIndex != k) {
            // Repeatedly partition the vector
            // while narrowing in on the kth element
            pivotIndex = partition(points, left, right);
            if (pivotIndex < k) {
                left = pivotIndex;
            } else {
                right = pivotIndex - 1;
            }
        }
        
        // Return the first k elements of the partially sorted vector
        return vector<vector<int>>(points.begin(), points.begin() + k);
    };

    int partition(vector<vector<int>>& points, int left, int right) {
        vector<int>& pivot = choosePivot(points, left, right);
        int pivotDist = squaredDistance(pivot);
        while (left < right) {
            // Iterate through the range and swap elements to make sure
            // that all points closer than the pivot are to the left
            if (squaredDistance(points[left]) >= pivotDist) {
                points[left].swap(points[right]);
                right--;
            } else {
                left++;
            }
        }
        
        // Ensure the left pointer is just past the end of
        // the left range then return it as the new pivotIndex
        if (squaredDistance(points[left]) < pivotDist)
            left++;
        return left;
    };

    vector<int>& choosePivot(vector<vector<int>>& points, int left, int right) {
        // Choose a pivot element of the vector
        return points[left + (right - left) / 2];
    }
    
    int squaredDistance(vector<int>& point) {
        // Calculate and return the squared Euclidean distance
        return point[0] * point[0] + point[1] * point[1];
    }
};