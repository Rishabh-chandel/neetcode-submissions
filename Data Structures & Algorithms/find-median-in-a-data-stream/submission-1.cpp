class MedianFinder {
public:
    priority_queue<int> maxhp;
    priority_queue<int,vector<int>,greater<int>> minhp;
    MedianFinder() {}
    
    void addNum(int num) {
        if(maxhp.empty() || num < maxhp.top()) 
            maxhp.push(num);
        else minhp.push(num);
        if(maxhp.size() > minhp.size() + 1) {
            minhp.push(maxhp.top());
            maxhp.pop();
        }
        else if(maxhp.size() < minhp.size()){
            maxhp.push(minhp.top());
            minhp.pop();
        }
    }
    
    double findMedian() {
        if (maxhp.size() == minhp.size())
            return ((double)maxhp.top() + (double)minhp.top()) / 2.0;
        return (double)maxhp.top();
    }
};
