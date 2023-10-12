class Solution {
public:
    bool isPalindrome(string s) {
        // Convert all characters to lowercase
        for (char &c : s) {
            c = tolower(c);
        }
        
        int left = 0, right = s.length() - 1;
        
        while (left < right) {
            // Move left pointer until an alphanumeric character is found
            while (left < right && !isalnum(s[left])) {
                left++;
            }
            
            // Move right pointer until an alphanumeric character is found
            while (left < right && !isalnum(s[right])) {
                right--;
            }
            
            // Compare the characters
            if (s[left] != s[right]) {
                return false;
            }
            
            // Move the pointers towards the center
            left++;
            right--;
        }
        
        return true;
    }
};