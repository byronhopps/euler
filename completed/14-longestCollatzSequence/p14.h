
// Returns the next number in the collatz sequence
long int collatz(long int a);

struct nodeT {
    struct nodeT* nextNode;
    unsigned int number;
    unsigned long int length;
};

struct resultsT {
    int startNumber;
    int length;
};

// Returns the length of the longest collatz sequence
struct resultsT getLongestChain(int maxTestValue);

// Creates a new, empty node
struct nodeT* createNode();

// Returns the length of the collatz sequence from a start node
unsigned int getLength(struct nodeT* headNode, struct nodeT* startNode);

// Returns the node at the specified location
// Creates a new node if the requested node doesn't exist
struct nodeT* getNode(struct nodeT* hashTable, unsigned long int location);

void freeAllNodes(struct nodeT* headNode);

// Creates an empty list with one element
struct nodeT* initList();
