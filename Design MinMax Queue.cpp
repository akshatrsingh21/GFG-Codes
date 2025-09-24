#include <bits/stdc++.h>
using namespace std;

class SpecialQueue {
    queue<long long> q;        // main queue
    deque<long long> min_q;    // monotonic increasing deque
    deque<long long> max_q;    // monotonic decreasing deque

public:
    // Function to enqueue an element x in the queue
    void enqueue(long long x) {
        q.push(x);

        // maintain increasing deque for min
        while (!min_q.empty() && min_q.back() > x) {
            min_q.pop_back();
        }
        min_q.push_back(x);

        // maintain decreasing deque for max
        while (!max_q.empty() && max_q.back() < x) {
            max_q.pop_back();
        }
        max_q.push_back(x);
    }

    // Function to dequeue front element from the queue
    void dequeue() {
        if (!q.empty()) {
            long long val = q.front();
            q.pop();

            if (!min_q.empty() && min_q.front() == val) {
                min_q.pop_front();
            }
            if (!max_q.empty() && max_q.front() == val) {
                max_q.pop_front();
            }
        }
    }

    // Function to get the front element
    long long getFront() {
        if (!q.empty()) return q.front();
        return -1; // queue empty
    }

    // Function to get the minimum element
    long long getMin() {
        if (!min_q.empty()) return min_q.front();
        return -1; // queue empty
    }

    // Function to get the maximum element
    long long getMax() {
        if (!max_q.empty()) return max_q.front();
        return -1; // queue empty
    }
};
