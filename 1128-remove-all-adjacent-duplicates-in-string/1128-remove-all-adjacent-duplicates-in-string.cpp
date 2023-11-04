class Solution {
public:
    string removeDuplicates(string s) {
        std::stack<char> stack;

    for (char c : s) {
        if (!stack.empty() && stack.top() == c) {
            stack.pop();
        } else {
            stack.push(c);
        }
    }

    std::string result;
    while (!stack.empty()) {
        result = stack.top() + result;
        stack.pop();
    }

    return result;
    }
};