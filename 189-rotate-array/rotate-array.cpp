class Solution {
public:
    void rotate(vector<int>& nums, int k) {
         ios_base::sync_with_stdio(false);
      k = k % nums.size(); // if the array size is 7 and k=7 it means rotating the array by k will result in same array , so array will only be rotated when k is not a multiple of the size of array , it reduces the number of operations needs to be performed.in this method the time complexity is O(n) , and space is O(1)
      reverse(nums.begin() , nums.begin()+nums.size()-k);
      reverse(nums.begin()+(nums.size()-k) , nums.end());
      reverse(nums.begin(), nums.end());
    }
};