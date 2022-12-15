class Solution {
public:
    string simplifyPath(string path) {
        vector<string> tokens;
        stringstream ss(path);
        string tmp = "";
        while (getline(ss, tmp, '/')) {
            tokens.push_back(tmp);
        }

        stack<string> words;
        for (const auto& t : tokens) {
            if (t == ".") {
                continue;
            } else if (t == "..") {
                if (! words.empty()) {
                    words.pop();
                }
            } else if (t != "") {
                words.push(t);
            }
        }
        
        string result = "";
        while (! words.empty()) {
            result = "/" + words.top() + result;
            words.pop();
        }
        if (result.empty()) {
            result = "/";
        }
        return result;
    }
};

