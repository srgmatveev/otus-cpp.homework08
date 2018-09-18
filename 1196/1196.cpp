#include <iostream>
#include <cctype>
#include <set>
#include <map>
#include <string>

int main(int argc, char const *argv[])
{
    std::size_t n{0};
    std::set<unsigned long> teacher;
    std::map<unsigned long, std::size_t> learner;
    unsigned long tmp_digit{0};
    std::cin >> n;
    for (std::size_t i = 0; i < n; ++i)
    {
        std::cin >> tmp_digit;
        teacher.insert(tmp_digit);
    }
    std::cin >> n;
    for (std::size_t i = 0; i < n; ++i)
    {
        std::cin >> tmp_digit;
        learner[tmp_digit] = ++learner[tmp_digit];
    }
    std::size_t count{0};

    for (auto &item : learner)
    {

        if (teacher.find(item.first) != teacher.cend())
        {
            count += item.second;
        }
    }
    std::cout << count << std::endl;
    return 0;
}
