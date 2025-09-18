class Solution {
  public:
    vector<int> nextGreater(vector<int> &arr) {   // 👈 renamed
        vector<int> newArr;
        int n = arr.size();
        for(int i=0;i<n;i++) newArr.push_back(arr[i]);
        for(int i=0;i<n;i++) newArr.push_back(arr[i]);

        n = newArr.size();
        stack<int> st;
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && st.top()<=newArr[i]) st.pop();
            int t=newArr[i];
            newArr[i] = st.empty()? -1 : st.top();
            st.push(t);
        }
        while(newArr.size()>arr.size()) newArr.pop_back();
        return newArr;
    }
};
