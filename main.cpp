/*********************************************************************
 ** Program name: linkedList.cpp
 ** Author: reuben youngblom
 ** Date: 2/19/17
 ** Description: linkedList implementation file for Lab 6.  I used the code from a youtube
        video called Paul Programming as a guidline and apapted it from there.
 *********************************************************************/

#include <iostream>
using namespace std;


int main() {
    char againCIN;  //to take input to test whether program re-runs
    bool againBool = true;  //tests whether program re-runs
    char testDone;  //char to test whether user want to keep adding numbers
    int place;  //places input int into data section
    
    cout << "Welcome to my Linked List!" << endl;  //introductory text
    
    
    while (againBool == true)  //to test whether user wants to run through program again
    
{
    
    struct node  //creates the data structure of node
        {
            int data;  //creates the "data" part to hold integers
            node * next;  //creates the "pointer" to point to next node
        };
    
    
    node * n;  //current node pointer
    node * t; //tail position pointer
    node * h;  //head position pointer
    
    cout << "enter a number: " << endl;  //user prompt
    cin >> place;  //takes user input

    
    n = new node;  //creates new node
    n -> data = place;  //puts user-input int in data section
    t = n;  //head and tail are both where n is, because there is only one node so far
    h = n;
    
    int count = 1;  //to let user input one number at least (see below)
    
    while (testDone != 'n')  //as long as user keeps entering 'y'....
    {
        if (count == 1)  //and if this is the first time through....
        {
            cout << "thanks!  Would you like to enter more?" << endl;  //just jump to this
            cout << "Please enter 'y' for yes or 'n' for no" << endl;   //it asks if user is done
            cin >> testDone;  //and takes input
            count ++;  //and increases count so this will never ever run again
            if (testDone == 'n')  //if user is done, breaks out of the loop
            {break;}
        }
        
        //but if not.... contintues below
        
        cout << "enter a number: " << endl;  //user prompt
        cin >> place;  //and takes in data
        
    n = new node;  //and creates a new node
    n -> data = place;  //and puts user-entered int into data section
    t -> next = n;  //and sets "next" of tail (pointer) to next node
    t = t->next;  //and advances t
        
        cout << "thanks!  Would you like to enter more?" << endl;  //user prompts
        cout << "Please enter 'y' for yes or 'n' for no" << endl;  //user prompts
        cin >> testDone;  //takes in input
    }  //if user enters anything but n, loop keeps going.
    
    cout << endl;
    
    cout << "Thanks!  Your linked list is: " << endl;  //when user is done and breaks out of loop, displays the list
     
    n -> next = NULL;  //by first ending it with a NULL
    
    
    node * ptr = h;  //then setting a new node pointer to the head
    
    while (ptr != NULL)  //and saying, "until it hits NULL...."
    {
        cout << ptr->data << " ";  //"print out data in succession"
        ptr = ptr -> next;  //"and then advance pointer to go to next node"
    }
    
    
    cout << "Do you want to get head or tail node value? (h or t): " << endl;  //user prompt
    cin >> testDone;  //takes in inout (recycled variable because it isn't needed anymore)
    
    if (testDone == 'h')  //if user chooses head...
    {
        cout << endl;  //for readibility
        node * ptr = h;  //sets pointer to head
        cout << "Your Head node is: " << endl;
        cout << ptr->data;  //and prints it
        cout << endl;  //for readibility.  All of the cout << endl;'s are for readbility
    }
    
    else if (testDone == 't')  //but if they want the tail....
    {
        cout << endl;
        node * ptr = t;  //sets pointer equal to tail (I could have only created this once, but I copy/pasted the above code, so).
        cout << "Your Tail node is: " << endl;  //user info
        cout << ptr->data;  //and prints out tail data number
        cout << endl;
    }
    
    //then, the program asks user if they want to delete head or tail
    cout << "Do you want to delete head or tail node value? (h or t): " << endl;
    cin >> testDone;  //and take input in same recycled variable
    
    if (testDone == 'h')  //if they choose head
    {
        if (h == NULL)  //if there's nothinf in the list (i.e. no head),
        {
            cout << endl;
            cout << "List is empty!" << endl;  //say list is empty
        }
        
        else  //but if there are values....
        {
        
        cout << endl;
        node *temp = h;  //create temp pointer and set to head
        temp = h -> next;  //set that equal to the node AFTER head
        delete h; //delete head
        h = temp;  //and place h pointer at "temp", which was the next one in line.  This is the new head
        
        node * ptr = h;  //and print it out just like above
        cout << "Your new Head node is: " << endl;
        cout << ptr->data;
        cout << endl;
        }
    }
        
    
    else if (testDone == 't')  //similar thing with tail
    {
        
        if (h == NULL)  //if list is empty, say so.
        {
            cout << endl;
            cout << "List is empty!" << endl;
        }
        
        else  //but if there are values
        {
        cout << endl;
        
        node *temp = h;  //find head node
        while(temp->next!=t)  //and advance through list until just before tail.  temp->next will only equal t on the node just before t
        {
            temp=temp->next;  //this advances it and sets temp equal to current node
        }
        
        delete t;   //so then, delete the tail
        temp->next=NULL;  //set the one before the 'old' tail to NULL
        t=temp;  //and then assign the 'temp' (which was the one before the old tail) to be the new tail.
        
        node * ptr = t;  //and then print it out just like above
        cout << "Your new Tail node is: " << endl;
        cout << ptr->data; //prints data
        cout << endl;
        }
    }
        cout << endl;
        cout << "would you like to do this again? (y/n)" << endl;  //user info
        cin >> againCIN;  //takes user inout to see if they want to do it again
        
        if (againCIN == 'y')  //if yes, keeps test bool the same
        {againBool = true;}
        
        else if (againCIN == 'n') //but if no....
        {againBool = false;} //sets it to false so the loop won't run again
       
        else  //and if they enter something wonky, just exit the program.
        {
            cout << "sorry!  Invalid response.  Exiting." << endl;
            againBool = false;
        }
        
        
    }
    
    return 0;
}
