main = print $ solve 0 1 where
	solve a b
		| b > 4000000 = 0
		| b`mod`2 == 0 = b+solve b (a+b)
		| otherwise = solve b (a+b)
