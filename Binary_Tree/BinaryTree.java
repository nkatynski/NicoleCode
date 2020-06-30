import java.io.*;
import java.util.Scanner;

public class BinaryTree {

  Node root; // root of the binary tree

  static class Node {
    int empID; // stores employee ID number
    String empName; // stores employee name
    Node left; // references left child node
    Node right; // references right child node

    // constructor method
    Node(int number, String name) {
      empID = number;
      empName = name;
      left = null;
      right = null;
    }
  }

  public static BinaryTree add(BinaryTree tree, int idNum, String name) {
    Node newNode = new Node(idNum, name); // construct node using method arguments
    if(tree.root == null) tree.root = newNode; // set new tree root if none
    else tree.add(newNode, tree.root); // begin recursive insertion operation
    return tree;
  }

  public static void add(Node newNode, Node currentNode) {
    if(newNode.empID < currentNode.empID){ // node key value comparison, left child condition
      if(currentNode.left == null) {
        currentNode.left = newNode; // if no left child exists, new node is new left child
        //System.out.println("Left insertion attempt.");
      }
      else add(newNode, currentNode.left); // if left child exists, recur

    }
    else if(newNode.empID > currentNode.empID){ // node key value comparison, right child condition
      if(currentNode.right == null) {
        currentNode.right = newNode; // if no right child exists, new node is new right child
        //System.out.println("Right insertion attempt.");
      }
      else add(newNode, currentNode.right); // if right child exists, recur
    }
    // duplicate values are not allowed in a binary search tree
    else System.out.println("ERROR: Attempt to insert redundant ID into tree, operation aborted. Offending ID#: " + newNode.empID);
  }

  public static String isMember(Node currentNode, int idNum) {
    String searchResult = "No employee"; // fits the prompt for a name search as well as a name does
    if(currentNode != null){ // prevent segmentation faults by preventing examination of nulls
      if(idNum == currentNode.empID) searchResult = currentNode.empName; // track name associated with nodes of a matching key
      // recur left if the searched ID is less than the key of the current node
      else if(idNum < currentNode.empID) searchResult = isMember(currentNode.left, idNum);
      // recur right if the searched ID is greater than the key of the current node
      else if(idNum > currentNode.empID) searchResult = isMember(currentNode.right, idNum);
    }
    return searchResult;
  }

  public static void main(String[] args) {
    BinaryTree myTree = new BinaryTree();
    Scanner myScanner = new Scanner(System.in);
    int[] empNums = new int[]{1021, 1057, 2487, 3769, 1017, 1275, 1899, 4218};
    String[] empNames = new String[]{"John Williams", "Bill Witherspoon", "Jennifer Twain", "Sophia Lancaster", "Debbie Reece", "George McMullen", "Ashley Smith", "Josh Plemmons"};

    for(int i = 0; i < 8; i++) myTree.add(myTree, empNums[i], empNames[i]); // insert employee data into the tree

    System.out.print("Enter an employee ID# to search for: ");
    int searchID = myScanner.nextInt(); // poll user
    System.out.println(myTree.isMember(myTree.root, searchID) + " has the employee ID #" + searchID); // display search results
  }
}
