// C++ implementation of the binary tree example

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
    empName = name;
		empNum = idNum;
		EmployeeInfo* left = NULL;
		EmployeeInfo* right = NULL;
	}
};

class BinaryTree
{
private:
	EmployeeInfo* root;
public:
	void add(int idNum, string name) // inserts node containing the employee's name and ID into the tree at the correct spot
	{
		EmployeeInfo* newInfo = new EmployeeInfo(idNum, name); // insert employee info into new node
		if (!root) root = newInfo; // if root is null, set the new node as the root
		else add(newInfo, root); // if a root exists, call add function at the root
	}

	void add(EmployeeInfo* newInfo, EmployeeInfo* childNode)
	{
		if (newInfo->empNum < childNode->empNum) // if the key of the new node is less than that of the child node being compared
		{
			if (!childNode->left) childNode->left = newInfo; // if no left child exists, set the new node as the left child node
			else add(newInfo, childNode->left); // if a left child exists, call add function again upon the left child, repeat process
		}
		else if( newInfo->empNum > childNode->empNum) // if the key of the new node is greater than that of the child node being compared
		{
			if (!childNode->right) childNode->right = newInfo; // if no right child exists, set the new node as the right child node
			else add(newInfo, childNode->right); // if a right child exists, call the add function again upon the right child, repeat process
		}
    // duplicate values are not allowed in a binary search tree
    else cout << "ERROR: Attempt to insert redundant ID into tree, operation aborted. Offending ID#: " << newInfo->empNum << endl;
	}

	string isMember(int idNum) // searches for a node with a key matching that of the searched ID number, returns employee name if found
	{
    string searchResult = "No employee"; // cleverly fits the prompt if no name is found
    bool runSearch = true; // for terminating the search if a dead end is reached or the searched key is located
    EmployeeInfo *currentInfo;
    if (root) { // search only conducted if a root exists
      currentInfo = root;
      while (runSearch) {
        if (idNum == currentInfo->empNum) { // if the searched ID# equals the key of the current node
          searchResult = currentInfo->empName; // take the name from the node with the matching key
          runSearch = false; // terminate search
        }
        else if (idNum < currentInfo->empNum) { // if the search value is less than the key
          if (currentInfo->left) currentInfo = currentInfo->left; // if a left node exists, change current node to its current left child
          else runSearch = false; // if no child, cancel the search
        }
        else { // if the search value is greater than the key
          if (currentInfo->right) currentInfo = currentInfo->right; // if a right node exists, change current node to its current right child
          else runSearch = false; // if no child, cancel the search
        }
      }
    }
    return searchResult;
	}

  BinaryTree()
  {
    root = NULL;
  }
};

int main()
{
  BinaryTree myTree;
  int searchID;
  int empNums[8] = {1021, 1057, 2487, 3769, 1017, 1275, 1899, 4218};
  string empNames[8] = {"John Williams", "Bill Witherspoon", "Jennifer Twain", "Sophia Lancaster", "Debbie Reece", "George McMullen", "Ashley Smith", "Josh Plemmons"};

  for(int i = 0; i < 8; i++) myTree.add(empNums[i], empNames[i]);
  cout << "Enter an Employee ID# to search for: ";
  cin >> searchID;

  cout << myTree.isMember(searchID) << " has the employee ID #" << searchID << "." << endl;
	return 0;
}
