class MedianFinder {
public:
    // Max-heap (left half of the data)
    priority_queue<int> leftMaxHeap;
    // Min-heap (right half of the data)
    priority_queue<int, vector<int>, greater<int>> rightMinHeap;

    // Constructor
    MedianFinder() {
        // No need to fix anything in the constructor itself; we'll handle balancing in addNum
    }

    // Method to add a number to the data stream
    void addNum(int num) {
        // Always add to leftMaxHeap first
        if (leftMaxHeap.empty() || num <= leftMaxHeap.top()) {
            leftMaxHeap.push(num);
        } else {
            rightMinHeap.push(num);
        }

        // Rebalance the heaps to ensure their sizes differ at most by 1
        if (leftMaxHeap.size() > rightMinHeap.size() + 1) {
            // Move the top of leftMaxHeap to rightMinHeap
            rightMinHeap.push(leftMaxHeap.top());
            leftMaxHeap.pop();
        } else if (rightMinHeap.size() > leftMaxHeap.size()) {
            // Move the top of rightMinHeap to leftMaxHeap
            leftMaxHeap.push(rightMinHeap.top());
            rightMinHeap.pop();
        }
    }

    // Method to find the median of the data stream
    double findMedian() {
        // If leftMaxHeap has more elements, return the top of it
        if (leftMaxHeap.size() > rightMinHeap.size()) {
            return leftMaxHeap.top();
        } else {
            // If both heaps are balanced, return the average of the tops of both heaps
            return (leftMaxHeap.top() + rightMinHeap.top()) / 2.0;
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
