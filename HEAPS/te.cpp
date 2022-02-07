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
};

struct comp
{
    bool operator()(HuffNode *l, HuffNode *r)
    {
        // highest priority item has lowest frequency
        return l->freq > r->freq;
    }
};

class HTree
{
    HuffNode * root; //

    HuffNode *arr;
    int index;
    int capacity;

public:
    
    HTree() 
    {
        root = nullptr;
        capacity = 150;
        arr = new HuffNode[capacity];
        index = 1;
    }

    HuffNode *newHuffNode(char ch, int freq, HuffNode *left, HuffNode *right)
    {
        HuffNode *node = new HuffNode();

        node->ch = ch;
        node->freq = freq;
        node->left = left;
        node->right = right;

        return node;
    }


    void encode(HuffNode *root, string str,unordered_map<char, string> &hcode)
    {
        if (root == nullptr)
            return;

        // found a leaf node
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

        // found a leaf node
        if (!root->left && !root->right)
        {
            cout << root->ch;
            return;
        }

        index++;

        if (str[index] == '0'){
            decode(root->left, index, str);}
        else{
            decode(root->right, index, str);}
    }
    
    void buildHuffmanTree(string text)
    {

        unordered_map<char, int> freq;
        for (char ch : text)
        {
            freq[ch]++;
        }

        priority_queue<HuffNode *, vector<HuffNode *>, comp> pq;

        // Creating a leaf node for each character and add it
        // to the priority queue.
        for (auto pair : freq)
        {
            pq.push(newHuffNode(pair.first, pair.second, nullptr, nullptr));
        }

        // do till there is more than one node in the queue
        while (pq.size() != 1)
        {

            HuffNode *min1 = pq.top();
            pq.pop();
            HuffNode *min2 = pq.top();
            pq.pop();

            int sum = min1->freq + min2->freq;
            pq.push(newHuffNode('*', sum, min1, min2));
        }


        root = pq.top();

       
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
            << ref << '\n';


    }


};


int main()
{
    HTree h;

    std::ifstream inFile;
    inFile.open("file.txt"); // open the input file

    std::stringstream strStream;
    strStream << inFile.rdbuf();       // read the file
    std::string str = strStream.str(); // str holds the content of the txt file

    
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


    ///decoding....


    int index = -1;
    cout << "\nDecoded string is: \n";
    while (index < (int)ref.size() - 2)
    {
        h.decode(index, ref);
    }

    return 0;
}