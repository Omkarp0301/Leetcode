class Solution {
public:
    string removeOccurrences(string s, string part) {
        int i = 0;
        int j = 0;

        while (i < s.length()) {
            if (s[i] == part[j]) {
                int k = i + 1;
                int l = j + 1;
                while (l < part.length() && k < s.length() && s[k] == part[l]) {
                    k++;
                    l++;
                }

                if (l == part.length()) {
                    s.erase(i, k - i);
                    i = 0; 
                } else {
                    i++;
                }
            } else {
                i++;
            }
        }
        return s;
    }
};
