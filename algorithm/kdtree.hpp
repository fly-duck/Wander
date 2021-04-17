
#include <point.h>
#include <memory>

namespace Wander {
using Point2D = Wander::Point<int,2>; 

struct  TreeNode2D {
    public:
        TreeNode2D() {};


        TreeNode2D(std::unique_ptr<TreeNode2D> other){
            keys_ = other->keys_;
        }
        TreeNode2D(TreeNode2D &&) =default;

    //    TreeNode2D& operator=(TreeNode2D&) =default;

        Point2D keys_;

        std::unique_ptr<TreeNode2D> loson_;
        std::unique_ptr<TreeNode2D> hison_;
};

class   Tree2D {
    public:
        Tree2D() = delete;
    void Insert(TreeNode2D node);
    private:
    bool IsNullTree() { 
        return root_==nullptr;
    }
        std::unique_ptr<TreeNode2D> root_;
};


void Tree2D::Insert(TreeNode2D node) {
    if (IsNullTree()) {
        root_->keys_ = node.keys_;
        root_->hison_ = nullptr;
        root_->loson_ = nullptr;
        return;
    }
    


    
};
}
