class Solution {
public:
    // Function to find largest rectangle area in a histogram
    int largestRectangleArea(vector<int>& heights) {
        stack<int> st;
        int maxArea = 0;
        int n = heights.size();
        
        for (int i = 0; i <= n; i++) {
            int h = (i == n ? 0 : heights[i]);
            while (!st.empty() && h < heights[st.top()]) {
                int height = heights[st.top()];
                st.pop();
                int width = (st.empty() ? i : i - st.top() - 1);
                maxArea = max(maxArea, height * width);
            }
            st.push(i);
        }
        return maxArea;
    }

    // Function to find maximal rectangle in a binary matrix
    int maxArea(vector<vector<int>> &mat) {
        if (mat.empty()) return 0;
        
        int n = mat.size(), m = mat[0].size();
        vector<int> height(m, 0);
        int maxRect = 0;

        for (int i = 0; i < n; i++) {
            // Update histogram heights
            for (int j = 0; j < m; j++) {
                if (mat[i][j] == 0) height[j] = 0;
                else height[j] += 1;
            }
            // Compute largest rectangle in current histogram
            maxRect = max(maxRect, largestRectangleArea(height));
        }
        return maxRect;
    }
};
