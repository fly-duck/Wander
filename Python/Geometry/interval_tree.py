import random
class TreeNode:
    def __init__(self,data):
        self.left = None
        self.right = None
        self.mid = self.median_number(data) 
        self.interval = []
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
        print(endpoints)
        print(median_point)
        return endpoints[median_point]
    def build_tree(self,data):
        return


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
        self.root.interval = crossing_mid
        if completely_left: 
            self.left_tree = IntervalTree(completely_left)
            self.left_tree.build_tree()
        if completely_right:
            self.right_tree= IntervalTree(completely_right)
            self.right_tree.build_tree()
        

if __name__ == "__main__":
    n = 10
    intervals = []
    start_points = [random.randrange(10) for i in range(10)]
    for point in start_points:
        end_point = point +random.randint(1,5)
        interval = [point,end_point]
        intervals.append(interval)
    print(intervals)
    tree = IntervalTree(intervals)
    tree.build_tree()


        


