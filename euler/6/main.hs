main = print solve where
  x = sum [1..100]
  solve = x*x-sum [x*x | x <- [1..100]]
