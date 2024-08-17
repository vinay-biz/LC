class Solution {
public:
    double findMedianSortedArrays(vector<int>& a, vector<int>& b) {
        int n1 = a.size();
        int n2 = b.size();

        //Make sure the array we are gonna perform binary search on is nums1
        if(n1 > n2) return findMedianSortedArrays(b, a);

        //we binary search the smaller array to find how to partiton the elements
        //For example if the size is 9, median will be at 4, so if we partiton the
        //First array at 2, we know that we will take 2 elements from next array
        //We have to find the point where the arrays become sorted
        int low = 0, high = n1;
        int left = (n1 + n2 + 1) / 2; //where the median would be in merged array (odd)
        int n = n1 + n2; //Total size of merged array

        while(low <= high)
        {
            int mid1 = (low + high)/2; //Where to partiton the left smaller array
            int mid2 = left - mid1; //required element for median - elemnts chosen from nums1

            int l1 = INT_MIN, l2= INT_MIN; //Incase they point to a blank cell
            int r1 = INT_MAX, r2= INT_MAX;//Incase they point to a blank cell

            if(mid1 < n1) r1 = a[mid1];
            if(mid2 < n2) r2 = b[mid2];
            if(mid1-1 >= 0) l1 = a[mid1-1];
            if(mid2-1 >= 0) l2 = b[mid2-1];

            if(l1 <= r2 && l2 <= r1)
            {
                if(n%2 == 1) return max(l1, l2);
                return ((double)(max(l1,l2)+min(r1,r2)))/2.0;
            }

            else if(l1 > r2) high = mid1-1;
            else low = mid1+1;
        }

        return 0; //never visited
    }
};