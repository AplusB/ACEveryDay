
f :: Int -> [Int] -> [Int]
f n arr --Fill up this function
  | null arr = []
  | head arr < n = head arr : f n (tail arr)
  | otherwise = f n (tail arr)

-- The Input/Output section. You do not need to change or modify this part
main = do 
    n <- readLn :: IO Int 
    inputdata <- getContents 
    let
        numbers = map read (lines inputdata) :: [Int]
    putStrLn . unlines $ (map show . f n) numbers
