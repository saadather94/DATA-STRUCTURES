#include <iostream>
#include <stack>
#include <queue>
#include <vector>

using namespace std;

template <typename V>
struct TreeNode
{

    V value;
    TreeNode<V>  *lChild;
    TreeNode<V>  *rChild;

    TreeNode()
    {
        this->lChild = this->rChild = nullptr;
    }

    TreeNode(V value)
    {
        this->value = value;
        this->lChild = this->rChild = nullptr;
    }

    bool isLeaf()
    {
        return !this->lChild && !this->rChild;
    }
};

template <typename V>
class BinarySearchTree
{
private:
    void inorderPrintvalues(TreeNode<V> *ptr)
    {
        if (ptr)
        {
            inorderPrintvalues(ptr->lChild);
            cout << ptr->value << " ";
            inorderPrintvalues(ptr->rChild);
        }
    }

    void preOrderPrintvalues(TreeNode<V> *ptr)
    {
        if (ptr)
        {
            cout << ptr->value << " ";
            preOrderPrintvalues(ptr->lChild);
            preOrderPrintvalues(ptr->rChild);
        }
    }

    void postOrderPrintvalues(TreeNode<V> *ptr)
    {
        if (ptr)
        {
            postOrderPrintvalues(ptr->lChild);
            postOrderPrintvalues(ptr->rChild);
            cout << ptr->value << " ";
        }
    }
    void traverseSkewed(TreeNode<V> *root)
    {
        if (!root)
            return;

        cout << root->value << " ";
        traverseSkewed(root->rChild);
    }

    void delete_(V value, TreeNode<V> *&ptr)
    {
        if (ptr == nullptr)
            return;
        else if (value < ptr->value)
        {
            delete_(value, ptr->lChild);
        }
        else if (value > ptr->value)
        {
            delete_(value, ptr->rChild);
        }
        else
        {
            // case 0: leaf TreeNode<V> *
            if (ptr->isLeaf())
            {
                delete ptr;
                ptr = nullptr;
            }
            // case 1.1: only lChild child exists
            else if (ptr->lChild && !ptr->rChild)
            {
                TreeNode<V> *delTreeNode  = ptr;
                ptr = ptr->lChild;
                delete delTreeNode;
            }
            // case 1.2: only rChild child exists
            else if (!ptr->lChild && ptr->rChild)
            {
                TreeNode<V>  * delTreeNode = ptr;
                ptr = ptr->rChild;
                delete delTreeNode;
            }
            // case 2: both children exits
            else
            {
                TreeNode<V> *successor = ptr->rChild;
                while (successor->lChild)
                    successor = successor->lChild;

                ptr->value = successor->value;
                delete_(successor->value, ptr->rChild);
            }
        }
    } // end of delete

    void insert(V value, TreeNode<V> *&ptr)
    {
        if (ptr == nullptr)
        {
            ptr = new TreeNode<V>(value);
        }
        else if (value < ptr->value)
        {
            insert(value, ptr->lChild);
        }
        else if (value > ptr->value)
        {
            insert(value, ptr->rChild);
        }
    }

    V const *search(V value, TreeNode<V> *ptr)
    {
        if (ptr == nullptr)
            return nullptr;
        else if (value < ptr->value)
            return this->search(value, ptr->lChild);
        else if (value > ptr->value)
            return this->search(value, ptr->rChild);
        else
            return &ptr->value;
    }

    void deleteAll(TreeNode<V>  *ptr)
    {
        if (ptr)
        {
            deleteAll(ptr->lChild);
            deleteAll(ptr->rChild);
            delete ptr;
        }
    }

public:

    TreeNode<V>  *root;
    TreeNode<V> * headNode = NULL;
    TreeNode<V> * prevNode = NULL;

    BinarySearchTree()
    {
        this->root = nullptr;
    }

    BinarySearchTree(const BinarySearchTree & obj)
    {
        TreeNode<V> * newTreeNode= CopyTree(root, obj.root);
    }

    void operator=(const BinarySearchTree &originalTree)
    {
        if (&originalTree == this)
            return;

        CopyTree(root, originalTree.root);
    }

    void CopyTree(TreeNode<V> *&copy, const TreeNode<V> *originalTree)
    {
        if (originalTree == NULL)
            copy = NULL;
        else
        {
            copy = new TreeNode<V>;
            copy->value = originalTree->value;
            CopyTree(copy->lChild, originalTree->lChild);
            CopyTree(copy->rChild, originalTree->rChild);
        }
    }

        void traverseSkewed()
        {
            traverseSkewed(headNode);
        }

        void inorderPrintvalues()
        {
            inorderPrintvalues(this->root);
        }

        void preOrderPrintvalues()
        {
            this->preOrderPrintvalues(this->root);
        }

        void postOrderPrintvalues()
        {
            this->postOrderPrintvalues(this->root);
        }

        void levelOrderPrintvalues()
        {
            if (!this->root)
                return;

            queue<TreeNode<V> *> q;
            q.push(this->root);

            while (!q.empty())
            {
                TreeNode<V> *ptr = q.front();
                q.pop();
                cout << ptr->value << endl;

                if (ptr->lChild)
                    q.push(ptr->lChild);
                if (ptr->rChild)
                    q.push(ptr->rChild);
            }
        }
        ////////////////////////////////////////////////////////////////////////////////////////////////////////

        void updatevalue(V value1, V value2, TreeNode<V> * ptr)
        {

            delete_(value1,root);
            insert(value2,root);

        }

        //////////////////////////////////////////////////////////////////////////////////////////////////////

        void countnode()
        {
            if (!root)
                return;

            queue<TreeNode<V> *> q;
            q.push(root);
            int count = 0;

            while (!q.empty())
            {
                TreeNode<V> *ptr = q.front();
                q.pop();
                count++;

                if (ptr->lChild)
                    q.push(ptr->lChild);
                if (ptr->rChild)
                    q.push(ptr->rChild);
            }

            cout << count;
        }

        //////////////////////////////////////////////////////////////////////////////////////////////////////////////

        bool identicalTrees(TreeNode<V> * a, TreeNode<V> * b)
        {
            /*1. both empty */
            if (a == NULL && b == NULL)
            {
                return true;
            }

            /* 2. both non-empty -> compare them */
            if (a != NULL && b != NULL)
            {
                return (a->value == b->value && identicalTrees(a->lChild, b->lChild) && identicalTrees(a->rChild, b->rChild));
            }

            /* 3. one empty, one not -> false */
            return false;
        }

        //////////////////////////////////////////////////////////////////////////////////////////////////////////////////

        bool isBST(TreeNode<V>* node)
        {

            // traverse the tree in inorder fashion and
            // keep a track of previous node
            if (node != NULL)
            {
                if (!isBST(node->lChild))
                    return false;

                // allows only distinct values node
                if (prevNode != NULL &&
                    node->value <= prevNode->value)
                    return false;
                prevNode = node;
                return isBST(node->rChild);
            }
            return true;
        }

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    void mirror()
    {
        root = mirror(root);
    }

    TreeNode<V> * mirror(TreeNode<V> *& node)
    {
        if (node == NULL)
        {
            return node;
        }

        TreeNode<V> * lChild = mirror(node->lChild);
        TreeNode<V> * rChild = mirror(node->rChild);

        /* swap the lChild and rChild pointers */
        node->lChild = rChild;
        node->rChild = lChild;

        return node;
    }

    /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    static int getCAL(TreeNode<V> *node, int curr, int desired)
    {

        if (node == NULL)
            return 0;
        if (curr == desired)
            return 1;
        return getCAL(node->lChild, curr + 1, desired) +
               getCAL(node->rChild, curr + 1, desired);
    }

    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////



    void skewed(TreeNode<V> *&root)
    {
        if (root)
        {
            skewed(root->rChild);
            TreeNode<V> *Node = root;
            Node->value = root->value;
            cout<<Node->value<<" ";          
            skewed(root->lChild);
        }
    }

    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    bool commonpath(TreeNode<V> *root, vector<int> &path, int k)
    {
        // base case
        if (root == NULL)
            return false;

        // Store this node in path vector. The node will be removed if
        // not in path from root to k
        path.push_back(root->value);

        // See if the k is same as root's value
        if (root->value == k)
            return true;

        // Check if k is found in lChild or rChild sub-tree
        if ((root->lChild && commonpath(root->lChild, path, k)) ||
            (root->rChild && commonpath(root->rChild, path, k)))
            return true;

        // If not present in subtree rooted with root, remove root from
        // path[] and return false
        path.pop_back();
        return false;
    }

    // Returns LCA if node node1, node2 are present in the given binary tree,
    // otherwise return -1
    int common_ancestor(TreeNode<V> *root, int node1, int node2)
    {
        // to store paths to node1 and node2 from the root
        vector<int> node1path, node2path;

        // Find paths from root to node1 and root to node2. If either node1 or node2
        // is not present, return -1
        if (!commonpath(root, node1path, node1) || !commonpath(root, node2path, node2))
            return -1;

        /* Compare the paths to get the first different value */
        int i;
        for (i = 0; i < node1path.size() && i < node2path.size(); i++)
            if (node1path[i] != node2path[i])
                break;
        return node1path[i - 1];
    }

    void ancestor(TreeNode<V>*root, int k1, int k2)
    {
        while (root)
        {
            if (root->value> k1 && root->value> k2)
            {
                root = root->lChild;
            }
            else if (root->value<k1 && root->value<k2)
            {
                root = root->rChild;
            }
            else
            {
                break;
            }
        }
        //return root->value;

        stack<int> s;
        int c = s.push(root->value);

            
        if (root == s.top())
        {
            cout<<s.top();
        }
        else
        {

        }
        
        





    }

    //////////////////////////////////////////////////////////////////////////////////////////////////////////////

    void insert(V value)
    {
        insert(value, this->root);
    }

    void delete_(V value)
    {
        delete_(value, this->root);
    }

    V const *search(V value)
    {
        return this->search(value, this->root);
    }

    ~BinarySearchTree()
    {
        this->deleteAll(this->root);
    }
    };

int main()
{
    BinarySearchTree<int> b, b2 ,b3;

    int * array = new int[10];

    b.insert(8);
    b.insert(6);
    b.insert(15);
    b.insert(2);
    b.insert(7);
    b.insert(13);
    b.insert(20);
    //b.insert(100);


    cout <<endl<< "1ST TREE: ";
    b.preOrderPrintvalues();

    cout << endl;
    cout << endl<<"Total nodes: ";
    b.countnode();
    cout << endl;

    cout << endl
         << "IS BST: ";
    if( b.isBST(b.root)){cout<<"Yes! TREE IS BST ";}else{cout<<"Not a BST ";}

    cout << endl
         << endl;

    cout << "Common Ancestor of two nodes 2 & 7: "
         << b.ancestor(b.root, 2, 7)<< endl<<endl;

    b2=b;
    cout << "2nd TREE after deep copy: ";
    b.preOrderPrintvalues();

    cout << endl<<endl;
    cout<< "updating value 2 with 88 in tree 1: ";
    b.updatevalue(2, 88, b.root);
    b.preOrderPrintvalues();

    cout << endl
         << endl;
    for (int i = 0; i < 5; i++)
    {
        int count = b.getCAL(b.root, 0, i);
        printf("Level %d has %d node%s\n", i, count, (count == 1) ? "" : "s");
    }

    cout << endl
         << "CHECKING TREE 1 & TREE 2 IF IDENTICAL " << endl;

    if(b3.identicalTrees(b.root,b2.root)){cout<<">> IDENTICAL"<<endl;} 
    else {cout<<">> NOT IDENTICAL"<<endl;}

    cout<<endl << "Deleting 1 from tree 1: ";
    b.delete_(1);
    b.preOrderPrintvalues();

    cout << endl
         << endl;

    cout << "mirroring the tree: ";
    b.mirror();
    b.preOrderPrintvalues();

    cout << endl
         << endl;

    // cout << "Common Ancestor of two nodes 50 & 3 ";
    // cout << endl
    //      << b.ancestor(b.root, 2,7); 
         
         // b.common_ancestor(b.root, 50, 3);

    cout << endl
         << endl;

    cout << "SKEWED TREE ";
    b.skewed(b.root);

    cout << endl
         << endl;
}