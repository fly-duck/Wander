import random
import math
from PIL import Image, ImageDraw


def CompareonY(interval,i,j):
    if interval[i][1]>interval[j][1]: 
        return True
    elif interval[i][1] == interval[j][1]:
        return interval[i][0] < interval[j][0]
    return False 


# max heapify an array to store intervals as priority queue
def MaxHeapify(intervals,i):
    left = i<<1
    right = (i<<1) +1
    largest = i
    if left< len(intervals) and CompareonY(intervals,left,largest):
        largest = left   
    if right< len(intervals) and CompareonY(intervals,right,largest):
        largest = right
    if largest != i:
        intervals[largest],intervals[i] = intervals[i],intervals[largest]
        MaxHeapify(intervals,largest)
        

def BuildHeap(intervals):
    for i in range(math.floor(len(intervals)/2),0,-1):
        MaxHeapify(intervals,i) 
    return intervals








if __name__ == "__main__":
    range_value = 500
    n = 10 
    # todo : how to generate specific range number of intersections 
    startpoint_x = [random.randrange(range_value) for i in range(n)]
    startpoint_y = [random.randrange(range_value) for i in range(n)]
    endpoint_x = [random.randrange(range_value) for i in range(n)]
    endpoint_y = [random.randrange(range_value) for i in range(n)] 

    startpoints =[]
    endpoints =[]
    eventpoints=[]

    for i in range(n):
        startpoints.append((startpoint_x[i],startpoint_y[i]))
        endpoints.append((endpoint_x[i],endpoint_y[i]))
        eventpoints.append(startpoints[i])
        eventpoints.append(endpoints[i])
    im = Image.new('RGB', (500, 300), (128, 128, 128))
    draw = ImageDraw.Draw(im)
    for i in range(n):
        draw.line((startpoints[i],endpoints[i]),fill=(255,255,0))
    print(eventpoints)
    heap_array= BuildHeap(eventpoints)
    print(eventpoints)
    #draw.line(((30, 200), (130, 100), (80, 50)), fill=(255, 255, 0))
    #draw.line(((80, 200), (180, 100), (130, 50)), fill=(255, 255, 0), width=10)
    im.show()
