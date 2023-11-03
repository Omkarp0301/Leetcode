class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if (s1.length() > s2.length()) {
            return false;
        }

        vector<int> s1_count(26, 0);
        vector<int> s2_count(26, 0);

        // Calculate the frequency of characters in s1 and the initial window in s2
        for (int i = 0; i < s1.length(); i++) {
            s1_count[s1[i] - 'a']++;
            s2_count[s2[i] - 'a']++;
        }

        for (int i = s1.length(); i < s2.length(); i++) {
            if (s1_count == s2_count) {
                return true;
            }

            // Update the character count for the new character entering the window
            s2_count[s2[i] - 'a']++;

            // Remove the count of the character leaving the window
            s2_count[s2[i - s1.length()] - 'a']--;
        }

        // Check the last window
        return s1_count == s2_count;
    }
};
