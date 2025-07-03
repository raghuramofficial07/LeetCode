class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty()) return "";

        string word = strs[0];
        for (const string& s : strs) {
            if (s.length() < word.length()) {
                word = s;
            }
        }

        for (int i = 0; i < word.length(); ++i) {
            char c = word[i];
            for (const string& s : strs) {
                if (s[i] != c) {
                    return word.substr(0, i);
                }
            }
        }

        return word;
    }
};
