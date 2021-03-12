def latest(scores):
    return scores[-1]


def personal_best(scores):
    return max(scores)


def personal_top_three(scores):
    if len(scores) < 4:
        scores.sort(reverse=True)
        return scores
    top = []
    for num in range(3):
        top.append(max(scores))
        scores.remove(max(scores))
    
    return top
