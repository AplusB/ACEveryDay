keys = "qwertyuiopasdfghjkl;zxcvbnm,./"

shift :: String->String->Char->Char
shift d (x:cs) c
  | d == "L" =
    if x == c then head cs
    else shift "L" cs c
  | otherwise =
    if head cs == c then  x
    else shift "R" cs c

solve :: String->String->String
solve d s
  | length s == 1 = [shift d keys (head s)]
  | otherwise = shift d keys (head s) : solve d (tail s)

main = do
  d <- getLine
  s <- getLine
  putStrLn (solve d s)
