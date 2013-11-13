main = do
	let x = [1..999]
	print (foldl judge 0 x)
	where judge a b
		| b`mod`3 == 0 || b`mod`5 == 0 = a+b
		| otherwise = a
