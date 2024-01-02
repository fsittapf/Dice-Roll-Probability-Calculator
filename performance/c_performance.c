#include <stdio.h>
#include <time.h>
#include <math.h>

double calculate_fail_probability(int dc, int bonus, int dice_sides) {
    return fmax(1, dc - bonus - 1) / dice_sides;
}

void calculate_probability(int dc, int bonus_min, int bonus_max, int advantage, int dice_sides, double *prob_min, double *prob_max, double *total) {
    double factor = advantage ? 2 : 1;
    double fail_prob_min = calculate_fail_probability(dc, bonus_min, dice_sides);
    double fail_prob_max = calculate_fail_probability(dc, bonus_max, dice_sides);

    *prob_min = fmax(1 - pow(fail_prob_min, factor), 0);
    *prob_max = fmax(1 - pow(fail_prob_max, factor), 0);
    *total = (*prob_max + *prob_min) / 2;
}

void test_function(double results[][4], int *size) {
    int index = 0;
    for (int dc = 2; dc <= 35; dc++) {
        for (int bonus_min = -2; bonus_min <= 11; bonus_min++) {
            for (int bonus_max = 0; bonus_max <= 19; bonus_max++) {
                double prob_min, prob_max, total;
                calculate_probability(dc, bonus_min, bonus_max, 1, 20, &prob_min, &prob_max, &total);
                results[index][0] = dc;
                results[index][1] = bonus_min;
                results[index][2] = bonus_max;
                results[index][3] = total;
                index++;
            }
        }
    }
    *size = index;
}

int main() {
    const int n = 20;
    double results[11934][4];
    int size;
    double minTime = INFINITY, maxTime = 0, sumTime = 0;

    for (int i = 0; i < n; i++) {
        clock_t start = clock();
        test_function(results, &size);
        clock_t end = clock();
        double time_spent = (double)(end - start) / CLOCKS_PER_SEC;
        minTime = fmin(minTime, time_spent);
        maxTime = fmax(maxTime, time_spent);
        sumTime += time_spent;
    }

    printf("Min: %f - Max: %f - Mean: %f\n", minTime, maxTime, sumTime / n);
    return 0;
}

