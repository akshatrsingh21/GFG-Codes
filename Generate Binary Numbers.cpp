#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Function to generate binary numbers from 1 to N
    vector<string> generateBinary(int n) {
        vector<string> ans;
        queue<string> q;
        
        // start with "1"
        q.push("1");

        for (int i = 1; i <= n; i++) {
            string curr = q.front();
            q.pop();
            
            ans.push_back(curr);

            // generate next numbers by appending "0" and "1"
            q.push(curr + "0");
            q.push(curr + "1");
        }
        return ans;
    }
};
