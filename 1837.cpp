#include <vector>
#include <cstring>
#include <map>
#include <deque>
#include <iostream>
#include <algorithm>

int main() {
    std::vector<std::string>                         ans{};
    std::map<std::string, long long>                 to{}, used{}, dp{};
    std::map<std::string, std::vector<std::string> > g{};
    long long                                        n{}, i{};
    std::string                                      a{}, b{}, c{};
    std::deque<std::string>                          dk{};

    std::cin >> n;
    for (i = 0; i < n; ++i) {
        std::cin >> a >> b >> c;

        g[a].emplace_back(b);
        g[a].emplace_back(c);

        g[b].emplace_back(a);
        g[b].emplace_back(c);

        g[c].emplace_back(a);
        g[c].emplace_back(b);

        ans.emplace_back(a);
        ans.emplace_back(b);
        ans.emplace_back(c);

    }

    dp["Isenbaev"]   = 1;
    used["Isenbaev"] = 1;
    dk.emplace_back("Isenbaev");

    while (!dk.empty()) {
        std::string id = dk.front();
        dk.pop_front();
        for (i = 0; i < g[id].size(); ++i) {
            if (used[g[id][i]] == 0) {
                used[g[id][i]] = 1;
                to[g[id][i]]   = dp[id];
                dp[g[id][i]]   = dp[id] + 1;
                dk.emplace_back(g[id][i]);
            }
        }
    }

    std::sort(ans.begin(), ans.end());

    ans.emplace_back("");
    for (i = 0; i < ans.size() - 1; ++i) {
        if (ans[i] != ans[i + 1]) {
            if (to[ans[i]] != 0 || ans[i] == "Isenbaev") {
                std::cout << ans[i] << " " << to[ans[i]] << '\n';
            } else {
                std::cout << ans[i] << " " << "undefined" << '\n';
            }
        }
    }

    return 0;
}