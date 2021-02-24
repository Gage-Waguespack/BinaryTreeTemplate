#include "BinaryTree.h"
#include "TreeNode.h"
#include "raylib.h"

BinaryTree::~BinaryTree()
{
	//This destructor will utilize remove to remove everything in the list, including all pointers... this will allow us to destroy the entire tree in one call!
	while (m_root->hasLeft() || m_root->hasRight())
	{
		//removes the root and everything attached to it
		remove(m_root->getData());

		//deletes the root after everything else is removed
		delete m_root;
	}
}

void BinaryTree::insert(int value)
{
	//If the tree is empty, set the root to be a new node with the given value.
	if (isEmpty())
	{
		m_root = new TreeNode(value);
		return;
	}

	//Create a TreeNode pointer that will act as an iterator pointing to the current node and set it to the root.
	TreeNode* currentNode = m_root;

	//Create a TreeNode pointer that will act as an iterator pointing to the parent 
	//of the current node and set it to the root.
	TreeNode* nodeParent = m_root;

	//Loop until the the current node iterator reaches a nullptr.
	while (currentNode != nullptr)
	{
		//Check if the value we want to add to the tree is less than the value at the current node.
		if (value < currentNode->getData())
		{
			//Set the parent node to be the current node before the current node moves positions.
			nodeParent = currentNode;
			//Change the current node to be the child to its left and continue.
			currentNode = currentNode->getLeft();
		}

		//Check if the value we want to add to the tree is greater than the value at the current node.
		else if (value > currentNode->getData())
		{
			//Set the parent node to be the current node before the current node moves positions.
			nodeParent = currentNode;
			//Change the current node to be the child to its right and continue.
			currentNode = currentNode->getRight();
		}

		//If the value is the same as a value already in the list return 
		else if (value == currentNode->getData())
		{
			return;
		}
	}
	//end loop

	//If the value we want to add is less than the value of the parent node, insert the value to the left.
	if (value < nodeParent->getData())
	{
		nodeParent->setLeft(new TreeNode(value));
	}

	//Otherwise, insert the value to the right.
	else if (value > nodeParent->getData())
	{
		nodeParent->setRight(new TreeNode(value));
	}
}

void BinaryTree::remove(int value)
{
	//Create two TreeNode pointers: one to hold a reference to the node we want to remove
	//and another to hold a reference to its parent.

	//Pointer to a node
	TreeNode* currentNode{};

	//Pointer to the parent of iter1's node
	TreeNode* nodeParent{};

	//Try to find the node that matches the value given and its parent in the tree.
	//If the node cannot be found return.
	if (value != currentNode->getData())
	{
		return;
	}

	//Check to see if the node has a right
	currentNode->hasRight();

		//Initialize two iterators to find the node whose data will be copied and its parent.
	TreeNode* iter1{};
	TreeNode* iter2{};

	TreeNode* toRemove = find(value);

		//Set the first iterator to point to the right child of the node we want to remove.
	iter1 = toRemove->getRight();

		//Loop while the first iterator has a value to its left
	while (iter1->hasLeft())
	{
		//Set the second iterator to be the value of the first iterator.
		iter2 = iter1;

		//Set the first iterator to be the value to the left of it
		iter1 = iter1->getLeft();

		//end loop
	}
		//Once the smallest value has been found, copy the data in first iterator to the node we want to remove.
	

		//Check if the second iterator has a left child.
	if (iter2->hasLeft())
	{
		//Check if the left child stores the same data as the node we wanted to remove.
		if (iter2->getLeft()->getData() == value)
		{
			//Set the second iterators left child to be the first iterators right child.
			iter2->setLeft(iter1->getLeft());
		}
	}

		//Check if the second iterator has a right child.
	if (iter2->hasRight())
	{
		//Check if the right child contains the same data as the node we want to remove.
		if (iter2->getRight()->getData() == value)
		{
			//Set the right child of the second iterator to be the right child of the first iterator.
			iter2->setLeft(iter1->getRight());
		}
	}
		//Delete the first iterator
	iter1 = nullptr;
	delete(iter1);

	//Otherwise, if the node doesn't have a right child
	if(!currentNode->hasRight())

		//check if the parent of the node to remove has a left child.
		if (nodeParent->hasLeft())
		{
			//Check if the data that the left child holds is the same as the data the node to remove holds.
			if (nodeParent->getLeft()->getData() == value)
			{
				//Set the left child of the parent node to be the left child of the node to remove.
				nodeParent->setLeft(currentNode->getLeft());
			}
		}
		//Check if the parent of the node to remove has a right child.
	if (nodeParent->hasLeft())
	{
		//Check if the data the right child holds is the same as the data the node to remove holds.
		if (nodeParent->getRight()->getData() == value)
		{
			//Set the right child of the parent node to be the left child of the node to remove.
			nodeParent->setRight(currentNode->getRight());
		}
	}

		//Check if the node we want to remove is the root.
	if (value == m_root->getData())
	{
		//Set the root to be its left child.
		m_root = m_root->getLeft();

		//Delete the pointer that points to the node to remove.

	}
}

TreeNode* BinaryTree::find(int value)
{
	//Initialize an iterator starting at the root.
	TreeNode* iter = m_root;

	//Loop through the tree while the iterator isn't nullptr.
	if (iter != nullptr)
	{
		//Check if the node has the data we want
		if (iter->getData() == value)
		{
			//Return the iterator
			return iter;
		}
		//If the node doesn't have the data we want, check to see if it's higher in value.
		else if (iter->getData() != value)
		{
			if (iter->getData() < value)
			{
				//Set the iterator to be its current right child.
				iter = iter->getRight();
			}
		}
		//If the node doesn't have the data we want, check to see if it's lower in value.
		else if (iter->getData() != value)
		{
			if (iter->getData() > value)
			{
				//Set the iterator to be its current left child.
				iter = iter->getLeft();
			}
		}
	//end loop
	}
	//Return nullptr
	return nullptr;
}

void BinaryTree::draw(TreeNode* selected)
{
	draw(m_root, 400, 40, 400, selected);
}

bool BinaryTree::findNode(int searchValue, TreeNode*& nodeFound, TreeNode*& nodeParent)
{
	//Create two iterators: one that will point to the current node to compare the search value to,
	//and the other to hold a reference to the parent.
	TreeNode* currentNode{};
	TreeNode* parentNode{};

	//Loop while the current node iterator isn't nullptr/
	while (currentNode != nullptr)
	{
		//Check if the search value is the same as the current nodes data.
		if (currentNode->getData() == searchValue)
		{
			//Set the node found argument to be the current node and the parent node to be the parent node iterator.
			nodeFound = currentNode;
			nodeParent = parentNode;

			//Return true.
			return true;
		}
		//Check if the search value is greater than the value at the current node.
		if (searchValue <= currentNode->getData())
		{
			//Set the parent node to be the current node.
			parentNode = currentNode;
			//Set the current node to be the child to the right of the current node.
			currentNode = currentNode->getRight();
		}
		//Check if the search value is less than the value at the current node.
		if (searchValue > currentNode->getData())
		{
			//Set the parent node to be the current node.
			parentNode = currentNode;
			//Set the current node to be its left child.
			currentNode = currentNode->getLeft();
		}
	//end loop
	}

	//Return false.
	return false;
}

void BinaryTree::draw(TreeNode* currentNode, int x, int y, int horizontalSpacing, TreeNode* selected)
{
	//Decrease the horizontal space as the nodes draw
	horizontalSpacing /= 2;

	//Checks if the current node is null
	if (currentNode)
	{
		//Draw the left child if this node has one 
		if (currentNode->hasLeft())
		{
			//Draws a line between the left child and the current node
			DrawLine(x, y, x - horizontalSpacing, y + 80, RED);
			//Draws the left child
			draw(currentNode->getLeft(), x - horizontalSpacing, y + 80, horizontalSpacing, selected);
		}

		//Draws the right child if this node has one 
		if (currentNode->hasRight())
		{
			//Draws a line between this child and the current node
			DrawLine(x, y, x + horizontalSpacing, y + 80, RED);
			//Draws the right child
			draw(currentNode->getRight(), x + horizontalSpacing, y + 80, horizontalSpacing, selected);
		}
		//Draws the current node
		currentNode->draw(x, y, (selected == currentNode));
	}
}
