def calculate_probability(dc, bonus_min=0, bonus_max=0, advantage=False):
    docalc = lambda b: 1 - (max(0, (dc - b - 1)) + 1) / 20
    docalcadvantage = lambda b: 1 - (max(0, (dc - b - 1)) ** 2 + 1) / 20**2
    if advantage:
        prob_max = docalcadvantage(bonus_max)
        prob_min = docalcadvantage(bonus_min)
    else:
        prob_max = docalc(bonus_max)
        prob_min = docalc(bonus_min)

    return {"min": prob_min, "max": prob_max, "total": (prob_max + prob_min) / 2}


if __name__ == "__main__":
    dc = 30
    bonus_min = 11
    bonus_max = 14
    advantage = 0

    probability = calculate_probability(dc, bonus_min, bonus_max, advantage)
    print(probability)
