#include <iostream>
#include <map>
#include <algorithm>

int main() {
    int n;
    
    std::cin >> n;
    std::multimap<char, std::string> mmap;
    std::string                      str{};
    for (auto                        i = 0; i < n; ++i) {
        std::cin >> str;
        if (!str.empty()) {
            mmap.emplace(str.c_str()[0], str);
        }
    }

    char k{};
    std::cin >> k;
    auto range = mmap.equal_range(k);
    std::for_each(range.first, range.second, [](auto &it) { std::cout << it.second << std::endl; });
    return 0;
}