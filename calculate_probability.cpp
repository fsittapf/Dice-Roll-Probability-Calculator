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


int main() {
    int dc = 14;
    int bonusMin = 11;
    int bonusMax = 14;
    bool advantage = false;
    int diceSides = 20;

    ProbabilityResult probabilities = calculateProbability(dc, bonusMin, bonusMax, advantage, diceSides);
    
    std::cout << "Probability Min: " << probabilities.min << std::endl;
    std::cout << "Probability Max: " << probabilities.max << std::endl;
    std::cout << "Total Probability: " << probabilities.total << std::endl;

    return 0;
}