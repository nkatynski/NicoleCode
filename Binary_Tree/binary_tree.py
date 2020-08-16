# python implementation of basic binary tree

# as mentioned elsewhere, recursive methods on trees of possibly vast unknown size is bad, but this is for fun

class Node:
    def __init__(self, emp_name, emp_num):
        self.name = emp_name
        self.num = emp_num
        self.left = None
        self.right = None

    def display(self):
        print(str(self.num) + ": " + self.name)


class BinaryTree:
    def __init__(self):
        self._root = None

    def add(self, emp_name, emp_num):
        if self._root is None:
            self._root = Node(emp_name, emp_num)
        # handoff to recursive insertion function
        else:
            self._insert_(Node(emp_name, emp_num), self._root)

    def _insert_(self, new_node, current_node):
        # redundant insertion case
        if new_node.num == current_node.num:
            print("ERROR: All keys must be unique. Collision value: #" + str(new_node.num))
        # left branch case
        elif new_node.num < current_node.num:
            if current_node.left is None:
                current_node.left = new_node
            else:
                self._insert_(new_node, current_node.left)
        # right branch case
        elif new_node.num > current_node.num:
            if current_node.right is None:
                current_node.right = new_node
            else:
                self._insert_(new_node, current_node.right)

    def is_member(self, value):
        if self._root.num == value:
            return True
        # handoff to recursive insertion function
        else:
            return self._search_(value, self._root)

    def _search_(self, value, current_node):
        if current_node.num == value:
            membership = True
        elif value < current_node.num and current_node.left is not None:
            self._search_(value, current_node.left)
        elif value > current_node.num and current_node.right is not None:
            self._search_(value, current_node.right)
        else:
            membership = False
        return membership

    def in_order(self, current_node=None):
        if current_node is None:
            current_node = self._root
        if current_node.left is not None:
            self.in_order(current_node.left)
        current_node.display()
        if current_node.right is not None:
            self.in_order(current_node.right)

    def pre_order(self, current_node=None):
        if current_node is None:
            current_node = self._root
        current_node.display()
        if current_node.left is not None:
            self.in_order(current_node.left)
        if current_node.right is not None:
            self.in_order(current_node.right)

    def post_order(self, current_node=None):
        if current_node is None:
            current_node = self._root
        if current_node.left is not None:
            self.in_order(current_node.left)
        if current_node.right is not None:
            self.in_order(current_node.right)
        current_node.display()


emp_nums = [1021, 1057, 2487, 3769, 1017, 1275, 1899, 4218]
emp_names = ["John Williams", "Bill Witherspoon", "Jennifer Twain", "Sophia Lancaster",
             "Debbie Reece", "George McMullen", "Ashley Smith", "Josh Plemmons"]
my_tree = BinaryTree()

for i in range(len(emp_nums)):
    pass
    my_tree.add(emp_names[i], emp_nums[i])

my_tree.post_order()
