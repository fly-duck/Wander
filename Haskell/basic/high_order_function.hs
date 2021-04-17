
twice f(x) = f(f(x))

newmap f xs = [f x | x<- xs] 


newfilter p xs = [x | x <- xs , p x ]
