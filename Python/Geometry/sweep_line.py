import random
import math
import sys
from PIL import Image, ImageDraw



class PriorityQueue:
    def __init__(self,intervals):
        self.intervals = intervals 
    def CompareonY(self,i,j):
        if self.intervals[i][1]>self.intervals[j][1]: 
            return True
        elif self.intervals[i][1] == self.intervals[j][1]:
            return self.intervals[i][0] < self.intervals[j][0]
        return False 
    # max heapify an array to store intervals as priority queue
    def MaxHeapify(self,i):
        left = i<<1
        right = (i<<1) +1
        largest = i
        if left< len(self.intervals) and self.CompareonY(left,largest):
            largest = left   
        if right< len(self.intervals) and self.CompareonY(right,largest):
            largest = right
        if largest != i:
            self.intervals[largest],self.intervals[i] = self.intervals[i],self.intervals[largest]
            self.MaxHeapify(largest)
    def BuildHeap(self):
        for i in range(math.floor(len(self.intervals)/2),-1,-1):
            self.MaxHeapify(i) 
        return self.intervals
    def PopMaxKey(self):
        if len(self.intervals)<1:
            raise ValueError("Can not pop a empty heap")
        max = self.intervals[0]
        # store value of last element and then remove it 
        self.intervals[0] = self.intervals[-1]
        self.intervals.pop()
        self.MaxHeapify(0)
        return max
    def HeapIncreaseKey(self,i,interval):
        if interval[1] < self.intervals[i][1]:
            raise ValueError("Insert Error")
        self.intervals[i] = interval 
        while (i > 0 and self.intervals[i>>1][1] < interval[1]):
            parent = i>>1
            self.intervals[parent],self.intervals[i] = self.intervals[i],self.intervals[parent]
            i = parent
    def InsertNewInterval(self,interval):
        self.intervals.append((~sys.maxsize,~sys.maxsize))
        self.HeapIncreaseKey(len(self.intervals)-1,interval)











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
    priorityqueue =  PriorityQueue(eventpoints)
    priorityqueue.BuildHeap()
    print(priorityqueue.intervals)
    #draw.line(((30, 200), (130, 100), (80, 50)), fill=(255, 255, 0))
    #draw.line(((80, 200), (180, 100), (130, 50)), fill=(255, 255, 0), width=10)
    im.show()
