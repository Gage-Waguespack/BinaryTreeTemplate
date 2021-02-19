#ifndef _BINARYTREE_H_
#define _BINARYTREE_H_

#pragma once

class TreeNode;

class BinaryTree
{
public:

	BinaryTree() { m_root = nullptr; };
	~BinaryTree();

	///<summary>
	///Returns true if the root is set to nullptr.
	///</summary>
	bool isEmpty() const { return m_root == nullptr; };

	///<summary>
	///Inserts the given value into the tree.
	///</summary>
	void insert(int value);

	///<summary>
	///Finds and removes the node containing the given value.
	///</summary>
	void remove(int value);

	///<summary>
	///Returns a pointer to the node that holds the given value.
	///</summary>
	TreeNode* find(int value);

	///<summary>
	///Draws the tree and marks the given node as selected.
	///</summary>
	void draw(TreeNode* selected = nullptr);

private:
	///<summary>
	///Finds the node with the given value and its parent.
	///</summary>
	bool findNode(int searchValue, TreeNode*& nodeFound, TreeNode*& nodeParent);

	///<summary>
	///Calls draw for every node in the tree.
	///</summary>
	///<param name = "">The current node being drawn.</param>
	///<param name = "x">The x position to draw the node.</param>
	///<param name = "y">The y position to draw the node.</param>
	///<param name = "horizontalSpacing">The amount of space to place between this node and others that are on its level.</param>
	///<param name = "selected">The treenode that is currently selected.</param>
	void draw(TreeNode*, int x, int y, int horizontalSpacing, TreeNode* selected = nullptr);

	TreeNode* m_root;
};

#endif