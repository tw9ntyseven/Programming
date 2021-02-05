#include <iostream>
#include <string>
#include <cmath>

int F(int a) {
    if (a > 1)
        return F(a - 1) * a;
    else
        return 1;
}

void reverse(std::string& str)
{
    for (int i = 0; i < str.length() / 2; i++)
    {
        char tmp = str[i];
        str[i] = str[str.length() - 1 - i];
        str[str.length() - 1 - i] = tmp;
    }
}

std::string sys(int a, std::string str)
{
    int p = str.length();
    std::string res("");

    while (a != 0)
    {
        res += std::to_string(a % p);
        a /= p;
    }

    reverse(res);

    return res;
}

int charNum_to_int(char a)
{
    for (int i = char('0'), j = 0; i < std::numeric_limits<char>::max(); i++, j++)
        if (a == char(i))
            return j;
}

int main()
{
    int n;
    std::cin >> n;

    std::string k;
    std::cin >> k;

    std::string str("");

    for (int i = 0; i < n; i++)
        str += '0';
    
    bool tmpChecker = 1;
    std::string tmp;
    for (int a = 0; a < pow(k.length(), n); a++)
    {
        tmp = sys(a, k);
        for (int j = 0; j < tmp.length(); j++)
            str[str.length() - 1 - j] = tmp[tmp.length() - 1 - j];

        for (int j = 0; j < n; j++)
            str[j] = k[charNum_to_int(str[j])];
        
        std::cout << str << ' ';

        str = "";
        for (int i = 0; i < n; i++)
            str += '0';

        tmpChecker = 1;
    }

    std::cout << '\n';

    return 0;
}
