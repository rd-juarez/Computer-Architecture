Lab 1 -ACME Solutions Personnel Management System (PMS)
Due Date: March 3 @10pm

How to use the program:
    -To compile the program:
    	$ make

    -To test/run the program:
    	$ ./lab1

    -To clean the binaries:
    	$ make clean

Description: The program allows the user to interact with the program based on a simple gui interface. The user is promted to ask which action he/she wants to perfom in the system. Functions available to the user include:

 -Adding a new employee name to the text file
 -Deleting an existent employee from the text file
 -List the current employee names from the text file
 -Exit the user intereface and creates the bst after no further changes are needed to be made

On my approach to create tbe PMS, I reserved the add, remove and list operations for the text file only. Why? Because for me, it was simpler to do simple functions with the text file instead of doing using insert, freenode, deletenode and all other structs based operations. So just at the end, after the user has ended its modification process, the exit command creates a new bst struct and pass the values from the text file to the bst struct. And for further modifications, each time the user types exit, a new node is created, making it easier to implement. However, the functionality of the struct, inserting, creating and displaying the names is functional, meaning that in fact, there is a process of storing names not just a supposition.

Collaborations & References: During the process of developing the lab, I did help Eulalio Garcia in the sort of informations sharing and explanations of process. I came up with a different way to made the lab and did share the ideas with Eulalio, at the end where just ideas, because each one of us did its own code individually. I got the allocation of memory for the name string of each node rom the linked list demo, it was very helpful because my program wasn't working correctly because of that. Also, the structure and constants used in the linked list Makefile where reused to create the new makefile for the actual lab, so I want to give credit to the Arch1 team who did this, I thought it will be easier to reuse code since it was a pretty neat implementation of a makefile.
