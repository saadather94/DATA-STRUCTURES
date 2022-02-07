#include<iostream>
using namespace std;

template <class ItemType>
struct TreeNode
{
    ItemType info;
    TreeNode *left;
    TreeNode *right;
};

template <class ItemType>
class TreeType
{
public:
    TreeType();                                       // constructor
    ~TreeType();                                      // destructor
    TreeType(const TreeType &originalTree);           // copy constructor
    void operator=(const TreeType &originalTree);     // assignment operator
    void Clear();                                     // clear the tree
    bool IsEmpty() const;                             // test for empty tree
    bool IsFull() const;                              // test for full tree
    int LengthIs() const;                             // return number of items in tree
    void Find(ItemType &item, bool &found) const;     // retrieve an item
    void InsertItem(ItemType item);                   // insert an item
    void DeleteItem(ItemType item);                   // delete an item
    void PrintInOrder(std::ostream &outFile) const;   // print the tree in order
    void PrintPreOrder(std::ostream &outFile) const;  // print the tree in preorder
    void PrintPostOrder(std::ostream &outFile) const; // print the tree in post order

private:
    TreeNode *root;
    void Destroy(TreeNode *&tree);
    void CopyTree(TreeNode *&copy, const TreeNode *originalTree);
    void Insert(TreeNode *&tree, ItemType item);
    void DeleteNode(TreeNode *&tree);
    void Delete(TreeNode *&tree, ItemType item);
    int CountNodes(TreeNode *tree);
    void Retrieve(TreeNode *tree, ItemType &item, bool &found);
}

//-----------------------------------------------------------------------------
// CONSTRUCTOR
//-----------------------------------------------------------------------------
template <class ItemType>
TreeType<ItemType>::TreeType()
{
    root = NULL;
}

//-----------------------------------------------------------------------------
// DECONSTRUCTOR
//-----------------------------------------------------------------------------
void Destroy(TreeNode *&tree);

template <class ItemType>
TreeType<ItemType>::~TreeType()
{
    destroy(root);
}

void Destroy(TreeNode *&tree)
{
    if (tree != NULL)
    {
        Destroy(tree->left);
        Destroy(tree->right);
        delete tree;
    }
}

//------------------------------------------------------------------------------
// COPY CONSTRUCTOR
//-----------------------------------------------------------------------------

void CopyTree(TreeNode *&copy, const TreeNode *originalTree);

template <class ItemType>
TreeType<ItemType>::TreeType(const TreeType &originalTree)
{
    CopyTree(root, originalTree.root);
}

template <class ItemType>
void TreeType<ItemType>::operator=(const TreeType &originalTree)
{
    if (&originalTree == this)
        return;
    Destroy(root);
    CopyTree(root, originalTree.root);
}

void CopyTree(TreeNode *&copy, const TreeNode *originalTree)
{
    if (originalTree == NULL)
        copy = NULL;
    else
    {
        copy = new TreeNode;
        copy->info = originalTree->info;
        CopyTree(copy->left, originalTree->left);
        CopyTree(copy->right, originalTree->right);
    }
}

//-----------------------------------------------------------------------------
// INSERT ITEM
//-----------------------------------------------------------------------------
void Insert(TreeNode *&tree, ItemType item);

template <class ItemType>
void TreeType<ItemType>::InsertItem(ItemType item)
{
    Insert(root, item);
}

void Insert(TreeNode *&tree, ItemType item)
{
    if (tree == NULL)
    {
        tree = new TreeNode;
        tree->right = NULL;
        tree->left = NULL;
        tree->info = item;
    }
    else if (item < tree->info)
        Insert(tree->left, item);
    else
        Insert(tree->right, item);
}

//-----------------------------------------------------------------------------
// DELETE ITEM
//-----------------------------------------------------------------------------
void DeleteNode(TreeNode *&tree);

void Delete(TreeNode *&tree, ItemType item);

template <class ItemType>
void TreeType<ItemType>::DeleteItem(ItemType item)
{
    Delete(root, item);
}

void Delete(TreeNode *&tree, ItemType item)
{
    if (item < tree->info)
        Delete(tree->left, item);
    else if (item > tree->info)
        Delete(tree->right, item);
    else
        DeleteNode(tree);
}

//-----------------------------------------------------------------------------
// IS FULL
//-----------------------------------------------------------------------------
template <class ItemType>
bool TreeType<ItemType>::IsFull() const
{
    TreeNode *location;

    try
    {
        location = new TreeNode;
        delete location;
        return false;
    }
    catch (std::bad_alloc exception)
    {
        return true;
    }
}

//-----------------------------------------------------------------------------
// IS EMPTY
//-----------------------------------------------------------------------------
template <class ItemType>
bool TreeType<ItemType>::IsEmpty() const
{
    return root == NULL;
}

//-----------------------------------------------------------------------------
// LENGTH IS
//-----------------------------------------------------------------------------
int CountNodes(TreeNode *tree);

template <class ItemType>
int TreeType<ItemType>::LengthIs() const
{
    return CountNodes(root);
}

int CountNodes(TreeNode *tree)
{
    if (tree == NULL)
        return 0;
    else
        return CountNodes(tree->left) + CountNodes(tree->right) + 1;
}
//-----------------------------------------------------------------------------
// FIND
//-----------------------------------------------------------------------------
void Retrieve(TreeNode *tree, ItemType &item, bool &found);
template <class ItemType>
void TreeType<ItemType>::Find(ItemType &item, bool &found) const
{
    Retrieve(root, item, found)
}

void Retrieve(TreeNode *tree, ItemType &item, bool &found)
{
    if (tree == NULL)
        found = false;
    else if (item < tree->info)
        Retrieve(tree->left, item, found);
    else if (item > tree->info)
        Retrieve(tree->right, item, found);
    else
    {
        item = tree->info;
        found = true;
    }
}
//-----------------------------------------------------------------------------
// Clear
//-----------------------------------------------------------------------------
template <class ItemType>
void TreeType<ItemType>::Clear()
{
    ~TreeType() :
}
