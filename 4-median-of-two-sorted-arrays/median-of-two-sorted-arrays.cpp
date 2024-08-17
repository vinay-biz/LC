class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans;
        int p1 = 0;
        int p2 = 0;

        while(p1 != nums1.size() && p2 != nums2.size())
        {
            if(nums1[p1] < nums2[p2])
            {
                ans.push_back(nums1[p1]);
                p1++;  
            }

            else
            {
                ans.push_back(nums2[p2]);
                p2++;
            }
        }

        if(p1 == nums1.size())
        {
            while(p2 != nums2.size())
            {
                ans.push_back(nums2[p2]);
                p2++;
            }
        }
        else
        {
            while(p1 != nums1.size())
            {
                ans.push_back(nums1[p1]);
                p1++;
            }
        }

        int n = ans.size();
        int mid = n/2;
        if(n%2 != 0) return (double)ans[mid];
        else return (double)((double)ans[mid-1]+(double)ans[mid])/2.0;
    }
};