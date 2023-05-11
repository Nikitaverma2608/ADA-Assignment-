// Implement the Huffman coding algorithm to compress a given string

/*
Huffman coding is a lossless data compression algorithm that works by assigning variable-length codes to the characters in a message. The more frequently a character appears, the shorter its corresponding code will be. This results in a more efficient encoding of the message, as the most frequently occurring characters can be represented using fewer bits. The algorithm was developed by David A. Huffman in 1952 while he was a graduate student at MIT.

Here is an example of how Huffman coding works:

Suppose we have a message consisting of the following characters and their frequencies:

Character	Frequency
A           	5
B	            9
C	            12
D	            13
E	            16
F	            45
To encode this message using Huffman coding, we follow these steps:

We create a binary tree with the characters as the leaves, and the frequencies as the weights of the nodes. The two nodes with the lowest frequencies are combined into a single node, and this process is repeated until all the nodes are combined into a single root node.

               100
              /   \
             /     \
            /       \
           /         \
         45           55
        /  \         /  \
       /    \       /    \
      F     16     39     |
           / \    /  \    |
          /   \  17  22   |
         E     |      |   |
              5     9    13
              A     B    C
We assign a 0 to each left branch and a 1 to each right branch in the tree, creating a unique binary code for each character:

        A:  0
        B:  101
        C:  100
        D:  111
        E:  1101
        F:  1100
We use these binary codes to encode the message:

    Original message: AAAAA BBBBBBBBB CCC DDDDDDDDDDDD EEEEEEEEEEEEEEEE FFFFFFFFFFFFFFFFFFFFFFFF
    Encoded message:  00000 101101010101010101010100 100100100100 1111111111111 1101110111011101110110101101011010101010101010101010101010101010101010101

The resulting encoded message is shorter than the original message, making it more efficient to store and transmit. The efficiency of Huffman coding depends on the frequencies of the characters in the message - the more skewed the distribution, the greater the potential for compression.
*/

#include <iostream>
#include <string>
#include <queue>
#include <unordered_map>
using namespace std;

// A Tree node
struct Node
{
	char ch;
	int freq;
	Node *left, *right;
};

// Function to allocate a new tree node
Node* getNode(char ch, int freq, Node* left, Node* right)
{
	Node* node = new Node();

	node->ch = ch;
	node->freq = freq;
	node->left = left;
	node->right = right;

	return node;
}

// Comparison object to be used to order the heap
struct comp
{
	bool operator()(Node* l, Node* r)
	{
		// highest priority item has lowest frequency
		return l->freq > r->freq;
	}
};

// traverse the Huffman Tree and store Huffman Codes
// in a map.
void encode(Node* root, string str,
			unordered_map<char, string> &huffmanCode)
{
	if (root == nullptr)
		return;

	// found a leaf node
	if (!root->left && !root->right) {
		huffmanCode[root->ch] = str;
	}

	encode(root->left, str + "0", huffmanCode);
	encode(root->right, str + "1", huffmanCode);
}

// traverse the Huffman Tree and decode the encoded string
void decode(Node* root, int &index, string str)
{
	if (root == nullptr) {
		return;
	}

	// found a leaf node
	if (!root->left && !root->right)
	{
		cout << root->ch;
		return;
	}

	index++;

	if (str[index] =='0')
		decode(root->left, index, str);
	else
		decode(root->right, index, str);
}

// Builds Huffman Tree and decode given input text
void buildHuffmanTree(string text)
{
	// count frequency of appearance of each character
	// and store it in a map
	unordered_map<char, int> freq;
	for (char ch: text) {
		freq[ch]++;
	}

	// Create a priority queue to store live nodes of
	// Huffman tree;
	priority_queue<Node*, vector<Node*>, comp> pq;

	// Create a leaf node for each character and add it
	// to the priority queue.
	for (auto pair: freq) {
		pq.push(getNode(pair.first, pair.second, nullptr, nullptr));
	}

	// do till there is more than one node in the queue
	while (pq.size() != 1)
	{
		// Remove the two nodes of highest priority
		// (lowest frequency) from the queue
		Node *left = pq.top(); pq.pop();
		Node *right = pq.top();	pq.pop();

		// Create a new internal node with these two nodes
		// as children and with frequency equal to the sum
		// of the two nodes' frequencies. Add the new node
		// to the priority queue.
		int sum = left->freq + right->freq;
		pq.push(getNode('\0', sum, left, right));
	}

	// root stores pointer to root of Huffman Tree
	Node* root = pq.top();

	// traverse the Huffman Tree and store Huffman Codes
	// in a map. Also prints them
	unordered_map<char, string> huffmanCode;
	encode(root, "", huffmanCode);

	cout << "Huffman Codes are :\n" << '\n';
	for (auto pair: huffmanCode) {
		cout << pair.first << " " << pair.second << '\n';
	}

	cout << "\nOriginal string was :\n" << text << '\n';

	// print encoded string
	string str = "";
	for (char ch: text) {
		str += huffmanCode[ch];
	}

	cout << "\nEncoded string is :\n" << str << '\n';

	// traverse the Huffman Tree again and this time
	// decode the encoded string
	int index = -1;
	cout << "\nDecoded string is: \n";
	while (index < (int)str.size() - 2) {
		decode(root, index, str);
	}
}

// Huffman coding algorithm
int main()
{
	string text = "Huffman coding algorithm";

	buildHuffmanTree(text);

	return 0;
}
