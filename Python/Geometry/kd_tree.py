
class TreeNode:
    def __init__(self,data):
        self.loson = None
        self.hison = None
        self.data = data 
        self.disc = 0
    def Print(self):
        print(self.data)

#def successor(TreeNode p, TreeNode q):
#    if p.data[disc] != q.data[disc]:
#        return 




class KdTree:
    def __init__(self,node=None):
        self.root = node
        self.loson = None 
        self.hison= None 
    def insert(self,node):
        if self.root == None:
            self.root = node
            self.root.disc = 0
            self.root.loson = None
            self.root.hison = None
            return 
        else:
            node.disc +=1
            node.disc %= len(node.data)
            if self.root.data[node.disc] <= node.data[node.disc]:
                if self.root.hison == None:
                    self.root.hison = KdTree(node)
                else:
                    self.root.hison.insert(node)
            if self.root.data[node.disc] > node.data[node.disc]:
                if self.root.loson == None:
                    self.root.loson = KdTree(node) 
                else:
                    self.root.loson.insert(node)
    def dump_tree(self,node=None):
        if node != None:
            print()
        if self.root.loson !=None:
            self.dump_tree(self.root.loson)
        if self.root.hison!=None:
            self.dump_tree(self.root.hison)
        return
    
def DumpTree(Tree,value):
    if Tree == None:
        return
    if Tree.root!=None:
        print(value)
        print(Tree.root.data)
    else:
        return
    DumpTree(Tree.root.loson,'left')
    DumpTree(Tree.root.hison, 'right')

if __name__ == "__main__":
    data = [1,2,3]
    node = TreeNode(data)
    data1 = [-2,2,3]
    node1 = TreeNode(data1)
    tree = KdTree()
    tree.insert(node)
    tree.insert(node1)
    data3 = [0,1,2]
    node3 = TreeNode(data3)
    tree.insert(node3)
    data4 = [-1,1,2]
    node4 = TreeNode(data4)
    tree.insert(node4)
    DumpTree(tree,'root')