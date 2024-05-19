class MedianFinder {
private:
    priority_queue<int> lower; //MaxHeap for smaller subtree
    priority_queue <int, vector<int>, greater<int>> higher; //MinHeap for greater subtree
public:
    MedianFinder() {
        std::ios_base::sync_with_stdio(false);
        std::cout.tie(nullptr);
        std::cin.tie(nullptr);
    }
    
    void addNum(int num) {
        lower.push(num); //push the number into lower subtree

        //incase lower subtree has a element greater than higher subtree elements
        if(!lower.empty() && !higher.empty() && lower.top() > higher.top())
        {
            higher.push(lower.top());
            lower.pop();
        }

        if(lower.size() > higher.size() + 1) //Incase lower is greater than higher
        {
            higher.push(lower.top());
            lower.pop();
        }

        else if(higher.size() > lower.size() + 1) //Incase higher is greater than lower
        {
            lower.push(higher.top());
            higher.pop();
        }
    }
    
    double findMedian() {
        if(lower.size() > higher.size()) return (double)lower.top();
        if(higher.size() > lower.size()) return (double)higher.top();

        return (((double)higher.top())+((double)lower.top()))/2.0;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */