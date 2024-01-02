def calculate_probability(dc, bonus_min=0, bonus_max=0, advantage=False, dice_sides=20):
    calcfailprob = lambda b: max(1, dc - b - 1) / dice_sides
    factor = {True: 2, False: 1}.get(advantage, 1)
    prob_min = max(1 - calcfailprob(bonus_min) ** factor, 0)
    prob_max = max(1 - calcfailprob(bonus_max) ** factor, 0)
    return {"min": prob_min, "max": prob_max, "total": (prob_max + prob_min) / 2}


if __name__ == "__main__":
    dc = int(input("Enter the Difficulty Class (DC): "))
    bonus_min = int(input("Enter the minimum bonus: "))
    bonus_max = int(input("Enter the maximum bonus: "))
    advantage = int(input("Is there an advantage? (0 for no, 1 for yes): "))
    dice_sides = 20

    probability = calculate_probability(dc, bonus_min, bonus_max, advantage, dice_sides)
    print(probability)
