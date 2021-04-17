n= a `div` length xs 
     where 
     a =10
     xs = [1,2,3,4,5]

last xs = head (reverse xs)

init xs = take (length xs -1) xs 


-- abs :: Int -> Int 
abs n = if n>=0 then n else -n 

myPrime n = factors n == [1,n]

factors n = [x|x<-[1..n],n `mod` x == 0]

halve a  = (take n a , drop n a)
            where n = length a `div` 2  

halve2 a  = splitAt (length a `div` 2 ) a 


third (_:_:x:_) = x


-- charpter 4

safetail xs = if null xs then [] else tail xs 

safetail2  xs | null xs = []
            | otherwise = tail xs 


safetail3 [] = [] 
safetail3 (_:xs) = xs  


False || False = False 
_     || _     = True
