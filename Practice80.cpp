#include <iostream>
#include <string>
#include <vector>
#include <algorithm> // For reverse() function

using namespace std;

/*
 * Function: compress
 * -------------------
 * Compresses the input character vector `s` using run-length encoding.
 * Example:
 * Input:  ['a','a','b','b','b']
 * Output: ['a','2','b','3']  -> new length = 4
 *
 * Parameters:
 *  - s: reference to a vector of characters to be compressed.
 *
 * Returns:
 *  - The length of the compressed vector.
 */
int compress(vector<char> &s)
{
    int index = 0;   // Position to write compressed characters in `s`
    int count = 1;   // Count occurrences of each character
    char prev = s[0]; // Store the first character for comparison

    // Traverse the vector starting from the 2nd character
    for (int i = 1; i < s.size(); i++)
    {
        if (s[i] == prev)
        {
            // Same as previous character → increase count
            count++;
        }
        else
        {
            // Write the previous character to the compressed position
            s[index++] = prev;

            // If count > 1, convert it to characters and store
            if (count > 1)
            {
                int start = index; // Track start position of count digits
                while (count)
                {
                    // Convert last digit of count to a character and add to vector
                    s[index++] = (count % 10) + '0';
                    count /= 10; // Remove the last digit
                }
                // Reverse the count digits because they were added in reverse order
                reverse(s.begin() + start, s.begin() + index);
            }

            // Move to the new character
            prev = s[i];
            count = 1; // Reset count for the new character
        }
    }

    // Handle the last group of characters
    s[index++] = prev;
    if (count > 1)
    {
        int start = index; // Track position for reversing digits later
        while (count)
        {
            s[index++] = (count % 10) + '0';
            count /= 10;
        }
        reverse(s.begin() + start, s.begin() + index);
    }

    return index; // Return length of compressed string
}

int main()
{
    // Example vector of characters
    vector<char> s = {'a', 'a', 'b', 'b', 'b'};

    // Call compress() and store new compressed length
    int newLength = compress(s);

    // Print the compressed characters
    for (int i = 0; i < newLength; i++)
    {
        cout << s[i];
    }

    return 0;
}
