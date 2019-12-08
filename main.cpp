#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

/***************************************************************************
 * Author: Christopher Moyer
 * Date: December 8th, 2019
 *
 * This program will take in a string from stdin and chop it up into a
 * palindrone using the least amount of cuts possible. If the string is
 * already a palindrone, the string will be just be reprinted.
 *
**/


bool isPalindrone(string word, int i, int k) {
    if (k > 1) {
        return word.at(i) == word.at(i + k - 1)
               && isPalindrone(word, i + 1, k - 2);
    } else {
        return true;
    }
}

int main() {
    string input;

    // Read from stdin until EOF
    while (cin >> input) {
        // Check if each possible substring of the string is a palindrone
        // and store the result in a vector
        size_t substring_length = input.size();
        // 1st Dimension is starting index of the substring
        // 2nd Dimension is the length of the substring
        vector<vector<bool>> substringIsPalindrone(input.size(),
                                       vector<bool>(input.size() + 1));
        for (size_t i = 0; i < input.size(); ++i) {
            for (size_t j = 1; j <= substring_length; ++j) {
                string substring = input.substr(i, j);
                bool result = isPalindrone(substring, 0, substring.size());
                substringIsPalindrone.at(i).at(j) = result;
            }
            --substring_length;
        }

        string test;
        string string_cuts;
        int number_of_cuts = 0;
        int i = 0;
        int j = 0;

        // Find the smallest number of cuts to make the string a palindrone.
        // This loop the subtring at index 0, and finds the longest possible
        // palindrone starting at that index. The function moves the index
        // after the previous cut and continues looking for the largest
        // possible palindrone all cuts have been completed
        while (test != input) {
            i = substringIsPalindrone.at(j).size() - 1;
            if (j == 0) {
                while (substringIsPalindrone.at(j).at(i) != true) {
                    --i;
                }
                string_cuts = input.substr(j, i);
                test += input.substr(j, i);
                j = i;
            } else {
                while (substringIsPalindrone.at(j).at(i) != true) {
                    --i;
                }
                string_cuts += "|";
                string_cuts += input.substr(j, i);
                test += input.substr(j, i);
                j = j + i;
                ++number_of_cuts;
            }
        }

        cout << number_of_cuts << " " << string_cuts << endl;
    }
}
