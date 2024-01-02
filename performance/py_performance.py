import timeit


def calculate_probability(dc, bonus_min=0, bonus_max=0, advantage=False, dice_sides=20):
    calcfailprob = lambda b: max(1, dc - b - 1) / dice_sides
    factor = {True: 2, False: 1}.get(advantage, 1)
    prob_min = max(1 - calcfailprob(bonus_min) ** factor, 0)
    prob_max = max(1 - calcfailprob(bonus_max) ** factor, 0)
    return [prob_min, prob_max, (prob_max + prob_min) / 2]


advantage = True


def test_function():
    results = []
    for dc in range(2, 36):
        for bonus_min in range(-2, 12):
            for bonus_max in range(20):
                result = calculate_probability(dc, bonus_min, bonus_max, advantage)
                results.append((dc, bonus_min, bonus_max, result))
    return results


if __name__ == "__main__":
    n = 20
    listtime = [
        timeit.timeit("test_function()", globals=globals(), number=1) for _ in range(n)
    ]
    print(f"Min: {min(listtime)} - Max: {max(listtime)} - Mean: {sum(listtime)/n}")
