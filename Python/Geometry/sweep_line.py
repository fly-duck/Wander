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
        print("Intersection : {interval}")
        self.intervals.append((~sys.maxsize,~sys.maxsize))
        self.HeapIncreaseKey(len(self.intervals)-1,interval)

class EventPoint:
    def __init__(self,eventpoint):
        self.eventpoint = eventpoint
        self.upper_segments = set() 
        self.lower_segments = set() 
        self.crossing_segments = set() 

# Todo: avoid division in this 
def GetXValueByY(segment,y):
    start_point = segment[0]
    end_point = segment[1]
    slope = 0
    if start_point[0] == end_point[0]:
        return start_point[0]
    slope = (start_point[1]-end_point[1])/(start_point[0]-end_point[0])
    b = start_point[1]-slope*start_point[0] 
    result = (y-b)/slope 
    return result 


# Todo: use Interval Search Tree to replace this
def GetNeighborSegment(segments,eventpoint):
    x = eventpoint[0]
    y = eventpoint[1]
    left_segment = None
    right_segment = None
    left_most= sys.maxsize
    right_most= sys.maxsize 
    for segment in segments:
        if segment[0][1] <= y and y <= segment[1][1]:
            intersect_x = GetXValueByY(segment,y)
            if intersect_x <= x and ((x-intersect_x)<(left_most)):
                left_most = x - intersect_x 
                left_segment = segment
            elif intersect_x >=x and ((intersect_x-x)>(right_most)):
                right_most = intersect_x-x
                right_segment = segment
    return left_segment,right_segment

# Cramer's Rule Todo : merge with GetXValueByY 
def GetIntersectionPoint(line1,line2):
    xdiff = (line1[0][0] - line1[1][0], line2[0][0] - line2[1][0])
    ydiff = (line1[0][1] - line1[1][1], line2[0][1] - line2[1][1])

    def det(a, b):
        return a[0] * b[1] - a[1] * b[0]

    div = det(xdiff, ydiff)
    if div == 0:
        return None

    d = (det(*line1), det(*line2))
    x = det(d, xdiff) / div
    y = det(d, ydiff) / div
    return (x, y)

def FindNewEvent(segment1,segment2,eventpoint,priorityqueue,event_dict):
    if segment1 == None or segment2 == None:
        return  
    x = eventpoint[0]
    y = eventpoint[1]
    intsect_point = GetIntersectionPoint(segment1,segment2)
    if intsect_point == None:
        return 
    elif intsect_point[1] < y or intsect_point[0]> x:
        aug_intsect_point = EventPoint(intsect_point) 
        priorityqueue.InsertNewInterval(intsect_point)
        if intsect_point != segment1[0] and intsect_point!= segment1[1]:
            aug_intsect_point.crossing_segments.add(segment1)
        if intsect_point != segment2[0] and intsect_point!= segment2[1]:
            aug_intsect_point.crossing_segments.add(segment2)
        event_dict[intsect_point] = aug_intsect_point
            #handle new eventpoint here

def FindLeftRightMost(upper_crossing_segments):
    left_most = None
    right_most = None
    for segment in upper_crossing_segments:
        start_point = segment[0]
        end_point = segment[1]
        left_most_slope= sys.maxsize 
        right_most_slope = ~sys.maxsize
        if start_point[0] == end_point[0]:
            slope = sys.maxsize
        else:
            slope = (start_point[1]-end_point[1])/(start_point[0]-end_point[0])
        if slope <= left_most_slope and slope >=0:
           slope = left_most_slope 
           left_most = segment
        elif slope <= 0 and slope > right_most_slope:
            right_most_slope = slope
            right_most = segment 
    return left_most, right_most 
            

        
            

        


            


    










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
    segments = set()

    for i in range(n):
        startpoints.append((startpoint_x[i],startpoint_y[i]))
        endpoints.append((endpoint_x[i],endpoint_y[i]))
        eventpoints.append(startpoints[i])
        eventpoints.append(endpoints[i])
        if startpoints[i][1]> endpoints[i][1] or (startpoints[i][1]==endpoints[i][1] and startpoints[i][0]<endpoints[i][0]):
            segments.add((startpoints[i],endpoints[i]))
        else:
            segments.add((endpoints[i],startpoints[i]))
    im = Image.new('RGB', (500, 300), (128, 128, 128))
    draw = ImageDraw.Draw(im)
    for i in range(n):
        draw.line((startpoints[i],endpoints[i]),fill=(255,255,0))
    print(eventpoints)
    priorityqueue =  PriorityQueue(eventpoints)
    priorityqueue.BuildHeap()
    print(priorityqueue.intervals)
    event_dict = {}
    # Todo: put aug_eventpoint into Heap
    for eventpoint in priorityqueue.intervals:
        aug_eventpoint = EventPoint(eventpoint) 
        for segment in segments:
            if eventpoint == segment[0]:
                aug_eventpoint.upper_segments.add(segment)
            if eventpoint == segment[1]:
                aug_eventpoint.lower_segments.add(segment)
        event_dict[eventpoint] = aug_eventpoint 
    #Todo: put segments into search tree 
    while(len(priorityqueue.intervals)!=0):
        segments_set = set() 
        event = priorityqueue.PopMaxKey()
        aug_eventpoint = event_dict[event]
        for segment in aug_eventpoint.upper_segments:
            segments_set.add(segment)
        for segment in aug_eventpoint.lower_segments:
            segments_set.add(segment)
        if len(segments_set)>1:
            print("got intersection {segments_set}")
        for segment in aug_eventpoint.lower_segments:
            segments.remove(segment)
        upper_crossing_set = set.union(aug_eventpoint.lower_segments,aug_eventpoint.upper_segments)
        if  len(upper_crossing_set) ==0:
            left_segment,right_segment = GetNeighborSegment(segments,aug_eventpoint.evenpoint)
            FindNewEvent(left_segment,right_segment,aug_eventpoint,priorityqueue,event_dict)
        else:
            left_most,right_most = FindLeftRightMost(upper_crossing_set)
            left_neighbor,right_neighbor = GetNeighborSegment(segments,aug_eventpoint.evenpoint)
            FindNewEvent(left_most,left_neighbor,aug_eventpoint,priorityqueue,event_dict)
            FindNewEvent(right_most,right_neighbor,aug_eventpoint,priorityqueue,event_dict)
            


        
        
        
        

    
    

    #draw.line(((30, 200), (130, 100), (80, 50)), fill=(255, 255, 0))
    #draw.line(((80, 200), (180, 100), (130, 50)), fill=(255, 255, 0), width=10)
    im.show()
