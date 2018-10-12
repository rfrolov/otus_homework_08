#include <iostream>
#include <set>

int main() {
    int         m{}, n{};
    std::size_t cnt{};
    
    std::cin >> m;
    std::set<std::string> set{};
    std::string           str{};

    for (auto i = 0; i < m; ++i) {
        std::cin >> str;
        if (!str.empty()) {
            set.emplace(str);
        }
    }

    std::cin >> n;
    for (auto i = 0; i < n; ++i) {
        std::cin >> str;
        if (set.find(str) != set.end()) {
            ++cnt;
        }
    }

    std::cout << cnt;
    return 0;
}