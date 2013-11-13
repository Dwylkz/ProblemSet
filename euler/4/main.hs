main = print solve where
  solve = maximum [x*y | x<-[100..999], y<-[100..999], x < y, look (x*y)] where
    look x = show x == reverse (show x)
