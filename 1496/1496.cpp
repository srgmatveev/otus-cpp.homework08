#include <iostream>
#include <cctype>
#include <map>
#include <string>

int main(int argc, char const *argv[])
{
    std::size_t n{0};
    std::map<std::string, std::size_t> commits;
    std::string tmp_str{};
    std::cin >> n;
    for (std::size_t i = 0; i < n; ++i)
    {
        std::cin >> tmp_str;
        ++commits[tmp_str];
    }

    for (auto &item : commits)
    {
        if (item.second > 1)
            std::cout << item.first << std::endl;
    }
    return 0;
}
