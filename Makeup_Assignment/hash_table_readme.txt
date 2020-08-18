Your assignment is to create a working hash table in Python. This can be done in most languages but I found it to be especially easy using Python.

A hash table is a data structure similar to an array that stores values using hash codes. A hash code is a number calculated using the value you are inserting whose final value must not exceed the index of the last bucket of your hash table. A bucket is the term for the areas where your entries are stored inside your hash map, accessible by index.

In other words, given an entry you are attempting to insert, a hash table will calculate the corresponding hash code for that entry, navigate to the bucket at the index referenced by the hash code, and insert the entry into the bucket. A functional hash table must be able to add elements, delete elements, and search for elements. These are among the method definitions I have started for you. Here is what I expect each method to be able to do:

__init__(): This is your constructor method. I have completed this one, it is fine as is.

_hash_():   This method takes in a term (a string) and returns a calculated hash code using a mathematical function of your choice. The hash function I wrote converts the inserted string to uppercase, iterates through the characters one by one, and produces a sum of the ASCII values of each of the characters in the string. This sum is then compressed (divided modularly) by the number of buckets in your table. You can use a different hash function if you like (or create your own from scratch), the table will work fine as long as the same entry produces the same hash code every time. A good hash function will produce as few collisions as possible (a collision is when multiple entries are assigned to the same bucket of a hash function - the idea is to have the entries be placed into separate buckets as often as possible).

_search_(): This method takes in a term (a string) and conducts a search on the hash table to check if the term has been entered. A good way to do this is to calculate the hash code for a given term, navigating to the bucket at the corresponding index, and searching the bucket to see if the entry is present. If found, the function returns True. If not, the function returns False. Note: the init, hash, and search functions are all private methods of the HashMap class, meaning they can only be called from within other methods of that class.

find():     This method takes in a term (a string) and conducts a search on the hash table to check if the item has been entered. This sounds extremely similar to _search_(), but it is not the same: this method prints a message confirming or denying that the term was located inside the hash map. The utility of this method is that it allows you to conduct searches without receiving a confirmation message each time; if you are using your search function inside insert() or remove() (which I *highly* recommend), printing the receipt each time is unhelpful, but a public method to do so periodically is very helpful.

insert():   This method takes in a term (a string) and inserts it into the hash table. The easiest way to do this is to calculate the hash code corresponding to your term, navigate to the bucket at which the term is stored, and appending the term to the bucket. Note: a hash table should have no redundant entries, so be sure to check that your term is not already an entry in the bucket before inserting a term.

remove():   This method takes in a term (a string) and removes it from the hash table. The easiest way to do this is to calculate the hash code corresponding to your term, navigate to the bucket at which the term is stored, and removing the term from the bucket. Note: it is good to check that an item is present before removing it from the bucket, lest you cause an error.

display():  This method will print out your entire hash table to the terminal. It will iterate through each bucket and then print the entries in each bucket one by one. For instance, if the hash map were full of produce:
  0: apples
  1: kiwi, asparagus
  2:
  3: kumquat
  4: banana
The hash function is irrelevant here, this is simply a formatting example.

For this example, I have a list of band names for groups I listen to regularly. I want your finished HashMap class to be capable of inserting every band name from the list of strings into the hash table, adding or removing additional entries individually, conducting searches for entries, and displaying all contents at the terminal. I strongly recommend you research the following topics if you are confused or stuck: hash tables, hash maps, hash codes, Lists in Python, Python classes, Python methods, private vs public Python class methods, iterators, the range() function, modular division.

I designed this hash map as a list of lists. This is how the __init__ function will prepare it, so I *highly* recommend learning how lists work in Python along with a few of the built-in methods for lists.

Hash tables are useful because they allow for near-instant searches compared to arrays. If you were looking for a value in an array but did not know the index it was stored at, you would possibly have to search the entire array to find it, making for a time complexity of O(n) where n is the number of entries in your array. This can be reduced substantially by storing items in your array methodically, assigning entries to indices using a calculated code (used for lookups as well). In worst cases, if your hash function returns only a single value and all entries end up colliding in the same bucket, it is no better than a regular array, search efficiency hitting O(n). Best case, all entries wind up in distinct buckets, dropping time complexity for searches to O(1) as you will be directed straight to the storage location for the entry in question and have to filter through no other values to find it. The most likely scenario is somewhere in between, especially as the number of entries grows; it is crucial that I can see which bands are my favorites as quickly as possible.

Feel free to reach out for guidance, this is a lot to take on, but self-directed progress will be rewarded considerably more heavily.
