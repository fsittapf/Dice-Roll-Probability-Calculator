#include <stdio.h>
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

int main() {
    int dc;
    int bonus_min;
    int bonus_max;
    int advantage;
    const int dice_sides = 20;
    double prob_min, prob_max, total;

    printf("Enter the Difficulty Class (DC): ");
    scanf("%d", &dc);
    printf("Enter the minimum bonus: ");
    scanf("%d", &bonus_min);
    printf("Enter the maximum bonus: ");
    scanf("%d", &bonus_max);
    printf("Is there an advantage? (0 for no, 1 for yes): ");
    scanf("%d", &advantage);

    calculate_probability(dc, bonus_min, bonus_max, advantage, dice_sides, &prob_min, &prob_max, &total);
    printf("Probability Min: %f\n", prob_min);
    printf("Probability Max: %f\n", prob_max);
    printf("Total Probability: %f\n", total);

    return 0;
}
