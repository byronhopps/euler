// Returns the number of distinct exponents from two numbers
// between minBound and maxBound
int countDistinctPowers(int minBound, int maxBound);

// Returns an integer representing a^b
int power(int a, int b);

struct listItem {
    int value;
    struct listItem* next;
};

// Inserts a value into a linked list
void insertItem(struct listItem* head, int value);
