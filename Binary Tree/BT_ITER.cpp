#pragma once
/*Implementation of Binary Search Tree class that has iterative
member functions. */

template <typename K, typename V>
struct TreeNode
{
    K key;
    V value;
    TreeNode *lChild;
    TreeNode *rChild;

    TreeNode()
    {
        this->lChild = this->rChild = nullptr;
    }

    TreeNode(K key, V value)
    {
        this->key = key;
        this->value = value;
        this->lChild = this->rChild = nullptr;
    }
};

template <typename K, typename V>
class BinarySearchTree
{
private:
    TreeNode<K, V> *root;

public:
    BinarySearchTree()
    {
        this->root = nullptr;
    }

    // iterative insert
    void insert(K key, V value)
    {
        if (this->root == nullptr)
        {
            this->root = new TreeNode<K, V>(key, value);
        }
        else
        {
            TreeNode<K, V> *ptr = this->root;
            bool breakLoop = false;
            while (breakLoop == false)
            {
                if (key < ptr->key)
                {
                    if (ptr->lChild == nullptr)
                    {
                        ptr->lChild = new TreeNode<K, V>(key, value);
                        breakLoop = true;
                    }
                    else
                    {
                        ptr = ptr->lChild;
                    }
                }

                else if (key > ptr->key)
                {
                    if (ptr->rChild == nullptr)
                    {
                        ptr->rChild = new TreeNode<K, V>(key, value);
                        breakLoop = true;
                    }
                    else
                    {
                        ptr = ptr->rChild;
                    }
                }
                else // ptr->key==key
                {
                    breakLoop = true;
                }
            } // end of while loop
        }
    } // end of insert function
};