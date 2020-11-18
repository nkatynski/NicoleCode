//Nicole Katynski
//Lab 8 Linked List of strings

#include<iostream>
#include<string>

using namespace std;

struct node
{
	string letter;
	node* next = nullptr;
};

const int SIZE = 10;

class List
{
private:
	node* head = nullptr;
public:
	void addNode(string myStr)
	{
		//create new node
		node* myNode = new node;

		//before adding a node I need to break string into chars
		int size = myStr.length();

		//make array of chars to go in linked list
		//for now size will be 71 since i cant have a const user input
		char myChar[SIZE];
		strcpy_s(myChar, myStr.c_str());
		//loop through char array to put in linked lits
		for (int i = 0; i < size; i++)
		{
			myNode->letter = myChar[i];
			cout << "Added " << myNode->letter << " to linked list" << endl;
			myNode->next = NULL;
		}

		//print out linked list
		cout << endl <<  "Contents of linked list = ";
		for (int i = 0; i < size; i++)
		{
			cout <<  myChar[i] << " ";
		
		}
		cout << endl;
	}

	void fromString(const string &word)
	{
		//create a list from a string
		//word1 and word2 are called into this fn
		addNode(word);		
	}

	string toString()
	{
		//create a string from a list
		//string that I will be printing out
		string newStr = ""; 

		//List myList;
		node* currNode = head;

		bool isNull = false;

		//loop through linked list 
		//if its not null then I take a value from it
		while (!isNull)
		{	
			// concatenate value to full string - STEP 1
			newStr += currNode->letter;

			// check to see if a child node exists
			if (currNode->next == nullptr) {  // if not
				isNull = true;  // change your loop-permission variable
			}
			else {  // if so
				// navigate to next node in the list before the loop repeats
				currNode = currNode->next;
			}
			
			//not sure if this line is right
			//but i need to check if the one next to me is null or not
			/*
			if (currNode->next == NULL)
			{
				//leave
			}

			else
			{
				//continue
				//move on to child node
				currNode = currNode->next;
			}
			*/
		}
		

		//print out string
		cout << "String from list = " << newStr << endl;
		return newStr;
	}

	//pass in one as a head
	//use a temp node = head node of list
	//when next = null then youve hit the end
	//while temp next not null
	//temp.next = the one i passed in
	List operator+ (const List& rhs)
	{
		
		//merge two lists together and create a new list containing both
		//pass in head node of list i want to append to the one im working on
		/*
		List list1;
		List list2;
		List mergeList;
		mergeList = list1 + list2;
		return mergeList;
		*/

		//the list i will be returning = combined list 1 and list 2
		List combList;
		node *tempNode;

		//while (tempNode->next != NULL)
		//{
			//tempNode.next = the one I passed in = rhs
			//tempNode->next = 
		//}
		//otherwise its null you hit the end
		return combList;


	}

	void deleteList(node*& ptr)
	{
		while (ptr)
		{
			//call recursively
			ptr = ptr->next;
			deleteList(ptr);
			node *prev = ptr;
		}
	}
	

	~List()
	{
		//destructor
		//while theres stuff in the list delete it
		List myList;
		node* currNode = head;
		while (currNode->next != NULL)
		{
			//delete currNode
			deleteList(currNode);
		}	
	}

	friend ostream& operator<<(ostream& out, const List& rhs)
	{
		//idk what is supposed to go here?
		return out;
	}
};

int main()
{
	
	List list1;
	List list2;
	List list3;
	string word1 = "cat";
	string word2 = "fish";
	string word3 = "";

	//add to list
	cout << "Adding the word: " << word1 << endl << endl;
	list1.fromString(word1);

	cout << endl << "Adding the word: " << word2 << endl << endl;
	list2.fromString(word2);
	cout << "Before toString()" << endl;
	word3 = list1.toString();
	cout << "After toString()" << endl;
	
	//it doesnt understand what list1 and list2 are? like it doesnt print them out?
	//should it be word1 and word2 since list1 and list2 are word1 and word2
	cout << word1 << " + " << word2 << " = ";

	//this calls operator function to merge list - merge list 1 list 2
	list3 = list1 + list2;
	cout << list3 << endl; //cat + fish = catfish
}