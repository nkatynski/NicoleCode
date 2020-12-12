//Nicole Katynski
//Project 3
//UML Cache & derived classes

//START HERE and then put into separate files

#include<iostream>

using namespace std;

//base class
class Cache
{
protected:
	int size;
	int numItem;

	void setSize(int someSize)
	{
		//int dataCache[someSize];
		size = someSize;
	}
public:

	//i am not implementing ANYTHING class Cache - implement through derived classes
	Cache()
	{
		//def const
		//declare dynamic array
		int* arr;
		arr = new int[size];
	}
	void addInitial(int item)
	{
		//fill in the initial array
		for (int i = 0; i < size; i++)
		{
			//arr[i] = item
			//how do I fill in
			//normally i would cin the amount of elements
			//but i dont want to make the entire array full of one number
		}
	}

	//this fn for additing new items/searching
	void addItem(int item)
	{
		//before adding anything I need to search the array for item passed in
		//search algorithm searching arr
		/*
		for (int i = 0; i < size; i++)
		{

			if (arr[i] == item)
			{
				//if found
				//move it to the front - most recently used
				cout << "Found " << item << endl;
				//item = arr[0];

				//how do i bump everything else down?
			}

			else
			{
				//if not found
				cout << item << " not found" << endl;
				cout << "Adding into the array" << endl;
				//delete element at the back
				//delete arr[size];
				//bump everyone down one spot
				//put new element at the front since it is now the most recently used
				//item = arr[i];
			}
		}
		*/
	}

	int getIndexOfItem(int item)
	{
		//passing in a number
		//return the spot of the array it is in
		//meaning you are searching
		
		for (int i = 0; i < size; i++)
		{
			//if arr[i] = item;
			//return i;
			cout << "The index of " << item << " is" << i << endl;
		}
	}

	int getItemAtFront()
	{
		cout << "The item at the front of the array:"; // <<arr[0] << endl;
		//return arr[0]
	}
};

//derived class
class LRUCache: public Cache
{
	//least recently used
	//must remove least recently used from the cache
public:
	LRUCache()
	{
		//def const
	}

	LRUCache(int size)
	{
		//dynamically allocate an array for this to work
		int* arr;
		arr = new int[size];
	}

	void addItem(int item)
	{ 
		
		//NOTE - do not need to sort it here, it will NOT help you

		//now return the array with new member/rearranged vals inside
		for (int i = 0; i < size; i++)
		{
			//cout << arr[i] << " " ;
		}
		//cout << endl;

	}

	int getIndexOfItem(int item)
	{
		//if user searches in here, they are asking for how recently it has been used
		//search again, this time returning the index of the item they are searching for

		//if not found?
	}
};

//derived class
class LFUCache: public Cache
{
	//least frequently used
public:
	LFUCache()
	{
		//def const
	}

	LFUCache(int size)
	{
		//take size for dynamic array
		int* arr;
		arr = new int[size];
	}

	void addItem(int item)
	{
			//if found
			cout << "Found " << item << endl;
			//freq++
			//else add new value to the front

		//sort to put in order after you have added an item
		//bubble sort algorithm
		/*
		for (int i = 0; i < size - 1; i++)
		{
			for (int j = size - 1; j > i; j--) {
				if (arr[j] < arr[j - 1])
				{
					//swap
					int temp;
					temp = myArr[j];
					myArr[j] = myArr[j - 1];
					myArr[j - 1] = temp;
				}
			}
			
		}		
		*/


		//return sorted array
		/*
		for (int i = 0; i < size; i++)
		{
			cout << arr[i] << " ";
		}
		cout << endl;
		*/

	}

	int getIndexOfItem(int item)
	{
		//search through the sorted array
		//if user enters a value then you check what spot it is in the array
		//based on the frequency

		//return the index - not sure what i am supposed to do with the returned index though????

		//every time you search it and it is in the array you add 1 to freq

	}
};


int main()
{

	//Cache* myLRUCache = new LRUCache(cacheSize);
	//Or
	//Cache* myLFUCache = new LFUCache(cacheSize);

	//this is where you declare the size of your array which is then dyn all in the classes
	cout << "Fill in an array" << endl;
	cout << "How many values are you entering?" << endl;
	int numVals;
	cin >> numVals;

	//class obj
	LRUCache myCache;
	LFUCache myCache1;

	//how do I set size if its protected/inherited from another class?
	//setSize is basically my default constructor for the other two
	//since I pick a size and then the def const for the other classes dynamically allocates an arr
	//myCache.setSize(numVals);

	//calling addItem down here - loop based on how many items
	int item;
	for (int i = 0; i < numVals; i++)
	{
		cout << "Enter a value" << endl;
		cin >> item;

		//every time I ask for a value i call addItem and put it in my dyn arr
		//need to call this within LRU or LFU not Cache
		//do i need to call for both? i think yes?
		myCache.addItem(item);
		myCache1.addItem(item);
	}

	//after they fill in the array
	//then create a menu to call our other functions based on what the user wants to do
	//they have to enter a search value to be able to use the functions in LRU/LFU
	int searchVal;
	cout << "Enter a search value" << endl;
	cin >> searchVal;

	//searchVal = "item" in LRU and LFU
	//then we pass this into our class functions AND return the arrays with the new item
	//OR the sorted array (for LRU)

	//AND pass into class functions for LFU and if its there freq++
	//else add it and sort
	//either way return the sorted array to show the frequency and return frequency = ___

}