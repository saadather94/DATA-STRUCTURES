#include<iostream>
#include<stack>
#include<queue>
using namespace std;

struct node
{
    int key;
    node* next;
};

struct list
{
    node* head;
};

class graph
{
private:

    int vertexs;
    int *visited;
    list * grp;

public:
    graph(int v)
    {
        vertexs = v;
        grp = new list[vertexs];
        visited = new int[vertexs];

        for (int i = 0; i < vertexs; i++)
        {
            grp[i].head = NULL;
            visited[i] = 0;
        }
        
    }

    node * new_node(int x)
    {   
        node * newnode = new node;
        newnode->key = x;
        newnode->next = nullptr;
        return newnode;
    }

    void addedge(int src, int dest)
    {
        if(grp[src].head==nullptr) 
        {
            grp[src].head = new_node(dest);
        }
        else{
        
        node * newnode = new_node(dest);
        newnode->next = grp[src].head;
        grp[src].head = newnode;

        }
    }

    void print()
    {
        for (int i = 0; i < vertexs; i++)
        {

            node * ptr = grp[i].head;
            cout << "vertex "<< i << ":  ";

            while(ptr!=nullptr)
            {
                cout << ptr->key << " -> ";
                ptr=ptr->next;
            }
            cout<<endl;
        }
    }

    void DFS()
    {
        for (int i = 0; i < vertexs; i++)
        {
            if(visited[i]==0)
            {
                DFS_VIST(i);
            }
        }
    }
    void DFS_VIST(int src)
    {
        visited[src] = 1;
        cout << src << " -> ";

        node * ptr = grp[src].head;
        while (ptr!=nullptr)
        {
            if(visited[ptr->key]==0)
            {
                visited[ptr->key] = 1;
                DFS_VIST(ptr->key);
                
            }
            ptr=ptr->next;
        }

        //    OR DO THIS ////

        // for (node *vert = grp[src].head; vert != NULL; vert = vert->next)
        // {
        //     if (visited[vert->key] == 0)
        //     {
        //         DFS_VIST(vert->key);
        //     }
        // }

        visited[src] = 2;
    }

    void BFS()
    {
        for (int i = 0; i < vertexs; i++)
        {
            if (visited[i]==0)
            {
                BFS_VIST(i);
            }
            
        }
        
    }

    void BFS_VIST(int x)
    {
        queue<int> q;
        q.push(x);
        visited[x]=1;

        while (!q.empty())
        {
            int u = q.front();
            q.pop();

            cout << u << " ->";
            node * ptr = grp[u].head;

            while(ptr!=nullptr)
            {
                //cout << ptr->key << " ->";         //active upon if traveral is needed from given node
                if (visited[ptr->key]==0)
                {
                    q.push(ptr->key);
                    visited[ptr->key] = 1;
                }              
                ptr = ptr->next;
            }

            visited[u]=2;
               
        }
        
    }



    ~graph(){}
};






int main(){

    graph g(5);

    g.addedge(0,4);
    g.addedge(1,3);
    g.addedge(1, 2);
    g.addedge(2, 3);

    g.print();
    cout<<"DFS VIST : ";
    //g.DFS();
    cout << endl;   

    cout << "BFS VIST : ";
    g.BFS();
    cout<<endl;
    

    return 0;
}