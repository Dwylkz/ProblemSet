main = print $ solve 600851475143 where
	solve x = foldl cmax 2 (f 2 x) where
		cmax a b | isPrime 2 b == True && a < b = b
						 | otherwise = a
		isPrime i x | i*i > x = True
								| x`mod`i == 0 = False
								| otherwise = isPrime (i+1) x
		f i x | i*i > x = []
					| x`mod`i == 0 = i:(x`div`i):(f (i+1) x)
					| otherwise = f (i+1) x
