main :: IO ()
main = getContents >>= return . solve >>= putStr

solve :: String -> String
solve input = show
	-- $ maximum
	-- $ map product
	-- $ genSegs
	-- $ map ((map read) . words)
	$ lines input where

		genSegs :: [[Int]] -> [[Int]]
		genSegs mt = iter coors2 where
			r = length mt
			c = (length $ mt!!0)

			coors2 = [(x, y) | x <- [0..(r-1)], y <- [0..(c-1)]]

			iter :: [(Int, Int)] -> [[Int]]
			iter [] = []
			iter ((x, y):cs) = (map gen4 [(0, 1), (1, 1), (1, 0)]) ++ (iter cs) where
				
				gen4 (dx, dy) = [mt!!tx!!ty | (tx, ty) <- [(x+dx*i, y+dy*i) | i <- [1..4]], tx < r, ty < c]
