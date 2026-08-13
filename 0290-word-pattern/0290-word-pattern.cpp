class Solution {
public:
    bool wordPattern(string pattern, string s) {
        unordered_map<char, string> m;
        unordered_set<string> se;
        stringstream ss(s);
        string word;
        vector<string> words;

        while (ss >> word) {
            words.push_back(word);
        }

        if (pattern.size() != words.size())
            return false;
        for (int i = 0; i < words.size(); i++) {
            if (m.count(pattern[i])) {

                if (m[pattern[i]] != words[i])
                    return false;
            } else {
                if (se.contains(words[i]))
                    return false;
                m[pattern[i]] = words[i];
                se.insert(words[i]);
            }
        }
        return true;
    }
};