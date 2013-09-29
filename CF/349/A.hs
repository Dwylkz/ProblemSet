import Data.List (foldl')

main = do
  n <- getLine
  a <- getLine
  let rv = (solve n $ words a)
  if snd rv == True then putStrLn "YES"
    else putStrLn "NO"

solve n xs = foldl' go ((0, 0, 0), True) xs where
  go ((_, _, _), b) "" = ((0, 0, 0), True && b)
  go ((c25, c50, c100), b) x
    | x == "100" =
        if c50 > 0 && c25 > 0 then ((c25-1, c50-1, c100+1), b)
          else if c25 > 2 then ((c25-3, c50, c100+1), b)
            else ((0, 0, 0), False)
    | x == "50" = 
        if c25 > 0 then ((c25-1, c50+1, c100), b)
            else ((0, 0, 0), False)
    | otherwise = ((c25+1, c50, c100), b)
