import java.io.*;

public class LinkedList {

  Node head;  // head of the linked list

  // linked list node
  static class Node { // inner class is static to allow main() to access it
    double val;
    Node next;

    // constructor
    Node(double v) {
      val = v;
      next = null;
    }
  }

  public static LinkedList insert(LinkedList list, double val) {
    Node newNode = new Node(val);

    if(list.head == null) list.head = newNode;
    else {
      Node last = list.head;
      while (last.next != null) last = last.next;
      last.next = newNode;
    }

    return list;
  }

  public static boolean isMember(LinkedList list, double val) {
    boolean membership = false;
    boolean runSearch = true;
    Node currentNode = list.head;

    if(currentNode.val == val) membership = true;
    while (runSearch && !membership) {
      if(currentNode.val == val) membership = true;
      else {
        if(currentNode.next != null) currentNode = currentNode.next;
        else runSearch = false;
      }
    }

    return membership;
  }

  public static void main(String[] args) {
    LinkedList myList = new LinkedList();
    double searchVal = 7.28;

    myList = insert(myList, 7.28);
    myList = insert(myList, 1.23);
    myList = insert(myList, 4.56);
    myList = insert(myList, 7.89);
    myList = insert(myList, 6.42);
    myList = insert(myList, 9.63);

    if(isMember(myList, searchVal)) System.out.println(searchVal + " is a member.");
    else System.out.println(searchVal + " is NOT a member.");
  }
}
