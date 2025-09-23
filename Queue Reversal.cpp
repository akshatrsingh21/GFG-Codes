class Solution
{
    public:
    // Function to reverse the queue in-place.
    void reverseQueue(queue<int> &q)
    {
        if(q.empty())
            return;
        
        // Take front element out
        int x = q.front();
        q.pop();
        
        // Recur for the rest of the queue
        reverseQueue(q);
        
        // Push element back at the end
        q.push(x);
    }
};
