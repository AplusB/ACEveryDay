
f arr  -- Fill up this function body
  | null arr = 0
  | head arr `mod` 2 == 0 = f (tail arr)
  | otherwise = head arr + f (tail arr)

-- This part handles the Input/Output and can be used as it is. Do not change or modify it.
main = do
   inputdata <- getContents
   putStrLn $ show $ f $ map (read :: String -> Int) $ lines inputdata
