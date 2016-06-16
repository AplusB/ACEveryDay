rev :: [Int] -> [Int]
rev l
  | null l = []
  | otherwise = (last l) : (rev (init l))
