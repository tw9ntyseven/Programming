#include <iostream>
#include <vector>

struct Roulette
{
    int num;
    int color; // 1 - red, 0 - black
    int dorp_rate;
};

int main()
{
    const int n = 37;

    Roulette arr[n];
    memset(arr, 0, sizeof(arr));


    /*
    * Start filling the array
    */

    for (int i = 1; i < n; i++)
        arr[i].num = i;

    for (int i = 1; i < 11; i++)
        arr[i].color = i % 2;
    
    arr[11].color = 0;
    
    for (int i = 12; i < 19; i++)
        arr[i].color = (i + 1) % 2;

    for (int i = 19; i < 29; i++)
        arr[i].color = i % 2;

    arr[29].color = 0;

    for (int i = 30; i < n; i++)
        arr[i].color = (i + 1) % 2;

    /*
    * End of array filling
    */

    std::vector<int> drop_rate_nums;
    for (int i = 0; i < n; i++)
        drop_rate_nums.push_back(i);

    std::pair<int, int> drop_rate_b_r; // 0 - black, 1 - red
    drop_rate_b_r.first = 0;
    drop_rate_b_r.second = 0;

    int most_drops = 0;

    int k = 3;
    int cin;
    
    while (true)
    {
        for (int j = 0; j < k; j++)
        {
            std::cin >> cin;
            if (cin < 0)
                return 0;
            if (cin > 36)
                continue;

            arr[cin].dorp_rate++;

            for (int i = 0; i < n; i++)
                if (arr[i].dorp_rate > most_drops)
                    most_drops = arr[i].dorp_rate;

            for (int i = 0; i < n; i++)
                if (arr[i].dorp_rate == most_drops)
                    std::cout << arr[i].num << ' ';
            std::cout << '\n';

            for (auto i = drop_rate_nums.begin(); i < drop_rate_nums.end(); i++)
                if (*i == cin)
                {
                    drop_rate_nums.erase(i);
                    break;
                }

            for (auto i = drop_rate_nums.begin(); i < drop_rate_nums.end(); i++)
                std::cout << *i << ' ';
            std::cout << '\n';

            arr[cin].color == 0 ? drop_rate_b_r.first++ : drop_rate_b_r.second++;

            std::cout << drop_rate_b_r.second << ' ' << drop_rate_b_r.first << "\n\n";
        }

        for (int i = 0; i < n; i++)
            arr[i].dorp_rate = 0;

        drop_rate_nums.clear();
        for (int i = 0; i < n; i++)
            drop_rate_nums.push_back(i);

        drop_rate_b_r.first = 0;
        drop_rate_b_r.second = 0;
        most_drops = 0;
    }

    return 0;
}
