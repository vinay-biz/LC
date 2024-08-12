class KthLargest {
    priority_queue <int, vector<int>, greater<int>> pq;
    int sz;
public:
    KthLargest(int k, vector<int>& nums) {
        sz = k;
        for(int i=0; i<nums.size(); i++)
        {
            if(pq.empty() || pq.size()  < k) pq.push(nums[i]);

            else if(pq.size() == k && nums[i] > pq.top())
            {
                pq.pop();
                pq.push(nums[i]);
            }
        }
    }
    
    int add(int val) {
        if(pq.empty() || pq.size()  < sz) pq.push(val);

        else if(pq.size() == sz && val > pq.top())
        {
            pq.pop();
            pq.push(val);
        }

        return pq.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */

 //4 5 8 2

 // 9 10 8   