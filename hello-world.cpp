#include <iostream>
#include <vector>
#include <cmath>
void simpleSieve(int n, std::vector<int> &primes)
{
    std::vector<bool> mark;
    for (int i = 0; i <= n; i++)
    {
        mark.push_back(true);
    }

    for (int p = 2; p * p <= n; p++)
    {
        for (int i = p * p; i <= n; i += p)
        {
            mark[i] = false;
        }
    }

    for (int i = 2; i <= n; i++)
    {
        if (mark[i])
        {
            primes.push_back(i);
        }
    }
}

void segmentedSieve(long long low, long long high)
{
    int range = (int)(high - low);
    std::vector<int> primes;
    int limit = (int)(floor(sqrt(high)) + 1);
    simpleSieve(limit, primes);

    std::vector<bool> mark;
    for (int i = 0; i <= high - low; i++)
    {
        mark.push_back(true);
    }
    for (int i = 0; i <= primes.size(); i++)
    {
        int lowerLimit = (int)(floor(low / primes[i]) * primes[i]);
        if (lowerLimit < low)
        {
            lowerLimit += primes[i];
        }

        if (lowerLimit == primes[i])
        {
            lowerLimit += primes[i];
        }

        for (int j = lowerLimit; j <= high; j += primes[i])
        {
            if (j != primes[i] && j)
            {
                mark[j - low] = false;
            }
        }
    }
    for (int i = low; i <= high; i++)
    {
        if (mark[i - low])
        {
            std::cout << i << " ";
        }
    }
    primes.clear();
}

int main()
{
    int T;
    long long low, high;
    std::cin >> T;
    while (T--)
    {
        std::cin >> low;
        std::cin >> high;
        segmentedSieve(low, high);
    }
    std::cout << "hello";
}
