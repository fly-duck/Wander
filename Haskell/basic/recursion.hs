

fac 0 = 1 
fac n = n * fac (n -1 ) 


myproduct [] = 2
myproduct(n : xs) = n * myproduct(xs)



randomop []  = 0
randomop ( e : xs) = randomop(xs) - e 

newinsert x [] = [x]
newinsert x (y:ys) | x <=y = x:y:ys
                   | otherwise = y: newinsert x ys

newdrop 0 xs = xs 
newdrop _ [] = []
newdrop n xs = newdrop (n-1) xs 


sumdown 0 = 0
sumdown n = sumdown(n-1) + n 

a *^ 1 = 0 
a *^ n = a *(a *^ (n-1))
