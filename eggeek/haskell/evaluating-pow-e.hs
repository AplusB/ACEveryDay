factor :: Int -> Int
factor n
  | n == 0 = 1
  | otherwise = n * factor (n-1)

subsolve :: Double -> Int -> Double
subsolve x n
  | n == 9 = x ** fromIntegral n / fromIntegral (factor n)
  | otherwise = x ** fromIntegral n / fromIntegral (factor n) +
                subsolve x (n+1)

solve :: Double -> Double
solve x = -- Insert your code here --
  subsolve x 0
main :: IO ()
main = getContents >>= mapM_ print. map solve. map (read::String->Double). tail. words
