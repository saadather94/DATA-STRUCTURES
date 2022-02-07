#include<iostream>
using namespace std;
#include <queue>

template <typename T>
class BST
{

public:
    
    class Tnode
    {

    public:
        T data;
        Tnode *lchild;
        Tnode *rchild;

        Tnode(){lchild=nullptr; rchild=nullptr;}
        Tnode(T value)
        {
            data = value;
            lchild = nullptr;
            rchild = nullptr;
        }
    };

    Tnode * root;

    BST()
    {
        root = nullptr;
    }
    BST(T value)
    {
        root->data = value;
    }

    bool isempty()
    {
        if(root==nullptr){return true;}else{return false;}
    }

    void skewinsertleft(T value)
    {
        if(isempty())
        {
            root = new Tnode(value);
        }
        else
        {   
            Tnode *ptr = root;
            while(ptr-> lchild!=NULL)
            {   
                ptr = ptr -> lchild;
                
            }

            ptr-> lchild= new Tnode(value);
        }

    }

    void skewinsertright(T value)
    {
        if(isempty())
        {
            root = new Tnode(value);
        }
        else
        {
            Tnode * ptr = root;
            while(ptr->rchild!=NULL)
            {
                ptr= ptr->rchild;

            }

            ptr->rchild = new Tnode(value);

        }

    }

    void insert(T value)
    {
        if (isempty())
        {
            root = new Tnode(value);

        }
        else
        {   
            Tnode * ptr = root;
            
            if(value > ptr->data)
            {

                Tnode *prev = root;
                while (ptr->rchild!=NULL)
                {

                    prev = ptr;
                    ptr = ptr->rchild;

                }
                
                if (value > prev->data)
                {
                    cout << "prev data " << prev->data << " ";
                    ptr->rchild = new Tnode(value);
                    cout << "right's right " << ptr->rchild->data << " ";
                }
                else
                {
                    cout << "prev data " << prev->data << " ";
                    ptr->lchild = new Tnode(value);
                    cout << "right's left " << ptr->lchild->data << " ";
                }

            }
            
            else if(value < ptr->data)
            {
                Tnode *prev = new Tnode;
                while (ptr->lchild!=NULL)
                {

                    prev = ptr;
                    ptr = ptr->lchild;
                    
                }

                if (value > prev->data)
                {
                    cout << "prev data " << prev->data << " ";

                    ptr->rchild = new Tnode(value);
                    cout << "left's right" << ptr->rchild->data << " ";
                }
                else
                {
                    cout << "prev data " << prev->data << " ";
                    ptr->lchild = new Tnode(value);
                    cout << "lefts left " << ptr->lchild->data << " ";
                }
            }
            else
            {
                return;
            }      

        }


    }

    bool isbalance(Tnode * root, int * height){

        if(root == NULL){
            return true;
        }
        int lh = 0, rh = 0;
        if(isbalance(root->lchild, &lh)== false){

            return false;
        }
        if (isbalance(root->rchild, &rh)== false)
        {
            return false;
        }
        
        *height = max(lh, rh)+1;
        if(abs(lh-rh)<=1){
            return true;
        }
        else {return false;}
        
    }

    void PrintKeys(Tnode *ptr)
    {
        if (ptr)
        {
            PrintKeys(ptr->lchild);
            cout << ptr->data << " ";
            PrintKeys(ptr->rchild);
 
        }
    }

    void PrintKeys()
    {
        PrintKeys(this->root);
    }
};

int main(){

    BST<int>b;
    // b.insert(5);
    // b.insert(7);
    // b.insert(1);
    // b.insert(8);
    // b.insert(9);
    // b.insert(2);
    // b.insert(3);
    // b.insert(6);
    // b.insert(6);
    // b.insert(11);

    BST<int> :: Tnode *root = new Tnode(1);
    BST<int>::Tnode *root->lchild = new Tnode(2);
    root->rchild = new Tnode(3);

    if(b.isbalance(root,0))
    {
        cout<<"balanced ";
    }
    else
    {
        cout<<"No balanced ";
    }
    

    cout << endl
         << endl;
    b.PrintKeys();

    return 0;
}