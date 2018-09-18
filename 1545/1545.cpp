#include <iostream>
#include <cctype>
#include <set>
#include <string>
#include <algorithm>
#include <iterator>
int main(int argc, char const *argv[])
{
    std::size_t n{0};
    std::set<std::string> dictionary, filter;
    std::string tmp_str{};
    std::cin >> n;
    for (std::size_t i = 0; i < n; ++i)
    {
        std::cin >> tmp_str;
        dictionary.emplace(tmp_str);
    }
    filter.clear();
    char letters_filter{};
    std::cin >> letters_filter;
    std::copy_if(dictionary.cbegin(), dictionary.cend(),
                 std::inserter(filter, filter.end()),
                 [&letters_filter](const std::string &value) {
                     return (letters_filter == value[0]);
                 });
    for (auto &item : filter)
    {
        std::cout << item << std::endl;
    }
    return 0;
}
