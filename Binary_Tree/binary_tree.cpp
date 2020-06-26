#include <iostream>
#include <string>

using namespace std;

class EmployeeInfo {
public:
	string empName; // store employee name here
	int empNum; // store employee ID number here - key
	EmployeeInfo* left; // store address of left child node here
	EmployeeInfo* right; // store address of right child node here

	EmployeeInfo(int idNum, string name)
	{
		//both null to start
		EmployeeInfo* left = NULL;
		EmployeeInfo* right = NULL;
		empName = name;
		empNum = idNum;
	}
};

class BinaryTree
{
private:
	EmployeeInfo* root; //declare root of the tree
public:
	void add(int idNum, string name)
	{
		//declare new vars for examining nodes
		EmployeeInfo* newInfo = new EmployeeInfo(idNum, name);
		EmployeeInfo* traveler = new EmployeeInfo(idNum, name);

		//if root is null, declare new root
		if (!root) root = newInfo;

		//if not null
		else
		{
			//insert data into node

			//if less than, go left
			if (newInfo->empNum < root->empNum)
			{
				add(newInfo, root->left);
			}

			//if greater than, go right
			else if (newInfo->empNum > root->empNum)
			{
				add(newInfo, root->right);
			}

		}
	}

	void add(EmployeeInfo* newInfo, EmployeeInfo* childNode)
	{
		//sort left and right based on > or < current node
		//left
		if (newInfo->empNum < childNode->empNum)
		{
			if (!childNode->left)
			{
				childNode->left = newInfo;
			}
			else
			{
				add(newInfo, childNode->left);
			}
		}

		//right
		else if (newInfo->empNum > childNode->empNum)
		{
			add(newInfo, childNode->right);

			if (!childNode->right)
			{
				childNode->right = newInfo;
			}
			else
			{
				add(newInfo, childNode->right);
			}
		}
	}

	//check if id num is inside the tree
	bool isMember(int idNum, string name)
	{

	}
};



int main()
{
	return 0;
}
