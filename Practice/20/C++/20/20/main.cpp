#include <iostream>
#include <vector>
#include <string>

struct alcohol
{
    std::string name{""};
    int price{0};
    int v{0};
    double benefit{0};
    int counter{0};
};

int main()
{
    int n; // money
    std::cin >> n;

    int k; // number of drinks
    std::cin >> k;
    
    std::vector<alcohol> arr(k);

    for (int i = 0; i < k; i++)
    {
        std::string name;
        std::cin >> name;
        arr[i].name = name;

        int price;
        std::cin >> price;
        arr[i].price = price;

        int v;
        std::cin >> v;
        arr[i].v = v;

        arr[i].benefit = double(v) / price;
    }

    std::cout << '\n';

    // bubble sort
    for (int i = 0; i < k - 1; i++)
        for (int j = 0; j < k - i - 1; j++)
            if (arr[j].benefit < arr[j + 1].benefit)
            {
                auto temp1 = arr[j].benefit;
                arr[j].benefit = arr[j + 1].benefit;
                arr[j + 1].benefit = temp1;

                auto temp2 = arr[j].name;
                arr[j].name = arr[j + 1].name;
                arr[j + 1].name = temp2;

                auto temp3 = arr[j].v;
                arr[j].v = arr[j + 1].v;
                arr[j + 1].v = temp3;

                auto temp4 = arr[j].price;
                arr[j].price = arr[j + 1].price;
                arr[j + 1].price = temp4;
            }

    for (int i = 0; i < k; i++)
        while (n - arr[i].price > 0)
        {
            arr[i].counter++;
            n -= arr[i].price;
        }

    for (int i = 0; i < k; i++)
    {
        if (arr[i].counter)
        {
            std::cout << arr[i].name << ' ' << arr[i].counter << '\n';
            std::cout << arr[i].v * arr[i].counter << '\n';
        }
    }

    std::cout << n;

    return 0;
}
