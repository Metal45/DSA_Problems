// Approach -> we create a vector items with different quantity of available items so as to ditribute it according to the order's demand 
// good test case to dry run -> nums[] = {1,1,2,2,2,2,4,4}, quantity[] = {2,2,3};


class Solution {
public:
    bool help(vector<int> &items, vector<int> &quantity, int currCustomer){
        // base case
        if(currCustomer == quantity.size()){
            return true;
        }

        // checking trough every available quality of different items
        for(int i = 0; i < items.size(); i++){

            // if item's quantity is enough to fulfill order's quantity
            if(items[i] >= quantity[currCustomer]){

                items[i] -= quantity[currCustomer];
                // recursion call for next index

                if(help(items, quantity, currCustomer + 1)){
                    return true;
                }

                // if some case fails 
                // backtracking and trying other solution
                items[i] += quantity[currCustomer];
            }
        }

        // returning false if no case fits
        return false;
    }

    bool canDistribute(vector<int>& nums, vector<int>& quantity) {
        // creating count of different available items
        map<int, int> count;
        for(int i = 0; i < nums.size(); i++){
            count[nums[i]]++;
        }

        // creating the vector of quantity of different items
        vector<int> items;
        for(auto i : count){
            items.push_back(i.second);
        }

        // optimisation (to reduce complexity)
        // to ensure the greatest quantity is checked first so if it fails we do not have to check the rest
        sort(quantity.begin(), quantity.end(), greater<int> ());

        return help(items, quantity, 0);
    }
};