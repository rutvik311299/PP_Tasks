import unittest

# Function to check if a number is a palindrome
def is_palindrome(n):
    # Convert the number to a string
    num_str = str(n)
    
    # Check if the string is equal to its reverse
    return num_str == num_str[::-1]

# Unit test class to test the palindrome function
class TestPalindrome(unittest.TestCase):
    
    def test_palindrome(self):
        # Test case 1: A known palindrome
        self.assertTrue(is_palindrome(121))  # Should return True
        
        # Test case 2: A known non-palindrome
        self.assertFalse(is_palindrome(123))  # Should return False
        
        # Test case 4: A large palindrome
        self.assertTrue(is_palindrome(12321))  # Should return True
        
        
# Run the unit tests
if __name__ == '__main__':
    unittest.main()
