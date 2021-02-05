#include <iostream>
#include <string>
#include <vector>
#include <cmath>

double myPow(int a, int b)
{
    int var = 1;
    int i = 0;

    while (i++ < b)
        var *= a;

    return var;
}

int main()
{
    const int n = 6;
    std::string familiarWords[n] = { "hallo", "klempner", "das", "ist", "fantastisch", "fluggegecheimen" };

    std::vector<char> familiarLetters;

    bool isExist = 1;

    /*
    * filling the vector with known words
    */

    for(int i = 0; i < n; i++) // word
        for (int j = 0; j < familiarWords[i].length(); j++) // char
        {
            for (auto k = familiarLetters.begin(); k < familiarLetters.end(); k++) // is there in the vector
                if (*k == familiarWords[i][j])
                    isExist = 0;

            if (isExist)
                familiarLetters.push_back(familiarWords[i][j]);

            isExist = 1;
        }

    /*
    * end of filling the vector with known words
    */
    
    std::string stopWord;
    std::cin >> stopWord;

    /*
    * checking if there is a letter in the stop word among known letters
    */
    
    std::vector<bool> arr(stopWord.length());

    for (int i = 0; i < stopWord.length(); i++)
        arr[i] = 0;

    for (int i = 0; i < stopWord.length(); i++)
        for (auto k = familiarLetters.begin(); k < familiarLetters.end(); k++)
            if (*k == stopWord[i])
            {
                arr[i] = 1;
                break;
            }

    isExist = 1;
    for (int i = 0; i < stopWord.length(); i++)
        isExist *= arr[i];

    /*
    * end of checking if there is a letter in the stop word among known letters
    */

    if (isExist)
        std::cout << pow(double(1) / familiarLetters.size(), stopWord.length());
    else
        std::cout << 0;

    return 0;
}
