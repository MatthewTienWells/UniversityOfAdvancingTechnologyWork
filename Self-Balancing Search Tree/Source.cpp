//A self balancing binary search tree. Always sorted, and should automatically rotate to avoid long branches
#include<iostream>
#include<vector>

using std::cout;
using std::endl;
using std::max;
using std::vector;

template <typename N> //N is a generic datatype- specify its type when declaring a node
class WellsSearchLeaf
{
public:
	N value; //The value we want to store in this node
	int depth; //The total depth from the bottom of this node's lowest branch
	WellsSearchLeaf* left; //The child of this node on the left
	WellsSearchLeaf* right; //The child of this node on the right
	WellsSearchLeaf* prev; //The previous node in the branch
	
	WellsSearchLeaf(N initValue) //Initialize the leaf
	{
		value = initValue;
		depth = 0;
	}

	void DepthCheck() //Set this leaf's distance from the bottom of the tree. It should be 1 more than the deepest of the two branches coming from it
	{
		if (left != nullptr) //If there is a left branch from this leaf
		{
			if (right != nullptr) //If there is a right branch from this leaf
			{
				depth = max(left->depth, right->depth) + 1; //Get both branches' depths, set depth to 1 more than the larger of the two
			}
			else //If there is only a left branch
			{
				depth = left->depth + 1; //Set the leaf depth to one more than the single branch's depth
			}
		}
		else if (right != nullptr) //If there is only a right branch
		{
			depth = right->depth + 1; //Set the leaf depth to one more than the single branch's depth
		}
		else //If this leaf has no branches
		{
			depth = 0; //Its depth is 0
		}
	};

	WellsSearchLeaf<N>* Add(N newValue) //Recurse through this leaf and its branches until we find the place where newValue belongs, then add a new leaf there
	{
		WellsSearchLeaf<N>* newNode; //Create an empty pointer to a leaf
		if (newValue > value) //If the new value should be to the right of this leaf
		{
			if (right == nullptr) //If this leaf has an open right branch
			{
				right = new WellsSearchLeaf<N>(newValue); //Create a new leaf to the right of this leaf with value newValue
				right->prev = this; //Make this leaf the parent of the new leaf
				newNode = right; //Set newNode to point to the new leaf
			}
			else //If this leaf already has a leaf to the right
			{
				newNode = right->Add(newValue); //Move right and attempt to add again
			}
		}
		else //If the new value should be to the left of this leaf
		{
			if (left == nullptr) //If this leaf has an open left branch
			{
				left = new WellsSearchLeaf<N>(newValue); //Create a new leaf to the left of this leaf with value newValue
				left->prev = this; //Make this leaf the parent of the new leaf
				newNode = left; //Set newNode to point to the new leaf
			}
			else //If this leaf already has a leaf to the left
			{
				newNode = left->Add(newValue); //Move left and attempt to add again
			}
		}
		DepthCheck(); //Recalculate this leaf's depth
		return newNode; //Return a pointer to the newNode
	}


};

template <typename N> //N is a generic datatype- specify its type when declaring a node
class WellsSearchTree
{
public:
	WellsSearchLeaf<N>* root; //The base of the binary search tree
	WellsSearchLeaf<N>* traverseNode; //The last node traversed

	WellsSearchTree() {};

	void rotate(WellsSearchLeaf<N>* node, bool turnRight) //Rotate the tree using node as a pivot. Moves the right node up if turnRight is true, moves the left node otherwise.
	{
		WellsSearchLeaf<N>* curNode;
		if (turnRight)
		{
			if (node->right == nullptr) //If there is no node to the right
			{
				return; //Do nothing
			}
			curNode = node->right; //Select the node to the right
			node->right = curNode->left; //Move the left of the selected node to the right of the main node
			curNode->left = node; //Move the left of the selected node to point to the main node
			curNode->prev = node->prev; //Swap the prev parameters of the main and selected nodes
			node->prev = curNode;
			if (node->right != nullptr) //If the new right of the main node is not an empty branch
			{
				node->right->prev = node; //Set the prev node of the new right branch
			}
		}
		else
		{
			if (node->left == nullptr) //If there is no node to the left
			{
				return; //Do nothing
			}
			curNode = node->left; //Select the node to the left
			node->left = curNode->right; //Move the right of the selected node to the left of the main node
			curNode->right = node; //Move the right of the selected node to point to the main node
			curNode->prev = node->prev; //Swap the prev parameters of the main and selected nodes
			node->prev = curNode;
			if (node->left != nullptr) //If the new left of the main node is not an empty branch
			{
				node->left->prev = node; //Set the prev node of the new left branch
			}
		}
		if (curNode->prev != nullptr) //If the selected node is not the new root
		{
			if (curNode->prev->right == node) //If the main node was to the right of its prev node
			{
				curNode->prev->right = curNode; //Reset the right branch of the prev node
			}
			if (curNode->prev->left == node) //If the main node was to the left of its prev node
			{
				curNode->prev->left = curNode; //Reset the left branch of the prev node
			}
		}
	}

	virtual bool pivot(WellsSearchLeaf<N>* base) //Returns true if the tree was unbalanced
	{
		WellsSearchLeaf<N>* oldbase = base;
		WellsSearchLeaf<N>* curNode; //Node that we are currently at
		if (base != nullptr)
		{
			if (base->left != nullptr)
			{
				if (base->right != nullptr)
				{
					if (base->left->depth > base->right->depth + 1) //If the tree is weighted towards the left by more than 1 depth
					{
						if (base->prev == nullptr) //If the base is the root
						{
							root = base->left; //Move the root left
						}
						curNode = base->left; //Select the new root
						if (curNode->right != nullptr) //If the new node has a right branch
						{
							if (curNode->left != nullptr) //If the new node has a left branch
							{
								if (curNode->right->depth > curNode->left->depth) //If the inner branch is longer than the outer
								{
									rotate(curNode, true); //Rotate the curNode outwards
								}
								ResetDepth(curNode); //Reset the depth
							}
							else //If the node has only an inner branch
							{
								rotate(curNode, true); //Rotate the curNode outwards
								ResetDepth(curNode); //Reset the depth
							}
						}
						rotate(base, false); //Rotate the given base left
						ResetDepth(base); //Reset the depth with the new tree shape
						return true;
					}
					if (base->right->depth > base->left->depth + 1) //If the tree is weighted towards the right by more than 1 depth
					{
						if (base->prev == nullptr)
						{
							root = base->right; //Move the root right
						}
						curNode = base->right; //Select the new root
						if (curNode->left != nullptr) //If the new node has a left branch
						{
							if (curNode->right != nullptr) //If the new node has a right branch
							{
								if (curNode->right->depth < curNode->left->depth) //If the inner branch is longer than the outer
								{
									rotate(curNode, true); //Rotate the curNode outwards
								}
								ResetDepth(curNode); //Reset the depth
							}
							else //If the node has only an inner branch
							{
								rotate(curNode, true); //Rotate the curNode outwards
								ResetDepth(curNode); //Reset the depth
							}
						}
						rotate(base, true); //Rotate the given base left
						ResetDepth(base); //Reset the depth with the new tree shape
						return true;
					}
				}
				else if (base->left->depth > 0) //If the base has no right leaf and its left leaf has children
				{
					if (base->prev == nullptr) //If the base is the root
					{
						root = base->left; //Move the root left
					}
					curNode = base->left; //Select the new root
					if (curNode->right != nullptr) //If the new node has a right branch
					{
						if (curNode->left != nullptr) //If the new node has a left branch
						{
							if (curNode->right->depth > curNode->left->depth) //If the inner branch is longer than the outer
							{
								rotate(curNode, true); //Rotate the curNode outwards
							}
							ResetDepth(curNode); //Reset the depth
						}
						else //If the node has only an inner branch
						{
							rotate(curNode, true); //Rotate the curNode outwards
							ResetDepth(curNode); //Reset the depth
						}
					}
					rotate(base, false); //Rotate the given base left
					ResetDepth(base); //Reset the depth with the new tree shape
					return true;
				}
			}
			else if (base->right != nullptr && base->right->depth > 0)
			{
				if (base->prev == nullptr)
				{
					root = base->right; //Move the root right
				}
				curNode = base->right; //Select the new root
				if (curNode->right != nullptr && curNode->left != nullptr)
					if (curNode->left != nullptr) //If the new node has a left branch
					{
						if (curNode->right != nullptr) //If the new node has a right branch
						{
							if (curNode->right->depth < curNode->left->depth) //If the inner branch is longer than the outer
							{
								rotate(curNode, true); //Rotate the curNode outwards
							}
							ResetDepth(curNode); //Reset the depth
						}
						else //If the node has only an inner branch
						{
							rotate(curNode, true); //Rotate the curNode outwards
							ResetDepth(curNode); //Reset the depth
						}
					}
				rotate(base, true); //Rotate the given base left
				ResetDepth(base); //Reset the depth with the new tree shape
				return true;
			}
		}
		return false; //If no action was taken, exit with false
	}


	void ResetDepth(WellsSearchLeaf<N>* curNode) //Move upwards through the tree and rebalance it at each leaf directly above the provided leaf
	{
		while (curNode->prev != nullptr) //Loop until we reach the root
		{
			curNode->DepthCheck(); //Recalculate the depth of the leaf
			curNode = curNode->prev; //Move upwards one node
			//while (pivot(curNode)) {}; //Pivot until the tree is balanced below this point
		}
		curNode->DepthCheck(); //Recalculate the depth of the root node
		//while (pivot(curNode)) {}; //Pivot until the entire tree is balanced
	}

	void Reparent(WellsSearchLeaf<N>* leaf) //Moves the closest value leaf in the tree to the position of the current leaf then deletes its prior location.
		//This allows us to remove values without disturbing the tree structure.
	{
		WellsSearchLeaf<N>* curNode; //Node that we are currently at
		WellsSearchLeaf<N>* nodeToDelete; //Node that we intend to remove
		if (leaf->left->depth < leaf->right->depth) //We want to move a leaf up from whichever side is deeper to reduce the need for rebalancing
		{
			if (leaf->right->left == nullptr) //If the leaf on the immediate right is the closest larger value
			{
				curNode = leaf; //Select the given leaf
				nodeToDelete = leaf->right; //Select the leaf on the right to be deleted
				leaf->value = nodeToDelete->value; //Overwrite the current leaf's value with the value from the leaf to be deleted
				leaf->right = nodeToDelete->right; //Make the current leaf point to the same leaf as the leaf to be deleted was pointing at, if any
				if (leaf->right != nullptr) //If the leaf to be deleted was pointing at a leaf
				{
					leaf->right->prev = leaf; //Make the leaf to be deleted's child the current leaf's child.
				}
				RemoveNode(nodeToDelete); //Delete the node to delete.
			}
			else //If the leaf on the immediate right has children closer to the leaf we are overwriting
			{
				curNode = leaf->right; //Move right
				while (curNode->left->left != nullptr) //While the node to the left has a node on its left
				{
					curNode = curNode->left; //Move left
				}
				nodeToDelete = curNode->left; //Select the leftmost node to be deleted
				leaf->value = nodeToDelete->value; //Set the leaf that this function was called on to have the value of the leaf to be deleted
				curNode->left = nodeToDelete->right; //Set the current leaf to have the leaf, if any, to the right of the leaf to be deleted
				if (curNode->left != nullptr) //If the current leaf's new left is a leaf
				{
					curNode->left->prev = curNode; //Set the leaf to the left to have the current leaf as its parent
				}
				RemoveNode(nodeToDelete); //Delete the node to delete
			}
		}
		else //If the left branch is as deep as the right branch or deeper
		{
			if (leaf->left->right == nullptr) //If the leaf to the immediate left is the closest smaller leaf to the leaf we are overwriting in value
			{
				curNode = leaf; //Set the leaf to be overwritten as the current leaf
				nodeToDelete = leaf->left; //Set the leaf to be deleted as the leaf to the left
				leaf->value = nodeToDelete->value; //Set the main leaf's value to the value of the leaf to be deleted
				leaf->left = nodeToDelete->left; //Set the main leaf's left to point to the left branch, if any, of the node to be deleted
				if (leaf->left != nullptr) //If the leaf to the left had a branch
				{
					leaf->left->prev = leaf; //Set the new leaf on the left branch to have the main leaf as its parent
				}
				RemoveNode(nodeToDelete); //Delete the node to be deleted
			}
			else //If the leaf to the immediate left has a right branch
			{
				curNode = leaf->left; //Set the current leaf as the leaf to the left of the main leaf
				while (curNode->right->right != nullptr) //While the node to the right has a node on its right
				{
					curNode = curNode->right; //Move right
				}
				nodeToDelete = curNode->right; //Set the node to be deleted to be the closest leaf to the main leaf
				leaf->value = nodeToDelete->value; //Set the main leaf's value to the leaf to be deleted's value
				curNode->right = nodeToDelete->left; //Move the left branch, if any, of the node to be deleted to its current location
				if (curNode->right != nullptr) //If the current leaf still has a right branch
				{
					curNode->right->prev = curNode; //Set the right branch's parent to the current leaf
				}
				RemoveNode(nodeToDelete); //Delete the node to be deleted
			}
		}
		ResetDepth(curNode); //Rebalance the tree from the last node visited and every node directly above it
	}

	WellsSearchLeaf<N>* Find(N target)
	{
		WellsSearchLeaf<N>* curNode = root; //get a pointer to the root that we will use to hold find and hold the node with the given value
		while (curNode->value != target) //Iterate until we find the target
		{
			if (curNode->value > target) //If we are to the right of the target
			{
				if (curNode->left != nullptr) //If we can move left
				{
					curNode = curNode->left; //Move left
				}
				else //If we cannot move left
				{
					return nullptr; //The target does not exist, exit
				}
			}
			else //If we are to the left of the target
			{
				if (curNode->right != nullptr) //If we can move right
				{
					curNode = curNode->right; //Move right
				}
				else //If we cannot move right
				{
					return nullptr; //The target does not exist, exit
				}
			}
		}
		return curNode;
	}

	bool RemoveNode(WellsSearchLeaf<N>* curNode)
	{
		WellsSearchLeaf<N>* parentNode;
		if (curNode != root) //If the target is not the root
		{
			parentNode = curNode->prev; //Get the parent of the target
		}
		if (curNode->left == nullptr) //If the node has no left child
		{
			if (curNode->right == nullptr) //If the node has no right child
			{
				if (curNode != root) //If the target node is not the root
				{
					parentNode = curNode->prev; //Set the parent node
					if (parentNode->left == curNode) //If the node's parent is to the right
					{
						parentNode->left = nullptr; //Orphan this node
					}
					if (parentNode->right == curNode) //If the node's parent is to the left
					{
						parentNode->right = nullptr; //Orphan this node
					}
				}
				else //If the current node is the root and has no children
				{
					root = nullptr; //Set the root to null
					delete curNode; //Delete the former root
					return true;
				}
				delete curNode; //Delete this node
				ResetDepth(parentNode); //Rebalance the tree
				return true;
			}
			else //If the current node has a child on the right
			{
				if (curNode != root) //If the target node is not the root
				{
					parentNode = curNode->prev; //Set the parent node
					if (parentNode->left == curNode) //If the current node is to the left of it's parent
					{
						parentNode->left = curNode->right; //Reparent the child node to the target node's parent
					}
					if (parentNode->right == curNode) //If the current node is to the left of it's parent
					{
						parentNode->right = curNode->right; //Reparent the child node to the target node's parent
					}
					curNode->right->prev = parentNode; //Set the right node's new parent
				}
				else //If the current node is the root and has a child to the right
				{
					root = curNode->right; //Make the child the root node
					root->prev = nullptr; //Remove the prev parameter from the new root
					parentNode = root; //Set the root to the parent node before we rebalance
				}
				delete curNode; //Delete this node
				ResetDepth(parentNode); //Rebalance the tree
				return true;
			}
		}
		else //If the node has a left child
		{
			if (curNode->right == nullptr) //If the node has no right child
			{
				if (curNode != root) //If the target node is not the root
				{
					parentNode = curNode->prev;
					if (parentNode->left == curNode) //If the node's parent is to the right
					{
						parentNode->left = curNode->left; //Reparent this node's child
					}
					if (parentNode->right == curNode) //If the node's parent is to the left
					{
						parentNode->right = curNode->right; //Reparent this node's child
					}
					curNode->left->prev = parentNode; //Set the left node's new parent
				}
				else //If the current node is the root and has only one child
				{
					root = curNode->left; //Move the root to the child
					root->prev = nullptr; //Remove the prev parameter from the new root
					delete curNode; //Delete the old root
					return true;
				}
				delete curNode; //Delete this node
				ResetDepth(parentNode); //Rebalance the tree
				return true;
			}
			else //If the current node has a child on the right
			{
				Reparent(curNode); //Move a lower node up to this node to maintain tree structure
				return true;
			}
		}
	}

	bool Delete(N target) //Deletes a node with value target
	{
		if (root == nullptr) //If tree is not initialized
		{
			return false; //Return false
		}
		WellsSearchLeaf<N>* curNode = Find(target); //Get the node to be deleted
		if (curNode == nullptr) //If the node could not be found
		{
			return false; //Return false
		}
		RemoveNode(curNode); //Remove the node from the tree
	}

	void Insert(N newValue) //Add a new value to the tree
	{
		WellsSearchLeaf<N>* curNode;
		if (root == nullptr) //If the tree is empty
		{
			root = new WellsSearchLeaf<N>(newValue); //Create a new node and make it root
		}
		else
		{
			curNode = root->Add(newValue); //Pass the value to the root to find its place in the tree recursively
			while (curNode->prev != nullptr) //Move up the tree from the added node and rebalance each affected branch
			{
				while (pivot(curNode)) {} //Balance tree
				curNode = curNode->prev; //Move up one level
			}
			while (pivot(curNode)) {} //Balance the root of the tree
		}
	}

	WellsSearchLeaf<N>* Traverse() //Move through the tree and return a node. Uses preorder traversal.
	{
		if (traverseNode == nullptr) //If traversal has not been initialized
		{
			traverseNode = root; //Set the root to the currently traversed node
			return traverseNode; //Return the root
		}
		else if (traverseNode->left != nullptr) //If the current node has a left child
		{
			traverseNode = traverseNode->left; //Move left
			return traverseNode; //Return the new node
		}
		else if (traverseNode->right != nullptr) //If the current node only has a right child
		{
			traverseNode = traverseNode->right; //Move right
			return traverseNode; //Return the new node
		}
		else //If the current node has no children
		{
			WellsSearchLeaf<N>* lastNode = traverseNode; //Start tracking the previous node
			traverseNode = traverseNode->prev; //Move up one
			while ((traverseNode->right == lastNode) || (traverseNode->right == nullptr)) //While we cannot move right
			{
				if (traverseNode != root) //If we are not at the root
				{
					lastNode = traverseNode; //Set this node to previous
					traverseNode = traverseNode->prev; //Move up one
				}
				else //If we've returned to the root from the right
				{
					return traverseNode; //Return the root
				}
			}
			traverseNode = traverseNode->right; //Move right
			return traverseNode; //Return the current node
		}
	}

	N Maximum() //Returns the largest value in the tree.
	{
		WellsSearchLeaf<N>* curNode = root; //Set the current node to the root
		while (curNode->right != nullptr) //While we can move right
		{
			curNode = curNode->right; //Move right
		}
		return curNode->value; //Return the value of the rightmost node
	}
};

template <typename N>
class UnbalancedSearchTree: public WellsSearchTree<N> //Search tree without the pivoting algorithm, for testing purposes
{
public:
	bool pivot(WellsSearchLeaf<N>* base) //Override pivot so it always returns true immediately
	{
		return false;
	}
};

void UnitTestAdd(WellsSearchTree<int>* testTree, vector<int> randoms, int size) //Add some amount of random numbers to a tree to see how long it takes
{
	for (int i = 0; i < size; i++) //Iterate through the vector array
	{
		testTree->Insert(randoms[i]); //Add the integers to the tree
	}
};

void UnitTestDelete(WellsSearchTree<int>* testTree, vector<int> randoms, int size) //Remove some amount of random numbers from a tree to see how long it takes.
{
	for (int i = 0; i < size; i++) //Iterate through the vector array
	{
		testTree->Delete(randoms[i]); //Add the integers to the tree
	}
};

void UnitTestAddUnbalanced(UnbalancedSearchTree<int>* testTree, vector<int> randoms, int size) //Add some amount of random numbers to a tree to see how long it takes
{
	for (int i = 0; i < size; i++) //Iterate through the vector array
	{
		testTree->Insert(randoms[i]); //Add the integers to the tree
	}
};

void UnitTestDeleteUnbalanced(UnbalancedSearchTree<int>* testTree, vector<int> randoms, int size) //Remove some amount of random numbers from a tree to see how long it takes.
{
	for (int i = 0; i < size; i++) //Iterate through the vector array
	{
		testTree->Delete(randoms[i]); //Add the integers to the tree
	}
};

void UnitTest(int size) //Test performance with different tree sizes
{
	vector<int> randomArray;
	for (int i = 0;i < size;i++)
	{
		randomArray.push_back(rand() % 100000); //Add a random number between 0 and 99999 to the vector
	}
	WellsSearchTree<int>* testTree = new WellsSearchTree<int>(); //This tree will test performance with size integers
	UnitTestAdd(testTree, randomArray, size); //Add nodes to the tree
	cout << testTree->Maximum() << endl;
	UnitTestDelete(testTree, randomArray, size); //Remove nodes from the tree
};

void UnitTestUnbalanced(int size) //Test performance with different tree sizes
{
	vector<int> randomArray;
	for (int i = 0;i < size;i++)
	{
		randomArray.push_back(rand() % 100000); //Add a random number between 0 and 99999 to the vector
	}
	UnbalancedSearchTree<int>* testTree = new UnbalancedSearchTree<int>(); //This tree will test performance with size integers
	UnitTestAddUnbalanced(testTree, randomArray, size); //Add nodes to the tree
	cout << testTree->Maximum() << endl;
	UnitTestDeleteUnbalanced(testTree, randomArray, size); //Remove nodes from the tree
};

void RunUnitTests()
{
	UnitTest(100);
	UnitTest(1000);
	UnitTest(10000);
	UnitTest(100000);
	UnitTestUnbalanced(100);
	UnitTestUnbalanced(1000);
	UnitTestUnbalanced(10000);
	UnitTestUnbalanced(100000);
};

int main()
{
	WellsSearchTree<int> testTree; //Create an empty tree
	cout << testTree.Delete(3) << endl; //Test to make sure we do not crash when attempting an impoosible delete. Should return false.
	testTree.Insert(3); //Add a root node to the tree
	testTree.Insert(3); //Test to make sure we do not crash when inserting a duplicate node
	cout << testTree.Delete(3) << endl; //Test what happens when we delete a duplicate node. Should return true.
	testTree.Insert(4); //Add a node to the right of the root
	cout << testTree.Delete(3) << endl; //Test what happens when we delete a node with one non-duplicate child. Should return true.
	testTree.Insert(3); //Add a node to the left of the root 
	testTree.Insert(5); //Add a node to the right of the root
	cout << testTree.Delete(4) << endl; //Test what happens when we delete a node with two children. Should return true.
	cout << testTree.Traverse()->value << endl; //Test that we begin traversing at the root. Should return 3.
	cout << testTree.Traverse()->value << endl; //Test that we traverse to a child. Should return 5.
	cout << testTree.Traverse()->value << endl; //Test that we return to the root after traversing the tree. Should return 3.
	RunUnitTests(); //Run performance tests
}