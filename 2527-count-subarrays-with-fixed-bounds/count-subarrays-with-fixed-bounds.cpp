class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        long long res = 0; //Store the result
        //EVery number in a subarray mmust be between minK and maxK if not it will make a bad_idx
        int bad_idx = -1, left=-1,right=-1; 

        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]<minK || nums[i]>maxK) bad_idx = i; //find bad index
            if(nums[i]==minK) left = i; //find index of lower number
            if(nums[i]==maxK) right = i; //find index of higher number

            res+= max(0,min(left,right)-bad_idx); 
            //Till we do not find both and left and right min will always be -1
            //And overall if bad_idx is potitve whole value will be negitive since -
            //If bad_idx is negitive i can never be below -1
            //Effective value will be -1 - (-1) = 0// thus not affecting the answer
            //In the event that the left part is ever negitive it will be zero
        }   
        return res;
    }
};