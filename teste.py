def calc_prob(x, bmin: int = 0, bmax:int = 0, adv:bool =False):
  calcprob = lambda b: 1-min(max(0.05, (x-1-b)/20), 0.95)) ** (1 + int(adv))
  return {"min": calprob(bmin), "max": calcprob(bmax)}
