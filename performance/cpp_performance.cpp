#include <iostream>
#include <vector>
#include <chrono>
#include <algorithm>
#include <numeric>
#include <cmath>

struct ProbabilityResult {
    double min;
    double max;
    double total;
};

ProbabilityResult calculateProbability(int dc, int bonusMin, int bonusMax, bool advantage, int diceSides) {
    double factor = advantage ? 2 : 1;
    double failProbMin = std::max(1, dc - bonusMin - 1) / static_cast<double>(diceSides);
    double failProbMax = std::max(1, dc - bonusMax - 1) / static_cast<double>(diceSides);

    double probMin = std::max(1 - std::pow(failProbMin, factor), 0.0);
    double probMax = std::max(1 - std::pow(failProbMax, factor), 0.0);
    double total = (probMax + probMin) / 2;

    return {probMin, probMax, total};
}

std::vector<ProbabilityResult> test_function() {
    std::vector<ProbabilityResult> results;
    results.reserve(34 * 14 * 20);

    for (int dc = 2; dc <= 35; dc++) {
        for (int bonus_min = -2; bonus_min <= 11; bonus_min++) {
            for (int bonus_max = 0; bonus_max <= 19; bonus_max++) {
                auto result = calculateProbability(dc, bonus_min, bonus_max, true, 20);
                results.emplace_back(result);
            }
        }
    }
    return results;
}

int main() {
    const int n = 20;
    std::vector<double> listtime;
    listtime.reserve(n);

    for (int i = 0; i < n; i++) {
        auto start = std::chrono::high_resolution_clock::now();
        auto results = test_function();
        auto end = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> elapsed = end - start;
        listtime.push_back(elapsed.count());
    }

    double minTime = *std::min_element(listtime.begin(), listtime.end());
    double maxTime = *std::max_element(listtime.begin(), listtime.end());
    double sumTime = std::accumulate(listtime.begin(), listtime.end(), 0.0);
    std::cout << "Min: " << minTime << " - Max: " << maxTime << " - Mean: " << sumTime / n << std::endl;

    return 0;
}
