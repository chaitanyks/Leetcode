
class MedianFinder {
public:
    priority_queue<int, vector<int>, greater<int> > minHeap;
    // priority_queue<int> minHeap;
    priority_queue<int> maxHeap;
    int count = 0;

    MedianFinder() {

    }

    void addNum(int num) {
        count++;
        int m = minHeap.size();
        int n = maxHeap.size();
        // cout<<n<<" "<<m<<" ";
        if (n == 0) {
            maxHeap.push(num);
            return;
        }

        if (n == m) {
            int val = minHeap.top();
            if (val < num) {
                minHeap.pop();
                minHeap.push(num);
                maxHeap.push(val);
            } else {
                maxHeap.push(num);
            }
        } else {
            int val = maxHeap.top();
            if (val > num) {
                // cout<<val<<" ";
                maxHeap.pop();
                minHeap.push(val);
                maxHeap.push(num);
            } else {
                minHeap.push(num);
            }
        }
        // cout<<maxHeap.top()<<" "<<minHeap.top()<<endl;
    }


    double findMedian() {
        int m = minHeap.size();
        int n = maxHeap.size();
        // cout<<n<<" "<<m<<" ";
        double val = maxHeap.top();
        double ans = val;

        if (n == m) {
            double val2 = minHeap.top();
            // cout<<val<<" "<<val2<<"|";
            ans = (val + val2) / 2;
        }

        return ans;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
