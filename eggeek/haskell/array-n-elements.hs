fn :: Int->[Int]
fn n
  | n == 1 = [1]
  | otherwise = 1 : fn (n-1)
