#include <bits/stdc++.h>

struct pair_hash {
    template <typename T1, typename T2>
    std::size_t operator()(const std::pair<T1, T2>& pair) const {
        auto hash1 = std::hash<T1>{}(pair.first);
        auto hash2 = std::hash<T2>{}(pair.second);
        return hash1 ^ (hash2 << 1);
    }
};

std::unordered_map<std::pair<long, long>, long, pair_hash> memo;

long count(long x, int d = 75) {
    if (d == 0) return 1;
    
    if (memo.count({x, d})) {
        return memo[{x, d}];
    }

    if (x == 0) return count(1, d - 1);

    int l = std::to_string(x).length();

    long result = 0;

    if (l % 2 != 0) {
        result = count(x * 2024, d - 1);
    } else {
        long divisor = std::pow(10, l / 2);
        long first_half = x / divisor;
        long second_half = x % divisor;
        
        result = count(first_half, d - 1) + count(second_half, d - 1);
    }

    memo[{x, d}] = result;

    return result;
}

int main() {
    long num;
    long sum = 0;

    while (std::cin >> num) {
        sum += count(num);
    }

    std::cout << sum << std::endl;

    return 0;
}
