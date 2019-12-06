#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

bool isPalindrone(string word, int i, int k) {
    if (k > 1) {
        return word.at(i) == word.at(i + k - 1) && isPalindrone(word, i + 1, k - 2);
    } else {
        return true;
    }
}

int main() {
    string input;

    // Read from stdin until EOF
    while (cin >> input) {
        size_t substring_length = input.size();
        vector<vector<bool>> substringIsPalindrone(input.size(), vector<bool>(input.size() + 1));
        for (size_t i = 0; i < input.size(); ++i) {
            for (size_t j = 1; j <= substring_length; ++j) {
                string substring = input.substr(i, j );
                //cout << "Checking if " << substring << " is a palindrone" << endl;
                bool result = isPalindrone(substring, 0, substring.size());
                substringIsPalindrone.at(i).at(j) = result;
                /*
                if (result == true) {
                    cout << i << " to " << j << " is a palindrone" << endl;
                } else {
                    cout << i << " to " << j << " is not a palindrone" << endl;
                }*/
            }
            --substring_length;
        }

        string test;
        string string_cuts;
        int number_of_cuts = 0;
        int i = 0;
        int j = 0;
        while (test != input) {
            i = substringIsPalindrone.at(j).size() - 1;
            if (j == 0) {
                while(substringIsPalindrone.at(j).at(i) != true) {
                    //cout << "i is " << i << endl;
                    --i;
                }
                string_cuts = input.substr(j, i);
                test += input.substr(j, i);
                j = i;
                //cout << "String cut to " << string_cuts << endl;
            } else {
                while(substringIsPalindrone.at(j).at(i) != true) {
                    //cout << "i is " << i << endl;
                    //cout << "j is " << j << endl;
                    //cout << "j at i is " << substringIsPalindrone.at(j).at(i) << endl;
                    --i;
                }
                string_cuts += "|";
                string_cuts += input.substr(j, i);
                test += input.substr(j, i);
                //cout << i << " + 1 is" << i + 1 << endl; 
                j = j + i;
                ++number_of_cuts;
                //cout << "String cut to " << string_cuts << endl;
            }
        }

        cout << number_of_cuts << " " << string_cuts << endl;

        /*
        for (size_t i = substringIsPalindrone.size() - 1; i >= 0; --i) {
            for (size_t j = substringIsPalindrone.at(i).size(); j >= 0; --j) {

            }
        }*/
    }
}