#include <iostream>
#include <set>

int main() {
    int n;
    
    std::cin >> n;
    std::multiset<std::string> mset;
    std::set<std::string>      set;
    std::string                str{};
    for (auto                  i = 0; i < n; ++i) {
        std::cin >> str;
        if (!str.empty()) {
            mset.emplace(str);
            set.emplace(str);
        }
    }

    for (const auto &it : set) {
        if (mset.count(it) > 1) {
            std::cout << it << std::endl;
        }
    }
    return 0;
}