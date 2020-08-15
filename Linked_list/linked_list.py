# python implementation of a linked list
# recursion is a great way to waste memory for longer lists, but it works well enough for a small example

class Node:
    def __init__(self, value):
        self.val = value
        self.next = None


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
            membership = self.is_member(value, self.head)
        elif current_node.val == value:
            membership = True
        elif (current_node.val == value) is False and current_node.next is None:
            membership = False
        # recur if value is not a match and the end has not been reached
        else:
            print("Recur!")
            membership = self.is_member(value, current_node.next)
        return membership


my_list = LinkedList()
values = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10]

for item in values:
    my_list.add(item)

result = my_list.is_member(1)
print(result)
