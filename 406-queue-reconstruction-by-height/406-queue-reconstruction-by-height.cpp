class Solution {
public:

    //Compare function for the logic of sort
	//Sorts in descending order
    static bool compare(vector<int>& a, vector<int> & b)
    {
        if(a[0] == b[0])
            return a[1] < b[1];
        
        return a[0] > b[0];
    }
    
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {   
        int n = people.size();
        
        sort(people.begin(), people.end(), compare); //Sorting the array according to comp function.
        vector<vector<int>> res; //To store the final array to be returned
        
        for(int i = 0; i < n; i++)
        {
            int idx = people[i][1];
            res.insert(res.begin() + idx, people[i]); //Inserting the element at desired position.
        }
        
        return res;
    }
};