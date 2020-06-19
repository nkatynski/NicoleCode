These programs are exercises in the use of some very simple data structures (containers) and string parsing.

The idea is to take a string containing brackets "[,]" braces "{,}" or parentheses "(,)" and check for proper delimiting.

The rules stand as follows: 

- Each opening character must have exactly one complementary closing character. 
- The opening character in said pair must precede the closing character in the string.
- There can be multiple opening characters present before any closing characters, but not vice versa.
- Delimiting character types can be mixed (i.e. you can use brackets, braces, and parentheses in the same string) but must be paired only with complements of their type.
- All other characters can be safely ignored - we are only concerned about the delimiting characters.

EX:
[]	- OK
{{}}	- OK
[{}]	- OK
[{]}	- NO
[[][]]	- OK
[[]())	- NO
[(){}]	- OK

NOTE: Many text editors feature bracket-matching highlighting among other helpful color-coding features. This is great for checking the validity of your string before testing it with your program. I personally use Atom, but NotePad++ is also good. Plenty of options.

One of these programs performs the check using a stack. A stack is a type of container which can retain elements of a given type. "Pushing" an element into the stack inserts the element at the end. "Popping" an element from the stack removes it from that same end. The order of insertion/removal of elements in a stack is characterized as "Last In, First Out", or "LIFO". The STL contains a class template for stacks in C++; implement by including <stack> at the start of your program. You can implement stacks in Python using the deque class from the collections module if you are clever about it.

Queues are similar to stacks in that they store elements of one data type sequentially via pushing and popping elements to and from the stack. Queues are different in that elements are inserted at the end of the queue and removed from the front. This dynamic is characterized as "First In, First Out" or FIFO. Queues also have a class template in the C++ Standard Template Library, which can be implemented by inserting <queue>. Python has a queue module to aid in implementation.

These programs are supposed to take a string (my implementation polls the user, but this could also be done with a text file to rapidly test inputs), iterate through a string, check if it is correctly delimited according to the rules above, and declare whether or not the delimiting is valid.
