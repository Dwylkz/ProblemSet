main = print solve where
  solve = [x | x <- [2..], null [y | y <- [2..sqrtn x], x`mod`y == 0]]!!10000 where
    sqrtn = fromInteger . floor . sqrt . fromInteger
