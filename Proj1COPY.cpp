//Nicole Katynski
//Proj 1
//To do list

#include<iostream>
#include<string>
#include<fstream>

using namespace std;

enum Type { Shopping, Dishes, Homework, Cooking, Laundry, PetCare };
enum Status { Done, InProgress, OnHold, NotStarted };

//temporarily set max size to 10 for testing
const int MAX_SIZE = 10;


//2 global functions
//copy to 2d array
//each row represents item type
void copy2D()//string title, string type)
{
	//this is how I put stuff in a 2d array but how do i copy it?
	//pass in 1d array i made earlier and add type to it?
	string toDoTitleType[MAX_SIZE][MAX_SIZE];
	for (int i = 0; i < MAX_SIZE; i++)
	{
		for (int j = 0; j < MAX_SIZE; j++)
		{
			cin >> toDoTitleType[i][j];
		}
	}
}

//copy to 3d array
//2nd dim = type
//3rd dim = priority

void copy3D()//string title, string type, int priority)
{
	//this is how i put stuff in a 3d array but how would I copy it????
	//pass in 1d array and add 3rd dimension to it?
	string toDoTitleTypePriority[MAX_SIZE][MAX_SIZE][MAX_SIZE];

	for (int i = 0; i < MAX_SIZE; i++)
	{
		for (int j = 0; j < MAX_SIZE; j++)
		{
			for (int k = 0; k < MAX_SIZE; k++)
			{
				cin >> toDoTitleTypePriority[i][j][k];
			}
		}
	}
}

class ToDoItem
{ 
private:
	int ID;
	string title;
	string description;
	int status;
	int priority;
	Type itemType;
	Status itemStatus;
	string todaysDate;
	string dueDate;
	string modDate;
	//create date struct
public:
	struct date
	{
		int day;
		int month;
		int year;
	};

	//default constructor
	ToDoItem()
	{
	}

	//constructor to initialize title, desc, type
	ToDoItem(string title, string description, Type userType)
	{
		title = title;
		description = description;
		userType = userType;
		//status = status.NotStarted;

		
	}

	//constructor to initialize title, type, priority
	ToDoItem(string title, Type userType, int priority)
	{
		title = title;
		userType = userType;
		priority = priority;


	}

	//constructor to initialize title, type, priority, due date
	ToDoItem(string title, Type userType, int priority, string date)
	{
		title = title;
		userType = userType;
		priority = priority;
		//this.date = date;
	}


	//where all user values will go
	//set and get functions
public:
	void setID(int newID)
	{
		ID = newID;
	}

	void setTitle(string newtitle)
	{
		title = newtitle;
	}

	void setType(Type newType)
	{
		itemType = newType;
	}

	void setDescription(string description)
	{
		description = description;
	}

	void setStatus(Status newStatus)
	{
		itemStatus = newStatus;
	}

	void setPriority(int newPriority)
	{
		priority = newPriority;
	}

	void setDueDate(string newDueDate)
	{
		dueDate = newDueDate;
	}

	void setTodaysDate(string newTodaysDate)
	{
		todaysDate = newTodaysDate;
	}

	void setModDate(string newModDate)
	{
		modDate = newModDate;
	}

	int getItemID()
	{
		return ID;
	}

	string getTitle()
	{
		return title;
	}

	int getType()
	{
		return itemType;
	}

	string getDescription()
	{
		return description;
	}

	int getStatus()
	{
		return status;
	}

	int getPriority()
	{
		return priority;
	}

	string getDueDate()
	{
		return dueDate;
	}

	string getTodaysDate()
	{
		return todaysDate;
	}

	string getModDate()
	{
		return modDate;
	}
};

class ToDoList
{
	//array of objects
	//showing titles entered by user

	ToDoItem myList[MAX_SIZE];
	//loop in information put in AddToDo

	//initialize empty to do list
public:
	ToDoList()
	{
		
	}

	//copy constructor
	ToDoList(string title)
	{

	}

private:
	
	int ID;
	string title;

	//default description
	string description = "The user has left no description for this item";
	int priority;
	int status;
	string dueDate;
	string todaysDate;
	string modDate;
	string temp;
	int userType;

public:

	void addToDo()
	{//taking in user input 
		/*
		ToDoItem setTitle();
		cout << "Enter task title (ex. Grocery Shopping)" << endl;

		for (int i = 0; i < MAX_SIZE; i++)
		{
			cin >> temp;
			myList[i].setTitle(temp);
		}
		*/

		editTitle();
		editDescription();

		//WITHIN EACH ITEM CALL SET/GET FNS???????
		//make int return type fn to return index of an ID
		//user enters task type 

		ToDoItem setType();
		cout << "Enter the number corresponsding to your task type: " << endl;
		cout << "(1 - Shopping, 2 - Dishes, 3 - Homework, 4 - Cooking, 5 - Laundry, 6 - Pet Care" << endl;
		int userType;
		//make an array to handle user input
		cin >> userType;
		switch(userType)
		{

		case 1:
			myList[ID].setType(Shopping);
		

		case 2:
			myList[ID].setType(Dishes);
	
		case 3:
			myList[ID].setType(Homework);
		
		case 4:
			myList[ID].setType(Cooking);

		case 5:
			myList[ID].setType(Laundry);

		case 6:
			myList[ID].setType(PetCare);
		
		//else
		default:
		
			cout << "Please enter a valid job type" << endl;
			cin >> userType; 
		
		}

		//user enters description

		//default description
		//ToDoItem setDescription();
		//string description = "The user has left no description for this item";

		//have user add a description
		//cout << "Add a job description" << endl;
		//string taskDescrip;
		//cin >> taskDescrip;

		//user enters status
		

		//user enters priority
		ToDoItem setPriority();
		cout << "Rate the task priority (1 = Highest Priority, 5 = Lowest Priority" << endl;
		cin >> priority;

		switch (priority) {

			case 1:
				cout << "You selected: 1 - Top Priority" << endl;
				myList[ID].setPriority(1);
			
			case 2:
				cout << "You selected: 2 - High Priority" << endl;
				myList[ID].setPriority(2);
			
			case 3:
				cout << "You selected: 3 - Medium Priority" << endl;
				myList[ID].setPriority(3);
		
			case 4:
				cout << "You selected: 4 - Low Priority" << endl;
				myList[ID].setPriority(4);
		
			case 5:
				cout << "You selected: 5 - Lowest Priority" << endl;
				myList[ID].setPriority(5);

			//else
			default:
				cout << "ERROR - INVALID INPUT" << endl;
				cout << "Try again" << endl;
				cin >> priority;
			
		}
		//user enters due date
		//using struct dueDate
		ToDoItem setDueDate();
		cout << "Enter task due date (mm/dd/yyyy)" << endl;
		cin >> dueDate;

		//user enters todays date
		//using struct createDate
		ToDoItem setTodaysDate();
		cout << "Enter today's date (mm/dd/yyyy)" << endl;
		cin >> todaysDate;
	}

	void editToDo()
	{
		int attribute;
		cout << "Which attribute do you want to edit?" << endl;
		cout << "Pick a number: (1 - Title, 2 - Description, 3 - Status)" << endl;
		cin >> attribute;
		//figure out which attribute
		//switch or if statement for task title,description, status

		switch (attribute) {

		case 1:
			//user chose title
			editTitle();


		case 2:
			//user chose descrip
			editDescription();

		case 3:
			//user chose status
			editStatus();
		}

		//user made modifications so set mod date
		ToDoItem setModDate();
		cout << "Enter today's date - (mm/dd/yyyy)" << endl;
		cin >> modDate;
	}
	string editTitle()
	{
		ToDoItem setTitle();
		cout << "Enter task title (ex. Grocery Shopping)" << endl;

		for (int i = 0; i < MAX_SIZE; i++)
		{
			cin >> temp;
			myList[i].setTitle(temp);
		}
		/*
		cout << "Enter your title changes" << endl;
		cin >> title;
		cout << "New title: " << title << " ." << endl;
		return title;
		*/
	}

	string editDescription()
	{
		ToDoItem setDescription();
		cout << "Enter your description changes" << endl;
		cin >> description;
		return description;
	}

	int editStatus()
	{	/*
		ToDoItem setStatus();
		cout << "Enter the new status" << endl;
		cin >> status;
		return status;
		*/

		ToDoItem setStatus();
		cout << "Enter the number corresponding to your task status: " << endl;
		cout << "(1 - Done, 2 - In Progress, 3 - On Hold, or 4 - Not Started)" << endl;
		cin >> status;

		//handle user input
		switch (status){
		case 1:
			myList[ID].setStatus(Done);

		case 2:
			myList[ID].setStatus(InProgress);
		
		case 3:
			myList[ID].setStatus(OnHold);
		
		case 4:
		//Status = NotStarted;
			myList[ID].setStatus(NotStarted);
		
		}
		if (status < 1 || status > 4)
		{
		//invalid input
		cout << "Please enter one of the listed statuses" << endl;
		cin >> status;
		}
	
	}

	void deleteToDo()
	{
		cout << "Choose a delete option: (1 - By ID, 2- By Task Type, 3 - By Task Status)" << endl;
		int userDeletePick;
		cin >> userDeletePick;

		if (userDeletePick == 1)
		{
			//delete by ID
			//ask for ID of num to be deleted
			cout << "Enter the ID of the item you want to delete" << endl;
			cin >> ID;

			cout << "Deleting " << ID << " " << title << endl;
			//delete ID;
			ID = 0;
		}

		else if (userDeletePick == 2)
		{
			//delete by type
			//multiples

			int deleteType = 1;
			cout << "Enter the type of task you want to delete: (1 - Shopping, 2 - Dishes, 3 - Homework, 4 - Cooking, 5 - Laundry, 6 - Pet Care" << endl;
			//cin which type and delete
			cin >> deleteType;
			//make a bool item for visible in listitem
			//check input
			switch(deleteType){

			case 1:
			{
				//delete shopping
			}

			case 2:
			{
				//delete dishes
			}

			case 3:
			{
				//delete homework
			}

			case 4:
			{
				//delete Cooking;
			}

			case 5:
			{
				//delete laundry;
			}

			case 6:
			{
				//delete petCare;
			}
		}
		}

		else if (userDeletePick == 3)
		{
			//delete by status

			int deleteStatus;
			cout << "Enter the number of the status you want to delete: (1 - Done, 2 - In Progress, 3 - On Hold, 4 - Not Started)" << endl;
			cin >> deleteStatus;

			switch(deleteStatus){
			//check input
			case 1:
			{
				//delete[] Done;
				//myList[ID].setStatus()
			}

			case 2:
			{
				//delete[] InProgress
			}

			case 3:
			{
				//delete[] OnHold;
			}

			case 4:
			{
				//delete[] NotStarted;
			}

		}
		}

		else
		{
			//invalid input
			cout << "ERROR - Invalid input, Try again" << endl;
			cin >> userDeletePick;
		}
	}

	void writeToText()
	{
		//writing TO a text file
		//NEEDS TO BE COMMA SEPARATED
		ofstream myFile;
		myFile.open("ToDo.txt");
		//myFile << "WRITING THE TO DO LIST HERE IN THIS FILE;
		myFile.close();
	}
	void readFromText()
	{
		//reading my to do list FROM the file i just wrote to
		string thisLine;
		ifstream myfile("ToDo.txt");
		if (myfile.is_open())
		{
			while (getline(myfile, thisLine))
			{
				cout << thisLine << endl;
				myfile.close();
			}

			//else
			cout << "Unable to open file";


		}
	}


		void printList()
		{
			//using get fns from to do item
			int userPrintPick;
			cout << "Select the number of your print option: (1- Print all items, 2- Print by task type, 3 - Print by task priority, 4 - Print by task ID)";
			cin >> userPrintPick;

			//check input

			//all items
			if (userPrintPick == 1)
			{
				//print all items in list
				cout << "Printing all items in list" << endl;
				//fn calls
				ToDoItem getID();
				ToDoItem getTitle();
				ToDoItem getType();
				ToDoItem getDescription();
				ToDoItem getStatus();
				ToDoItem getPriority();
				ToDoItem getDueDate();
				ToDoItem getTodaysDate();
				ToDoItem getModDate();

				for (int i = 0; i < MAX_SIZE; i++)
				{
					//cout << myList[i] << endl;
				}

				/*
				cout << "ID: " << ID << endl;
				cout << "Title: " << title << endl;
				//needs to have string not int - fix later
				cout << "Type: " << userType << endl;
				cout << "Task Description: " << description << endl;
				cout << "Task Priority: " << priority << endl;
				cout << "Task Status: " << status << endl;
				cout << "Task Due Date: " << dueDate << endl;
				cout << "Created On: " << todaysDate << endl;
				cout << "Last Modified On: " << modDate << endl;
				*/
			}

			//print by type
			else if (userPrintPick == 2)
			{
				//print by task type - print only one type
				int type;
				cout << "Enter a task type (1- Shopping, 2 -Dishes, 3 -Homework, 4 -Cooking, 5- Laundry, 6 - Pet Care)" << endl;
				cin >> type;

				switch(type){

				//check user input
				case 1:
					//print only shopping task items
					cout << "Printing shopping task items ONLY" << endl << endl;
					//ToDoItem getType(Shopping);

				case 2:
					//print only dishes task items
					cout << "Printing dishes task items ONLY" << endl << endl;
					//ToDoItem getType(Dishes);

				case 3:
					//print only homework task items
					cout << "Printing homework task items ONLY" << endl << endl;
					//ToDoItem getType(Homework);

				case 4:
					//print only cooking task items
					cout << "Printing cooking task items ONLY" << endl << endl;
					//ToDoItem getType(Cooking);

				case 5:
					//print only laundry task items
					cout << "Printing laundry task items ONLY" << endl << endl;
					//ToDoItem getType(Laundry);

				case 6:
					//print only pet care task items
					cout << "Printing pet care task items ONLY" << endl << endl;
					//ToDoItem getType(PetCare);

				defailt:
					//invalid input
					cout << "ERROR- invalid input, try again" << endl;
					cin >> type;
				
				}

			}

			//print by task priority
			else if (userPrintPick == 3)
			{
				//print only items with certain priority - ex only Top priority (1)
				int userPriority;
				cout << "Enter a Priority Number from 1-5" << endl;
				cin >> userPriority;

				//test input
				switch (userPriority) {

					//print highest priority
				case 1:
						//print top priority items ONLY
						cout << "Printing top priority tasks ONLY" << endl << endl;
						//ToDoItem getPriority(1);

					//high priority ONLY
				case 2:
						cout << "Printing high priority tasks ONLY" << endl << endl;
						//ToDoItem getPriority(2);

					//medium priority
				case 3:
						cout << "Printing medium priority tasks ONLY" << endl << endl;
						//ToDoItem getPriority(3);

					//low priority
				case 4:
						cout << "Printing low priority tasks ONLY" << endl << endl;
						//ToDoItem getPriority(4);

					//lowest priority
				case 5:
						cout << "Printing lowest priority tasks ONLY" << endl << endl;
						//ToDoItem getPriority(5);

				default:
						//invalid input
						cout << "ERROR - invalid input, try again" << endl;
						cin >> userPriority;
				}
			}

			//print ONLY ONE by task ID
			else if (userPrintPick == 4)
			{
				cout << "Enter the ID of the task you would like to print" << endl;
				cin >> ID;


				//unless the id does not exist
				//then print error statement and second prompt
				while (ID)
				{
					//ToDoItem returnID(ID);
				}
				while (!ID)
				{
					cout << "Task ID not found in system" << endl;
					cout << "Try another" << endl;
					cin >> ID;
				}

				//somehow print using this info
			}

		}

		void sortList()
		{
			//NEED YOUR ARRAY DESIGNED FIRST BEFORE BEING ABLE TO SORT ANYTHING
			//sort by different criteria
			//Sort by Priority, Due date, Create date,Type (with inner sort by Priority or Due Date)
			cout << "Select a Sorting Option: (1 - By Priority, 2 - By Due Date, 3 - By Create Date, 4 - By Type)" << endl;
			int sortPick;
			cin >> sortPick;

			switch (sortPick) {

			case 1:
				{
					//sort by priority
					cout << "Sorting To Do List by Priority" << endl << endl;

					//bubble sort 
					//for (int i = 0; i < MAX_SIZE - 1; i++)
						//for (int j = 0; j < MAX_SIZE - i - 1; j++)
							//if (myList[j] > myList[j + 1])
							///	swap(myList[j], myList[j + 1]);
				}

			case 2:
				{
					//by due date
					cout << "Sorting To Do List by Due Date" << endl;
				}

			case 3:
				{
					//by create date
					cout << "Sorting To Do List by Create Date" << endl;
				}

			case 4:
			{
				//by Type
				//inner sort by priority or due date
				cout << "Sorting To Do List by Type" << endl;
				cout << "Select an Inner Sort (1 - Priority, 2 - Due Date): " << endl;
				int innerSortPick;
				cin >> innerSortPick;

				switch (innerSortPick) {

				case 1:
					{
						//inner sort by Priority
						cout << "Inner Sorting by Priority" << endl;
						//then sort
					}

				case 2:
					{
						//inner sort by due date
						cout << "Inner Sorting by Due Date" << endl;
						//then sort
					}

				default:
					{
						//invalid input
						cout << "ERROR - Invalid input - Try again" << endl;
						cin >> innerSortPick;
					}
				}
			}
			}
		}

		void mergeList()
		{
			//merge = COMBINE with another array?????
		}

		string cloneList(string myList)
		{
			//deep copy 
			 
			//dyn allocate
			string *myList2 = new string [MAX_SIZE];

			for (int i = 0; i < MAX_SIZE; i++)
			{
				myList2[i] = myList[i];
			}

			//return cloneList;
		}

	};

	int main()
	{
		int choice = 1;
		//create user menu

		cout << "Menu: " << endl << endl;

		cout << " 1 - Add to Do" << endl;
		cout << " 2 - Edit to Do" << endl;
		cout << " 3 - Delete by task status" << endl;
		cout << " 4 - Write your list to a file" << endl;
		cout << " 5 - Read your list from a file" << endl;

		//sort by priority OR due date OR create date OR Type
		//TYPE inner sort by priority/due date
		cout << " 6 - Sort your file" << endl;

		//options to print all items, by type, by priority, 1 item by ID
		cout << " 7 - Print your list" << endl;

		cout << " 8 - Merge list" << endl;
		cout << " 9 - Clone list" << endl;
		cout << " 10 - QUIT" << endl;
		
		//while choice num is within my menu choices
		while (choice > 0 && choice < 11)
		{
			cout << "Enter the number of an action from the menu" << endl << endl;
			cin >> choice;

			//print automatically after any changes
			switch (choice)
			{
			case 1:
				//add to do
				cout << "Adding New Item:" << endl;
				//call all setfns for attributes/getUserInfo???
				//call add function
				ToDoList addToDo();
				ToDoList printList();
				break;

			case 2:
				//edit to do
				cout << "Editing Existing Item" << endl;
				//call edit function
				ToDoList editToDo();
				ToDoList printList();
				break;

			case 3:
				//delete to do
				cout << "Deleting Existing Item" << endl;
				//call delete function
				//delete one task OR multiple by diff parameters
				ToDoList deleteToDo();
				ToDoList printList();
				break;

			case 4:
				cout << "Writing To Do List to a File" << endl;
				//write to file
				//call write fn
				ToDoList writeToText();
				break;

			case 5:
				cout << "Reading To Do List from a File" << endl;
				//read from file
				//call read fn
				ToDoList readFromText();
				break;

			case 6:
				cout << "Sorting To Do List" << endl;
				//sort file
				//by diff parameters
				ToDoList sortList();
				ToDoList printList();
				break;

			case 7:
				cout << "Printing To Do List" << endl;
				//print list
				ToDoList printList();
				break;

			case 8:
				cout << "Merging To Do List" << endl;
				//merge list
				ToDoList mergeList();
				break;

			case 9:
				cout << "Cloning To Do List" << endl;
				//clone list
				ToDoList cloneList();
				break;
			case 10:
				cout << "EXITING PROGRAM" << endl;
				return 0;

			case 0:
				cout << "ERROR - Invalid Input" << endl;
				cout << "Please enter a different selection" << endl;
				cin >> choice;
			}
		}
	}
