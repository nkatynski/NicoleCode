# python implementation of a linked list
# recursion is a great way to waste memory for longer lists, but it works well enough for a small example

class Node:
    def __init__(self, value):
        self.val = value
        self.next = None

    def display(self):
        print(self.val)


class LinkedList:
    def __init__(self):
        self.head = None

    # given an value, will attempt to insert a node containing the value at the end of the linked list
    def add(self, value):
        # set head node if none exists
        if self.head is None:
            self.head = Node(value)
        else:
            self._insert_(Node(value), self.head)

    # hidden method called recursively to seek the tail node and perform the insertion
    def _insert_(self, new_node, current_node):
        # if the current node has no successor, the end has been reached; perform insertion
        if current_node.next is None:
            current_node.next = new_node
        # if not, recur
        else:
            self._insert_(new_node, current_node.next)

    # recursive method that navigates
    def is_member(self, value, current_node=None):
        # handles initial method call where no node is passed
        if current_node is None:
            current_node = self.head
        if current_node.val == value:
            membership = True
        elif (current_node.val == value) is False and current_node.next is None:
            membership = False
        # recur if value is not a match and the end has not been reached
        else:
            membership = self.is_member(value, current_node.next)
        return membership

    # recursive node deletion function, only deletes first instance
    def delete(self, value, current_node=None):
        # check if this is first function call
        if current_node is None:
            current_node = self.head
            # check if head node matches search value
            if self.head.val == value:
                # reassign next node to head if one exists
                if self.head.next is not None:
                    self.head = current_node.next
                # nullify the head otherwise
                else:
                    self.head = None
            # if head does not match search value, recur with next node
            else:
                self.delete(value, current_node.next)
        # if this is not the first function call and not the last link in the chain
        elif current_node.next is not None:
            # if the next node is a match
            if current_node.next.val == value:
                # if the next node has a following node of its own
                if current_node.next.next is not None:
                    # reassign current_node.next to the following node of its original following node
                    current_node.next = current_node.next.next
                # if the next node is the end of the chain
                else:
                    # nullify the current node's .next field
                    current_node.next = None
            # if the next node is not a match, recur with the next node
            else:
                self.delete(value, current_node.next)

    def display(self, current_node=None):
        if current_node is None:
            current_node = self.head
        current_node.display()
        if current_node.next is not None:
            self.display(current_node.next)


my_list = LinkedList()
values = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10]

for item in values:
    my_list.add(item)

my_list.display()
my_list.delete(4)
my_list.delete(1)
my_list.display()
