
f :: [Int] -> [Int]
f lst  -- Fill up this Function
  | null lst = []
  | length lst == 1 = []
  | length lst >= 2 =
      let l = tail lst
      in head l : f (tail l)
-- This part deals with the Input and Output and can be used as it is. Do not modify it.
main = do
   inputdata <- getContents
   mapM_ (putStrLn. show). f. map read. lines $ inputdata
