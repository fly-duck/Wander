

def point_interct_segment(point, segment):
    point1 = segment[0]
    point2 = segment[1]

    pointA = point1 if point1[1]>point1[1] else point2
    pointB = point2 if point1[1]<point2[1] else point1

    if (point[1]>pointA[1] or point[1]<pointB[1]):
        return False
    
    if (point[0]>pointA[0] and point[0] >pointB[0]):
        return False
    
    if (point[0]<=pointB[0] and point[0]<=pointA[0]):
        return True
   
    if (cal_slope(point1,pointA)>=cal_slope(pointB,pointA)):
        return True


        
# this doesn't apply to general slope
def cal_slope(point1,point2):
    if(point1[0]==point2[0]):
        return max 
    return (point1[1]-point2[1])/(point1[0]-point2[0])


def Point_in_Polygon(point,polygon):
    count = 0
    for segment in polygon:
        if(point_interct_segment(point,segment)):
           count +=1

    return count%2 == 0
