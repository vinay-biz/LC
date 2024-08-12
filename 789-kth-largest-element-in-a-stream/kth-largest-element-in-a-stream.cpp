class KthLargest {
    priority_queue <int, vector<int>, greater<int>> pq;
    int sz;
public:
    KthLargest(int k, vector<int>& nums) {
        std::ios_base::sync_with_stdio(false);
        std::cout.tie(nullptr);
        std::cin.tie(nullptr);
        sz = k;
        
        for(int i=0; i<nums.size(); i++)
        {
            pq.push(nums[i]);
            if(pq.size() > k) pq.pop();
        }
    }
    
    int add(int val) {
        pq.push(val);
        if(pq.size() > sz) pq.pop();
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