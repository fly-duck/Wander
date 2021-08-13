#include <point.h>
#include <memory>

namespace Wander
{
    using Point2D = Wander::Point<int, 2>;
    using Disc = int;
    using Level = int;

    struct KeyTwo
    {
        Point2D point_;
        // and we need to setup a compare function for keys
        bool operator==(const KeyTwo &other)
        {
            return point_.GetPoint<1>() == other.point_.GetPoint<1>() && point_.GetPoint<2>() == other.point_.GetPoint<2>();
        }

        bool GreaterThan(const KeyTwo &other, size_t i)
        {
            // need to improve point implementation
            if (i == 1)
                return point_.GetPoint<1>() > other.point_.GetPoint<1>();
            return point_.GetPoint<2>() > other.point_.GetPoint<2>();
        }
    };

    struct TreeNode2D
    {
        using NodePointer = std::unique_ptr<TreeNode2D>;

    public:
        TreeNode2D(){};

        TreeNode2D(std::unique_ptr<TreeNode2D> other)
        {
            keys_ = other->keys_;
        }
        TreeNode2D(TreeNode2D &&other) : loson_(std::move(other.loson_)), hison_(std::move(other.hison_))
        {
            keys_ = other.keys_;
        }
        TreeNode2D &operator=(TreeNode2D &&other) noexcept
        {
            loson_ = std::move(other.loson_);
            hison_ = std::move(other.hison_);
            keys_ = other.keys_;
            return *this;
        }

        TreeNode2D &operator=(TreeNode2D &other)
        {
            keys_ = other.keys_;
            loson_ = std::move(other.loson_);
            hison_ = std::move(other.hison_);
            return *this;
        }

        KeyTwo GetKeys() const
        {
            return keys_;
        }

        void SetHighSon(NodePointer &node)
        {
            this->hison_ = std::move(node);
        }

        void SetLowSon(NodePointer &node)
        {
            this->loson_ = std::move(node);
        }

        NodePointer& GetHighSon()
        {
            return this->hison_;
        }

        NodePointer& GetLowSon()
        {
            return this->loson_;
        }

        // kd trees have k keys now this one is represented as point but it needs to be more general
        KeyTwo keys_;
        Disc disc_; // disc_ = k_ % 2;
        Level k_;

        // for any node p  ,  if Q in loson(p), K_j_(Q) < K_j_(P)
        std::unique_ptr<TreeNode2D> loson_;
        std::unique_ptr<TreeNode2D> hison_;
    };

    using NodePointer = std::unique_ptr<TreeNode2D>;
    class Tree2D
    {
    public:
        Tree2D() = delete;
        NodePointer Insert(std::unique_ptr<TreeNode2D> &);

    private:
        bool IsNullTree()
        {
            return root_ == nullptr;
        }

        // search node in kd tree from root
        NodePointer Search(NodePointer &insert_node)
        {
            const KeyTwo keys = insert_node->GetKeys();
            const KeyTwo root_keys = root_->GetKeys();
        }

        void TreeDump() {
            return ;
        }

        NodePointer Compare(std::unique_ptr<TreeNode2D>& p, std::unique_ptr<TreeNode2D>& q, unsigned int disc)
        {
            if (p->GetKeys() == q->GetKeys())
            {
                // to prevent copy elision here
                // need to figure out how compiler deal with this non-RVO
                return std::move(q);
            }
            else
            {
                if (p->GetKeys().GreaterThan(q->GetKeys(), disc))
                {
                    if (p->GetHighSon() == nullptr)
                        p->SetHighSon(q);
                    else {
                        return Compare(p->GetHighSon(),q,disc);
                    }
                }
                if (p->GetLowSon() == nullptr)
                    p->SetLowSon(q);
                else {
                    return Compare(p->GetLowSon(),q,disc);
                }

                return std::move(p);
            }
        }

        void MoveDown()
        {
        }

        void InsertNewNode()
        {
        }
        std::unique_ptr<TreeNode2D> root_;
        unsigned int current_disc;
    };

    //Todo:  move this node;
    NodePointer Tree2D::Insert(std::unique_ptr<TreeNode2D> &node)
    {
        // if the tree is
        if (IsNullTree())
        {
            root_ = std::move(node);
            root_->hison_ = nullptr;
            root_->loson_ = nullptr;
            //root_->keys_ = node.keys_;
            //root_->hison_ = nullptr;
            //root_->loson_ = nullptr;
            return nullptr;
        }
        return Search(node);
    };
}
