main = print solve where
  solve = foldr (\a b -> a`div`(gcd a b)*b) 1 [1..20]
