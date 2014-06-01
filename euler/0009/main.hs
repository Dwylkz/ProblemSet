main = print $ solve where
  solve = [a*b*(1000-a-b) | a <- [1..332], b <- [(a+1)..664], a*a+b*b == (1000-a-b)*(1000-a-b)]
