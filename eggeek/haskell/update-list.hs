-- Enter your code here. Read input from STDIN. Print output to STDOUT

f arr -- Complete this function here
  | null arr = []
  | otherwise = abs(head arr) : f (tail arr)
-- This section handles the Input/Output and can be used as it is. Do not modify it.
main = do
   inputdata <- getContents
   mapM_ putStrLn $ map show $ f $ map (read :: String -> Int) $ lines inputdata
