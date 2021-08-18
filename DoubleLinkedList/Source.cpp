//Doubly Linked List implementation by Matthew Wells
#include<iostream>

using std::cout;
using std::endl;

template <typename N> //N is a generic datatype- specify its type when declaring a node

class WellsLinkedList //A doubly linked list. To prevent memory leak or loss, call nodes in it on the heap rather than the stack.
{
public:
    WellsLinkedList* parent = nullptr; //Prior node in the list
    WellsLinkedList* child = nullptr; //Following node in the list
    N value; //Value of this node

    WellsLinkedList() {}; //A node can be initialized with no values- this results in a value of null and no parent or child

    WellsLinkedList(N data) //When initialized with one parameter, a node sets that parameter to its value
    {
        value = data;
    };

    WellsLinkedList(WellsLinkedList* parent, N data) //When initialized with two parameters, the first parameter is set to be the parent, and the second the value
    {
        parent = parent;
        value = data;
    };

    void Insert(N data) //Adds a new node to the heap and places it at the end of the list. Takes one paramater for the value of the new node.
    {
        if (child == nullptr)
        {
            child = new WellsLinkedList<N> (this, data);
            child->parent = this;
        }
        else
        {
            child->Insert(data);
        }
    };

    void InsertAfter(WellsLinkedList* node) //Inserts a node into the list immediately after the current node. Takes an already initialized node as a parameter.
    {
        if (child != nullptr)
        {
            WellsLinkedList* oldChild = child;
            child = node;
            child->parent = this;
            child->InsertAfter(oldChild);
        }
        else
        {
            child = node;
            child->parent = this;
        }
    };

    void InsertBefore(WellsLinkedList* node) //Inserts a node into the list immediately before the current node. Takes an already initialized node as a parameter.
    {
        if (parent != nullptr)
        {
            parent->InsertAfter(node);
        }
        else
        {
            parent = node;
            parent->child = this;
        }
    }

    WellsLinkedList* Find(N key, bool searchUp = true, bool iterating = false)
        //If key is in the linkedlist, returns a pointer a node containing it, otherwise returns a null pointer.
        //Favors nodes prior to this one, and favors proximity to this node.
    {
        WellsLinkedList* returnPointer = nullptr;
        if (key == value)
        {
            returnPointer = this;
            return returnPointer;
        }
        if (!iterating)
        {
            if (parent != nullptr)
            {
                returnPointer = parent->Find(key, true, true);
            }
            if (returnPointer != nullptr)
            {
                return returnPointer;
            }
            else if (child != nullptr)
            {
                returnPointer = child->Find(key, false, true);
            }
            return returnPointer;
        }
        else
        {
            if (searchUp)
            {
                if (parent != nullptr)
                {
                    returnPointer = parent->Find(key, true, true);
                }
                return returnPointer;
            }
            else
            {
                if (child != nullptr)
                {
                    returnPointer = child->Find(key, false, true);
                }
                return returnPointer;
            }
        }
    };

    void Delete(WellsLinkedList* delNode) //Removes a node from both the list and the heap.
    {
        if (delNode->child != nullptr)
        {
            delNode->child->parent = delNode->parent;
        }
        if (delNode->parent != nullptr)
        {
            delNode->parent->child = delNode->child;
        }
        delete delNode;
    };

    void Orphan() //Removes this node from the list but does not delete it. Do not call this without reparenting, or it will eat up memory.
    {
        if (child != nullptr)
        {
            child->parent = parent;
        }
        if (parent != nullptr)
        {
            parent->child = child;
        }
        child = nullptr;
        parent = nullptr;
    }

    N Maximum() //Returns the highest value key in the list. Called without a parameter, it recurses to the beginning of the list to begin searching
    {
        if (parent != nullptr)
        {
            return parent->Maximum();
        }
        else if (child != nullptr)
        {
            return child->Maximum(value);
        }
        else
        {
            return value;
        }
    };

    N Maximum(N curMax) //Recursively searches through the list for the highest value key and returns it.
    {
        if (curMax < value)
        {
            curMax = value;
        }
        if (child == nullptr)
        {
            return curMax;
        }
        else
        {
            return child->Maximum(curMax);
        }
    };

    N Minimum() //Returns the lowest value key in the list. Called without a parameter, it recurses to the beginning of the list to begin searching
    {
        if (parent != nullptr)
        {
            return parent->Minimum();
        }
        else if (child != nullptr)
        {
            return child->Minimum(value);
        }
        else 
        {
            return value;
        }
    };

    N Minimum(N curMin) //Recursively searches through the list for the lowest value key and returns it.
    {
        if (curMin > value)
        {
            curMin = value;
        }
        if (child == nullptr)
        {
            return curMin;
        }
        else
        {
            return child->Minimum(curMin);
        }
    };

    WellsLinkedList<N>* ListStart() //Moves up the list and fetches the top node
    {
        WellsLinkedList<N>* curNode = this;
        while (curNode->parent != nullptr) //If curNode is not at the start of the list
        {
            curNode = curNode->parent; //Move back through the list
        }
        return curNode;
    }

    void CleanUp() //Deletes the entire linked list from memory
    {
        while (parent != nullptr) //While this node has a parent, delete its parent
        {
            Delete(parent);
        }
        while (child != nullptr) //While this node has a child, delete its child
        {
            Delete(child);
        }
        Delete(this); //Delete this node
    }
};

template <typename N> //N is a generic datatype- for this algorithm to work, it must be compatible with the equals and comparison operators
void InsertionSort(WellsLinkedList<N>* toSort) //Implementation of the InsertionSort algorithm for a LinkedList. Runs in O(n^2) worst case, O(n) best case.
{
    WellsLinkedList<N>* beginning = toSort->ListStart(); //Get the beginning of the list toSort is in
    WellsLinkedList<N>* nodeToMove; //If the next node in the list is smaller than the currently selected node, we set it to this
    WellsLinkedList<N>* currentNode = beginning; //We use this to track what nodes have been searched
    WellsLinkedList<N>* searchNode; //We use this to track which nodes are smaller than the nodeToMove
    while (currentNode->child != nullptr) //Iterate through the linked list
    {
        if (currentNode->child->value >= currentNode->value) //If the next node is properly ordered with respect to the current node
        {
            currentNode = currentNode->child; //Move to the next node in the list
        }
        else //If the next node belongs earlier in the list
        {
            nodeToMove = currentNode->child; //Get the node that needs to be moved
            nodeToMove->Orphan(); //Remove the node that needs moving from its current place in the list
            searchNode = beginning; //Beginning searching for the node's correct location at the beginning of the list
            while (searchNode->value < nodeToMove->value) //Iterate through the list until we find the first node with a larger value than the note to be moved
            {
                searchNode = searchNode->child;
            }
            searchNode->InsertBefore(nodeToMove); //Insert the node back into the list
            if (searchNode == beginning) //If we didn't move through the list while searching
            {
                beginning = beginning->ListStart(); //Reset the starting point in our searching
            }
        }
    }
}

int InsertionTest(int testSize) //Tests the time to sort a linked list with an arbitrary number of nodes with InsertionSort
{
    WellsLinkedList<int>* testList = new WellsLinkedList<int>(rand() % 100000); //Start a list with a random number
    for (int i = 0;i < testSize-1;i++)
    {
        testList->Insert(rand() % 100000); //Add a random number between 0 and 99999 to the list
        testList = testList->child; //Move our pointer to the end of the list
    }
    int begin = clock();
    //cout << "Beginning sort at " << begin << endl;
    InsertionSort(testList);
    int end = clock();
    //cout << "Ending sort at " << end << endl;
    testList = testList->ListStart();
    cout << "List now consists of:" << endl;
    for (int i = 0;i < 100;i++)
    {
        if (testList != nullptr)
        {
            cout << testList->value << endl;
            testList = testList->child;
        }
    }
    if (testList != nullptr)
    {
        cout << "Further entries have been omitted for conciseness." << endl;
    }
    testList->CleanUp(); //Delete the list
    return end - begin;
}

int main() //Demonstration of functionality
{
    //WellsLinkedList<int>* integerList = new WellsLinkedList<int> (); //Generate a new list of integers
    //integerList->value = 11; //Set the only node in the list's value to 11
    //integerList->Insert(42); //Append a new node to the list with value 42
    //WellsLinkedList<int>* preList = new WellsLinkedList<int>(134); //Create a node with a value of 134
    //integerList->InsertBefore(preList); //Put the node with value 134 at the beginning of the list
    //WellsLinkedList<int>* midListNode = new WellsLinkedList<int> (22); //Create a node with value 22
    //integerList->InsertAfter(midListNode); //Insert the node with value 22 into the list after the original node
    //cout << integerList->Find(134) << endl; //Return the pointer to the node with value 134 in the list, if it exists
    //cout << integerList->Maximum() << endl; //Return the highest value key in the list
    //cout << integerList->Minimum() << endl; //Return the lowest value key in the list
    //integerList->Delete(integerList->Find(134)); //Delete the first node found with a value of 134 in the list
    //cout << integerList->Maximum() << endl;
    //WellsLinkedList<char>* characterList = new WellsLinkedList<char>();
    //characterList->value = 'e';
    //characterList->Insert('t');
    //WellsLinkedList<char>* preChar = new WellsLinkedList<char>('T');
    //characterList->InsertBefore(preChar);
    //WellsLinkedList<char>* midListChar = new WellsLinkedList<char>('s');
    //characterList->InsertAfter(midListChar);
    //cout << characterList->Find('e') << endl;
    //cout << characterList->Maximum() << endl;
    //cout << characterList->Minimum() << endl;
    //characterList->Delete(midListChar);
    //cout << characterList->Find('s');
    cout << InsertionTest(1000) << endl;
    cout << InsertionTest(5000) << endl;
    cout << InsertionTest(10000) << endl;
};