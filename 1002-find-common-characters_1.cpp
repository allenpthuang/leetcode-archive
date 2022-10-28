class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        const int CHAR_SET = 26;
        int count_among_words[CHAR_SET];
        for (int i = 0; i < CHAR_SET; i++) {
            count_among_words[i] = INT_MAX;
        }
        for (const auto& word : words) {
            int count_per_word[CHAR_SET] = {0};
            for (const auto& c : word) {
                count_per_word[c - 'a']++;
            }
            for (int i = 0; i < CHAR_SET; i++) {
                if (count_per_word[i] < count_among_words[i]) {
                    count_among_words[i] = count_per_word[i];
                }
            }
        }
        vector<string> result;
        for (int i = 0; i < CHAR_SET; i++) {
            while (count_among_words[i] > 0) {
                char c = i + 'a';
                result.push_back(string(1, c));
                count_among_words[i]--;
            }
        }
        return result;
    }
};

/* retrieved from submitted codes */
