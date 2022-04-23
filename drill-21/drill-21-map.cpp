#include <iostream>
#include <stdexcept>
#include <map>
#include <string>
#include <numeric>
#include <algorithm>

// 5. Reads value pairs from cin
void f(std::map<std::string, int>& m)
{
    std::string s;
    int i = 0;

    while (m.size() < 10) {
        std::cin >> s >> i;
        m.insert(std::make_pair(s, i));
    }
}

// 3. Output the pairs to cout
template<typename T, typename U>
void print(const std::map<T,U>& m)
{
    std::cout << "Elemek:" << '\n'
              << "---------" << '\n';

    for (const auto& a : m)
        std::cout << a.first << '\t' << a.second << '\n';

    std::cout << "END" << "\n\n";
}

int main()
try {
    // 1. Define a map
    std::map<std::string, int> msi;

    // 2. Insert 10 pairs into map
    msi["Valami0"] = 4;
    msi["Valami1"] = 36;
    msi["Valami2"] = 3;
    msi["Valami3"] = 74;
    msi["Valami4"] = 63;
    msi["Valami5"] = 68;
    msi["Valami6"] = 32;
    msi["Valami7"] = 22;
    msi["Valami8"] = 19;
    msi["Valami9"] = 7;

    // 3. Output the pairs
    print(msi);

    // 4. Erase the (name,value) pairs from msi.
    msi.erase(msi.begin(), msi.end());

    print(msi);

    // 6. Read ten pairs from input and enter them into msi.
    f(msi);

    // 7. Write the elements from msi to std::cout
    print(msi);

    // 8. Output the sum of the integer values in msi
    int total = std::accumulate(msi.begin(), msi.end(), 0,
            [](int sum, const std::pair<std::string,int>& p)
            { return sum += p.second; });

    std::cout << "Total of integers: " << total << '\n';

    // 9. Define a map<int,string>
    std::map<int, std::string> mis;

    // 10. Enter values from msi into mis
    for (const auto& a : msi)
        mis[a.second] = a.first;

    // 11. Output the elements of mis
    print(mis);
}
catch(std::exception& e) {
    std::cerr << "Exception: " << e.what() << '\n';
    return 1;
}
catch(...) {
    std::cerr << "Unknown exception\n";
    return 2;
}

