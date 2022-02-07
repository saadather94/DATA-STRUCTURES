#include <iostream>
#include <cstdlib>
#include <fstream>
using namespace std;
#define MAX_TREE_HEIGHT 1000

// A Huffman tree node
struct MinHeapNode
{
    char codeword; // I chose char because we are inputing alphabetic       letters

    // The why I chose unsigned data type is because an unsigned  integer can never be negative.
    // In this case the frequency and the capacity of a character cannot be negative.
    unsigned freq; // Frequency of the character - how many times does it occur

    struct MinHeapNode *left, *right; // Left and Right children
};

struct MinHeap // Collection of nodes
{
    unsigned size;              // Size of the heap
    unsigned capacity;          // Capacity of the heap
    struct MinHeapNode **array; // Heap node pointers array
};

class heap
{
    public:
        
    // Function to dynamically alocate a new heap node with provided character   (codeword) and its frequency
    struct MinHeapNode *newHeapNode(char codeword, unsigned freq)
    {
        struct MinHeapNode *temp = (struct MinHeapNode *)malloc(sizeof(struct MinHeapNode));

        temp->left = temp->right = NULL;
        temp->codeword = codeword;
        temp->freq = freq;

        return temp;
    }

    // Creating a new dynamically allocated min heap with given capacity
    struct MinHeap *createMinHeap(unsigned capacity)
    {
        struct MinHeap *minHeap = (struct MinHeap *)malloc(sizeof(struct MinHeap));
        minHeap->size = 0;            // Setting the size to 0
        minHeap->capacity = capacity; // Inserting the given capacity
        // Inserting into the heap node pointers array
        minHeap->array = (struct MinHeapNode **)malloc(minHeap->capacity * sizeof(struct MinHeapNode *));
        return minHeap;
    }

    // Swap function to swap two min heap nodes
    void swap(struct MinHeapNode **a, struct MinHeapNode **b)
    {
        struct MinHeapNode *temp2 = *a;
        *a = *b;
        *b = temp2;
    }
    // minHeapify function
    void minHeapify(struct MinHeap *minHeap, int index)
    {
        int smallest = index;
        int leftchild = 2 * index + 1;
        int rightchild = 2 * index + 2;

        if (leftchild < minHeap->size && minHeap->array[leftchild]->freq < minHeap->array[smallest]->freq)
            smallest = leftchild;

        if (rightchild < minHeap->size && minHeap->array[rightchild]->freq < minHeap->array[smallest]->freq)
            smallest = rightchild;

        if (smallest != index)
        {
            swap(&minHeap->array[smallest], &minHeap->array[index]);
            minHeapify(minHeap, smallest);
        }
    }

    // Checking if the size of the heap is 1
    int heapSizeOne(struct MinHeap *minHeap)
    {
        return (minHeap->size == 1);
    }

    // Extracting minimum value node from the heap
    struct MinHeapNode *extractMin(struct MinHeap *minHeap)
    {
        struct MinHeapNode *temp = minHeap->array[0];
        minHeap->array[0] = minHeap->array[minHeap->size - 1];
        --minHeap->size;
        minHeapify(minHeap, 0);
        return temp;
    }

    // Inserting a new node into min heap
    void insert(struct MinHeap *minHeap, struct MinHeapNode *minHeapNode)
    {
        ++minHeap->size;
        int i = minHeap->size - 1;
        while (i && minHeapNode->freq < minHeap->array[(i - 1) / 2]->freq)
        {
            minHeap->array[i] = minHeap->array[(i - 1) / 2];
            i = (i - 1) / 2;
        }
        minHeap->array[i] = minHeapNode;
    }

    // Build function to build min heap
    void build(struct MinHeap *minHeap)
    {
        int n = minHeap->size - 1;
        for (int i = (n - 1) / 2; i >= 0; --i)
            minHeapify(minHeap, i);
    }

    // Display function to print an array
    void display(int arr[], int n)
    {
        int i;
        for (i = 0; i < n; ++i)
            cout << arr[i];
        cout << "\n";
    }

    // Function to check if the node is a leaf
    int isLeaf(struct MinHeapNode *root)
    {
        return !(root->left) && !(root->right);
    }

    // Creating a min heap with given capacity equivalent to size and inserts all    the codewords and their frequency.
    struct MinHeap *create(char codeword[], int freq[], int size)
    {
        struct MinHeap *minHeap = createMinHeap(size);
        for (int i = 0; i < size; ++i)
            minHeap->array[i] = newHeapNode(codeword[i], freq[i]);
        minHeap->size = size;
        build(minHeap);
        return minHeap;
    }

    // Function that builds the Huffman tree
    struct MinHeapNode *buildHT(char codeword[], int freq[], int size)
    {
        struct MinHeapNode *left, *right, *top;

        // Creating a min heap with given capacity equivalent to size and inserts all the codewords and their frequency.
        struct MinHeap *minHeap = create(codeword, freq, size);

        // while loop runs as long as the size of heap doesn't reach 1
        while (!heapSizeOne(minHeap))
        {
            // Getting the two minimums from min heap
            left = extractMin(minHeap);
            right = extractMin(minHeap);

            // The frequency of top is computed as the sum of the frequencies of left and right nodes.
            top = newHeapNode('_', left->freq + right->freq);
            top->left = left;
            top->right = right;
            insert(minHeap, top);
        }
        // The remaining value is the root node which completes the tree
        return extractMin(minHeap);
    }

    // Prints huffman codes from the root of
    // Displaying Huffman codes
    void displayHC(struct MinHeapNode *root, int arr[], int top)
    {

        // Left side is given the value 0
        if (root->left)
        {
            arr[top] = 0;
            displayHC(root->left, arr, top + 1);
        }
        // Right side is given the value 1
        if (root->right)
        {
            arr[top] = 1;
            displayHC(root->right, arr, top + 1);
        }
        // If this is a leaf node, print the character and its code.
        if (isLeaf(root))
        {
            cout << root->codeword << ": ";
            display(arr, top);
        }
    }

    // Building a Huffman Tree and displaying the codes
    void HuffmanCodes(char codeword[], int freq[], int size)
    {


        // Building a HT
        struct MinHeapNode *root = buildHT(codeword, freq, size);

        // Displaying the HT we built
        int arr[MAX_TREE_HEIGHT], top = 0;

        displayHC(root, arr, top);
    }
};

// I used the example from the PP presentation in the Files section - The Hoffman Coding
int main()
{
    heap h;

    cout << "A|4\t B|0\t C|2\t D|1\t C|5\t E|1\t F|0\t G|1\t H|1\t I|0\t J|0\t K|3\t L|2\t M|0\t N|1\t\nO|2\t P|0\t Q|3\t R|5\t S|4\t T|2\t U|0\t V|0\t W|1\t X|0\t Y|0\t Z|0\t _|6\n"
         << endl;
    char arr[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z', '_'};
    int freq[] = {4, 0, 2, 1, 5, 1, 0, 1, 1, 0, 0, 3, 2, 0, 1, 2, 0, 3, 5, 4, 2, 0, 0, 1, 0, 0, 6};

    int size = sizeof(arr) / sizeof(arr[0]);
    
    
    h.HuffmanCodes(arr, freq, size);

   
    cout << "\n\n";
    system("pause");
    
    return 0;
}
