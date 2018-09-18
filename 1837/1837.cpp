#include <string>
#include <iostream>
#include <set>
#include <cctype>
#include <queue>
#include <map>
#include <string>

int main(int argc, char const *argv[])
{
std::set<std::string> familes{};
    std::map<std::string, std::vector<std::string>> graph{};
    std::map<std::string, std::size_t> result;
    std::map<std::string, std::size_t> used;
    std::queue<std::string> queue;
    std::string Isenbaev = "Isenbaev";
    std::string testData{"7"};
    std::size_t n{0};
    std::ios::sync_with_stdio(false);
    std::cin >> n;

    std::string a, b, c;

    for (std::size_t i = 0; i < n; ++i)
    {
        std::cin >> a >> b >> c;
        graph[a].emplace_back(b);
        graph[a].emplace_back(c);

        graph[b].emplace_back(a);
        graph[b].emplace_back(c);

        graph[c].emplace_back(a);
        graph[c].emplace_back(b);
        familes.emplace(a);
        familes.emplace(b);
        familes.emplace(c);
    }

    auto is_found = graph.find(Isenbaev);
    if (is_found != graph.cend())
    {
        used[Isenbaev] = 1;
        result[Isenbaev] = 1;
        std::size_t group_number = 1;
        queue.push(Isenbaev);
        while (!queue.empty())
        {
            std::string id = queue.front();
            queue.pop();
            for (auto i = 0; i < graph[id].size(); ++i)
            {
                if (used[graph[id][i]] == 0)
                {
                    used[graph[id][i]] = 1;

                    result[graph[id][i]] = result[id] + 1;
                    queue.push(graph[id][i]);
                }
            }
        }
    }
   

    std::size_t result_item{0};
    for (auto &item : familes)
    {
        result_item = result[item];
        if (!result_item)
            std::cout << item << " "
                      << "undefined\n";
        else
            std::cout << item << " "
                      << result_item - 1 << "\n";
    }
    return 0;
}
