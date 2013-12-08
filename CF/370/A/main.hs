solve [r1, c1, r2, c2] = [moveRock, moveBishop, moveKing] where
  dr = abs $ r1-r2
  dc = abs $ c1-c2
  moveRock
    | dr > 0 && dc > 0 = 2
    | dr > 0 || dc > 0 = 1
  moveBishop
    | (r1+c1)`mod`2 /= (r2+c2)`mod`2 = 0
    | dr == dc = 1
    | otherwise = 2
  moveKing = max dr dc

main = do
  buff <- getLine
  putStrLn $ unwords $ map show $ solve $ map (read :: String -> Int) $ words buff
