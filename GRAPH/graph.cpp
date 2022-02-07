#include<iostream>
using namespace std;

template <typename T>
struct node
{
    int vertex_id;
    struct node<T>* next;
};

template <typename T>
struct list
{
    struct node<T> *head;
};

template <typename T>
class graph_
{
private:

        list<int> * G;
        int Vertexs;
        bool * visited;
        int ** adjmatrix_G;


public:
    char *vertex_name;

    graph_(int V)
    {
        this->Vertexs = V;
        G = new list<int>[Vertexs];
        visited = new bool[Vertexs];
        vertex_name = new char [Vertexs];
        
        adjmatrix_G = new int *[Vertexs];
        for (int i = 0; i < Vertexs; i++)
        {
            G[i].head = NULL;
            visited[i]= false;
            adjmatrix_G[i] = new int[Vertexs];
        }
        
        ////////////// ADJECENT MATRIX ////////////////////////////////////////

        for (int i = 0; i < Vertexs; i++)
        {
            for (int j = 0; j < Vertexs; j++)
            {
                adjmatrix_G[i][j]=0;
            }
            
        }
        
    }

    node<T> * new_node(char vertex)
    {
        node<T>* newnode = new node<T>;
        newnode->next = NULL;
        newnode->vertex_id = vertex;
        return newnode;
    }

    void addedge_adjlist(int src, int dest)
    {
        node<T> * newnode = new_node(dest);
        newnode->next = G[src].head;
        G[src].head = newnode;

        adjmatrix_G[src][dest]=1;
        
        /*for undirected graph uncomment the following lines*/

        // node<T> *newnode = new_node(src);
        // newnode->next = G[dest].head;
        // G[dest].head = newnode;

        // adjmatrix_G[dest][src]=1;

        /**/
    }

    void addedge_adjmatrix(int src, int dest)
    {
        adjmatrix_G[src][dest]=1;
    }


    void print()
    {
        cout << endl;
        for (int i = 0; i < Vertexs; i++)
        {
            node<T>* ptr = G[i].head;

            cout<<"vertex "<<i<<": ";
            
            while(ptr)
            {
                 cout<<"->"<<ptr->vertex_id<<" ";
                ptr = ptr->next;
            }
            cout<<endl;
            
        }
    }

    void print_adjmatrix()
    {
        cout<<endl<<"///////////// adjmatrix //////////////"<<endl<<endl;
        cout<<"vertex:      ";
        for (int i = 0; i < Vertexs; i++)
        {

            cout << i << "   ";
        }cout<<endl<<"             ";
        for (int i = 0; i < Vertexs; i++)
        {

            cout << "__  ";
        }
        cout<<endl;
        for (int i = 0; i < Vertexs; i++)
        {
            cout<<"         "<<i<<" | ";
            for (int j = 0; j < Vertexs; j++)
            {
                cout<<adjmatrix_G[i][j]<<"   ";
            }
            cout<<endl;
        }
    }

    ~graph_(){}
};








int main(){

    graph_<int> g(4);

    // for (int i = 0; i < 4; i++)
    // {
    //     cout<<"ENTER VERTEX NAME ";
    //     cin >> g.vertex_name[i];
    //     cout<<endl;
    // }
    // char sin='N';
    // for (int i = 0; i < 4; i++)
    // {
    //     for (int j = 0; j < 4; j++)
    //     {
    //         cout << "IS EDGE BETWEEN VERTEX " << g.vertex_name[i] << " and " << g.vertex_name[j]<<"Y/N? ";
    //         cin>>sin;
    //         if(sin=='Y')
    //         {
    //             g.addedge_adjlist(i, j);
    //         }
    //         cout << endl;
    //     }
        

    // }

    g.addedge_adjlist(0, 1);
    g.addedge_adjlist(0, 2);
    g.addedge_adjlist(1, 2);
    g.addedge_adjlist(1, 3);
    g.addedge_adjlist(1, 0);
    g.addedge_adjlist(2, 3);
    g.addedge_adjlist(3, 0);

    g.print();

    // g.addedge_adjmatrix(1,2);
    // g.addedge_adjmatrix(1, 3);
    // g.addedge_adjmatrix(1, 0);
    // g.addedge_adjmatrix(2, 0);
    // g.addedge_adjmatrix(2, 1);
    // g.addedge_adjmatrix(2, 3);
    // g.addedge_adjmatrix(3, 2);
    // g.addedge_adjmatrix(3, 0);
    // g.addedge_adjmatrix(0, 2);

    g.print_adjmatrix();



    return 0;
}