main :: IO ()
main = do
	input <- getContents
	ls <- return $ lines input
	nm <- return $ words $ ls!!0
	l2 <- return $ words $ ls!!1
	putStr $ solve (read $ nm!!0) (read $ nm!!1) (map read l2)

solve :: Int -> Int -> [Int] -> String
solve n m as = show $ f m as where 
	f :: Int -> [Int] -> Int
	f r [] = if r < m then 1 else 0
	f 0 ls = 1 + (f m ls)
	f r all@(l:ls) = if l <= r then f (r-l) ls else 1+(f m all)
