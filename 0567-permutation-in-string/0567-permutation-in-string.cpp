class Solution {
private:
    bool checkEqual(int a[26], int b[26]) {
        for (int i = 0; i < 26; i++) {
            if (a[i] != b[i]) {
                return false;
            }
        }
        return true;
    }

public:
    bool checkInclusion(string s1, string s2) {
        int count1[26] = {0};
        int count2[26] = {0};
        int s1Len = s1.length();
        int s2Len = s2.length();

        if (s1Len > s2Len) {
            return false; // s1 cannot be a permutation of s2 if it's longer
        }

        // Initialize count1 and count2 for the first s1Len characters in s2
        for (int i = 0; i < s1Len; i++) {
            count1[s1[i] - 'a']++;
            count2[s2[i] - 'a']++;
        }

        for (int i = s1Len; i < s2Len; i++) {
            if (checkEqual(count1, count2)) {
                return true; // Found a permutation
            }

            // Update count2 for the sliding window
            count2[s2[i] - 'a']++;
            count2[s2[i - s1Len] - 'a']--;
        }

        return checkEqual(count1, count2); // Check for the last window
    }
};
