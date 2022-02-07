#include <iostream>
#include <string>
#include <queue>
#include <unordered_map>
#include <fstream>
#include <sstream>
using namespace std;

struct HuffNode
{
    char ch;
    int freq;
    HuffNode *left, *right;

    HuffNode() {
        left = nullptr;
        right = nullptr;
    }

};

class heap
{
private:
    HuffNode *arr;
    int  index;
    int capacity;

    friend class HTree;

public:
    heap()
    {

        capacity = 1000;
        arr = new HuffNode[capacity];
        index = 1;
    }

    void doubleCapacity()
    {

        HuffNode *oldArr = arr;

        int double_ = capacity * 2;

        arr = new HuffNode[double_];

        for (int i = 0; i < double_; i++)
        {
            arr[i] = oldArr[i];
        }

        delete[] oldArr;
    }

    void insert(HuffNode  a)
    {
        arr[index] = a;

        index++;
        heapify(arr, index - 1);
    }

    void insert(char _ch, int _freq, HuffNode *_left, HuffNode *_right)
    {
        if (index != capacity)
        {
            HuffNode _new;
            _new.ch = _ch;
            _new.freq = _freq;
            _new.left = _left;
            _new.right = _right;

            arr[index] = _new;


            index++;
            heapify(arr, index - 1);
        }
        else
        {
            doubleCapacity();
            insert(_ch, _freq,nullptr,nullptr);
        }
    }

    void heapify(HuffNode *arr, int i)
    {
        int parent = i / 2;

        if (i == 1)
        {
            return;
        }

        if (arr[parent].freq > arr[i].freq)
        {
            HuffNode temp;

            temp = arr[parent];
            arr[parent] = arr[i];
            arr[i] = temp;

            heapify(arr, i / 2);
        }
    }

    void heapify_down(HuffNode *arr, int i)
    {
        int parent = i;
        int l = 2 * i;     // left = 2*i
        int r = 2 * i + 1; // right = 2*i + 1

        if (l < index && arr[i].freq > arr[l].freq)
        {
            parent = l;
        }
        if (r < index && arr[i].freq > arr[r].freq)
        {
            parent = r;
        }

        if (parent != i)
        {
            HuffNode temp;

            temp = arr[i];
            arr[i] = arr[parent];
            arr[parent] = temp;

            heapify_down(arr, parent);
        }
    }

    void delete_()
    {
        delete_(arr, index);
    }

    void delete_(HuffNode *arr, int i)
    {

        if (index == 0)
        {
            return;
        }

        HuffNode temp;
        temp = arr[1];
        arr[1] = arr[index - 1];
        arr[index - 1] = temp;

        index--;

        heapify_down(arr, 1);

        return;
    }

    void print()
    {
        print(arr);
    }

    void print(HuffNode *arr)
    {
        for (int i = 1; i < index; i++)
        {
            cout << arr[i].ch << ":"<<arr[i].freq<<"   " ;
        }
        cout <<endl;
    }

    HuffNode top()
    {
        return arr[1];
    }

    int size()
    {
        return index-1;
    }

    ~heap()
    {
        delete[] arr;
        capacity = 0;
        index = 0;
    }
};

/////////////////////////////////////////////////////////////////////////////////////////////////
// A Tree HuffNode
class HTree
{
    HuffNode *root; //

public:
    HTree()
    {
        root = nullptr;
        
    }

    //Function to allocate a new tree HuffNode

    HuffNode newHuffNode(char ch, int freq, HuffNode *left, HuffNode *right)
    {
        HuffNode HuffNode; //= new HuffNode();

        HuffNode.ch = ch;
        HuffNode.freq = freq;
        HuffNode.left = left;
        HuffNode.right = right;

        //cout << HuffNode.right->ch<<":"<<HuffNode.right->freq<<endl;

        return HuffNode;
    }

    void inorderPrintKeys(HuffNode *ptr)
    {
        if (ptr)
        {
            inorderPrintKeys(ptr->left);
            cout << ptr->ch << endl;
            inorderPrintKeys(ptr->right);
        }
    }

    // traverse the Huffman Tree and store Huffman Codes
    // in a map.
    void encode(HuffNode *root, string str, unordered_map<char, string> &hcode)
    {
           
        if (root == nullptr)
            return;

        // found a leaf HuffNode
        if (!root->left && !root->right)
        {
            hcode[root->ch] = str;
        }

        encode(root->left, str + "0", hcode);
        encode(root->right, str + "1", hcode);
    }

    // traverse the Huffman Tree and decode the encoded string

    void decode(int &index, string str)
    {
        decode(root, index, str);
    }

    void decode(HuffNode *root, int &index, string str)
    {
        if (root == nullptr)
        {
            return;
        }

        // found a leaf HuffNode
        if (!root->left && !root->right)
        {
            cout << root->ch;
            return;
        }

        index++;

        if (str[index] == '0')
        {
            decode(root->left, index, str);
        }
        else
        {
            decode(root->right, index, str);
        }
    }

    // Builds Huffman Tree and decode given input text
    void buildHuffmanTree(string text)
    {
        // count frequency of appearance of each character
        // and store it in a map
        unordered_map<char, int> freq;
        for (char ch : text)
        {
            freq[ch]++;
        }

        // Create a priority queue to store live HuffNodes of
        // Huffman tree;
        // priority_queue<HuffNode *, vector<HuffNode *>, comp> pq;

        heap pq;
        int count=0, index=1;
        // Create a leaf HuffNode for each character and add it
        // to the priority queue.
        for (auto pair : freq)
        {
            pq.insert(newHuffNode(pair.first, pair.second, nullptr, nullptr));
            count++;
            //cout << pair.first << ":" << pair.second<<endl;
        }
        cout <<  endl;
        pq.print();
        // do till there is more than one HuffNode in the queue
        while (index != count)
        {
            // Remove the two HuffNodes of highest prioritya
            // (lowest frequency) from the queue
            HuffNode left = pq.top();
            pq.delete_();
            HuffNode right = pq.top();
            pq.delete_();

            cout << endl
                 << "deled are: "<<left.ch<<":"<<left.freq<<"  "<<right.ch<<":"<<right.freq;

            cout << endl<<"after del: ";
            pq.print();
            cout << endl;
                // Create a new internal HuffNode with these two HuffNodes
                // as children and with frequency equal to the sum
                // of the two HuffNodes' frequencies. Add the new HuffNode
                // to the priority queue.
                int sum = left.freq + right.freq;
            pq.insert(newHuffNode('*', sum, &left, &right));
            cout << "after insert: "<<endl;
            pq.print();
            cout << index;
            index++;

        }

        // root stores pointer to root of Huffman Tree
        
        HuffNode r = pq.top();
        root = &r;//pq.top();

        //inorderPrintKeys(root);

        // traverse the Huffman Tree and store Huffman Codes
        // in a map. Also prints them

        unordered_map<char, string> hcode;

        encode(root, "", hcode);

        cout << "Huffman Codes are :\n"
             << '\n';
        for (auto pair : hcode)
        {
            cout << pair.first << " " << pair.second << '\n';
        }

        cout << "\nOriginal string was :\n"
             << text << '\n';

        // print encoded string
        string str = "";
        for (char ch : text)
        {
            str += hcode[ch];
        }

        ///////////////////////////// Compressing the encoded string in binary file ///////////////////////////

        std::string ref = str;
        unsigned int size = 124;

        std::ofstream supp_info_output("binary_file", std::ios::out | std::ios::binary); // saving file
        unsigned int stringLength = ref.length();
        supp_info_output.write((char *)(&stringLength), sizeof(stringLength));
        supp_info_output.write(ref.c_str(), ref.length());
        supp_info_output.write((char *)(&size), sizeof(size));
        supp_info_output.close();

        ////////////////////////////////////////////////////////////////////////////////////////////////////////

        cout << "\nEncoded string is :\n"
             << str << '\n';
    }
};

int main()
{
    HTree h;

    std::ifstream inFile;
    inFile.open("file.txt"); // open the input file

    std::stringstream strStream;
    strStream << inFile.rdbuf();       // read the file
    std::string str = strStream.str(); // str holds the content of the file

    h.buildHuffmanTree(str);

    /////////////Decompression reading encoded data from binary file and decoding it////////

    std::string ref;
    unsigned int size;

    std::ifstream supp_info_input("binary_file", std::ios::in | std::ios::binary); // loading file
    unsigned int stringLength;
    supp_info_input.read((char *)(&stringLength), sizeof(stringLength));
    ref.resize(stringLength);
    supp_info_input.read((char *)ref.c_str(), stringLength);
    supp_info_input.read((char *)(&size), sizeof(size));
    supp_info_input.close();

    /// decoding....

    int index = -1;
    cout << "\nDecoded string is: \n";
    while (index < (int)ref.size() - 2)
    {
        h.decode(index, ref);
    }

    return 0;
}