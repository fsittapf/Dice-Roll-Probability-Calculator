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
    int dc;
    int bonusMin;
    int bonusMax;
    bool advantage;
    const int diceSides = 20;

    std::cout << "Enter the Difficulty Class (DC): ";
    std::cin >> dc;
    std::cout << "Enter the minimum bonus: ";
    std::cin >> bonusMin;
    std::cout << "Enter the maximum bonus: ";
    std::cin >> bonusMax;
    std::cout << "Is there an advantage? (0 for no, 1 for yes): ";
    std::cin >> advantage;

    ProbabilityResult probabilities = calculateProbability(dc, bonusMin, bonusMax, advantage, diceSides);
    
    std::cout << "Probability Min: " << probabilities.min << std::endl;
    std::cout << "Probability Max: " << probabilities.max << std::endl;
    std::cout << "Total Probability: " << probabilities.total << std::endl;

    return 0;
}