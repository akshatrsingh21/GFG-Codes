class Solution {
public:
    vector<string> res;

    vector<string> possibleWords(vector<int>& arr) {
        // mapping numbers with letters
        vector<string> NumtoCharMap = {
            "", "", "abc", "def", "ghi", "jkl",
            "mno", "pqrs", "tuv", "wxyz"
        };

        string path;
        backtrack(arr, 0, path, NumtoCharMap);
        return res;
    }

private:
    void backtrack(vector<int>& arr, int idx, string& path, vector<string>& NumtoCharMap) {
        if (idx == arr.size()) {
            res.push_back(path);
            return;
        }
        int digit = arr[idx];

        if (digit >= 2 && digit <= 9) {
            for (char ch : NumtoCharMap[digit]) {
                path.push_back(ch);
                backtrack(arr, idx + 1, path, NumtoCharMap);
                path.pop_back(); // backtrack
            }
        } else {
            // skip invalid digits
            backtrack(arr, idx + 1, path, NumtoCharMap);
        }
    }
};
