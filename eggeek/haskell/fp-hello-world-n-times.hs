hello_worlds n = putStrLn . unlines . replicate n$ "hello World"

-- This part is related to the Input/Output and can be used as it is
-- Do not modify it
main = do
   n <- readLn :: IO Int
   hello_worlds n
