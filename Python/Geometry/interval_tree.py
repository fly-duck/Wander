import random
class TreeNode:
    def __init__(self,data):
        self.left = None
        self.right = None
        self.mid = self.median_number(data) 
        self.interval = []
        self.sorted_lend_list =[]
        self.sorted_rend_list =[]
    # avoid sorting 
    def median_number(self,data):
        endpoints = []
        for endpoint in data:
            small_end= endpoint[0]
            big_end= endpoint[1]
            endpoints.append(small_end)
            endpoints.append(big_end)
        endpoints.sort()
        median_point = int(len(endpoints)/4)
        return endpoints[median_point]
    def search(self,vertical_line):
        split = 'left' if vertical_line > self.mid else 'right' 
        intersection = []
        if split == 'left':
            for interval in self.sorted_lend_list:
                if interval[0] > vertical_line:
                    return 
                if interval[0] <= vertical_line and interval[1] >= vertical_line:
                    intersection.append(interval)
        elif split == 'right':
            for interval in self.sorted_rend_list:
                if interval[1] < vertical_line:
                    return 
                if interval[0] <= vertical_line and interval[1] >= vertical_line:
                    intersection.append(interval)
        return intersection




class IntervalTree:
    def __init__(self,data):
        self.root = TreeNode(data)
        self.left_tree = None
        self.right_tree = None
        self.data = data
    def build_tree(self):
        crossing_mid = []
        completely_left = []
        completely_right = []
        for elem in self.data:
            assert(len(elem)==2)
            if elem[0] <= self.root.mid and self.root.mid <= elem[1]:
                crossing_mid.append(elem)
                continue
            if elem[0] > self.root.mid:
                completely_left.append(elem)
                continue
            if elem[1] < self.root.mid: 
                completely_right.append(elem)
                continue
        self.root.interval = crossing_mid[:]
        # sort by increasing small_end 
        crossing_mid.sort(key = lambda endpoint: endpoint[0])
        # python can't do this x = y.sort() because y.sort() is operation and return None
        self.root.sorted_lend_list = crossing_mid[:]
        # sort by decreasing big_end
        crossing_mid.sort(key = lambda endpoint: -endpoint[1])
        self.root.sorted_rend_list = crossing_mid[:]
        if completely_left: 
            self.left_tree = IntervalTree(completely_left)
            self.left_tree.build_tree()
        if completely_right:
            self.right_tree= IntervalTree(completely_right)
            self.right_tree.build_tree()
    def intersection_check(self,vertical_line):
        intersections = self.root.search(vertical_line)
        if vertical_line > self.root.mid:
            intersections = intersections + self.right_tree.root.search(vertical_line)
        else:
            intersections = intersections + self.left_tree.root.search(vertical_line)
        return intersections
        

            

             
        

if __name__ == "__main__":
    n = 10
    intervals = []
    start_points = [random.randrange(10) for i in range(n)]
    for point in start_points:
        end_point = point +random.randint(1,5)
        interval = [point,end_point]
        intervals.append(interval)
    print(intervals)
    tree = IntervalTree(intervals)
    tree.build_tree()
    vertical_line = 2
    print(tree.intersection_check(vertical_line))


        


