
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
        TreeNode2D (TreeNode2D && other): loson_(std::move(other.loson_))
                                          ,hison_(std::move(other.hison_))
        {
           keys_ = other.keys_; 
        }
        TreeNode2D& operator= (TreeNode2D && other) noexcept {
            loson_ = std::move(other.loson_);
            hison_ = std::move(other.hison_);
            keys_ = other.keys_;
        }

        TreeNode2D& operator= ( TreeNode2D& other) {
            keys_ = other.keys_;
            loson_ = std::move(other.loson_); 
            hison_ = std::move(other.hison_);
        }


        Point2D keys_;

        std::unique_ptr<TreeNode2D> loson_;
        std::unique_ptr<TreeNode2D> hison_;
};

class   Tree2D {
    public:
        Tree2D() = delete;
    void Insert(std::unique_ptr<TreeNode2D>&);
    private:
    bool IsNullTree() { 
        return root_==nullptr;
    }
        std::unique_ptr<TreeNode2D> root_;
};

//Todo:  move this node;
void Tree2D::Insert(std::unique_ptr<TreeNode2D>& node) {
    if (IsNullTree()) {
        root_ = std::move(node);
        //root_->keys_ = node.keys_;
        //root_->hison_ = nullptr;
        //root_->loson_ = nullptr;
        //return;
    }
    


    
};
}
