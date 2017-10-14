#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include"read_file.h"
#include"add_name.h"
#include"delete_name.h"

typedef struct bst{
  char *name;
  struct bst *left;
  struct bst *right;
} bst;// The way to call the struct from now on

/* bst function declarations */
bst *create_node(char *name);
bst *insert_node(bst *root, char *name);
bst *init_tree();
void display_bst(bst *root);

int main(){
  
  FILE *testing;
  char emp_name[500];
  char user_input[500];
  bst *root;
  int loop =1;
  /* begining of the simple user interface */

  while(loop){
    printf("\n");
    printf("Welcome to ACME Solutions Personnel Maagement System\n");
    printf("Which action do you want to perform?\n");
    printf("List the name of all the Employees(List)\n");
    printf("Add a new Employee name to the System (Add)\n");
    printf("Delete a name from the system (Delete)\n");
    printf("Store the names in the BST and exit the user interface (Store) \n");
    printf("\n");
    scanf("%s",user_input);
    getchar(); //Prevents "enter" to be accepted as the value to be added/deleted function
    printf("\n");

    if(strcmp(user_input, "List")==0){
      printf("\n");
      read_file(testing);
    }
    
    else if(strcmp(user_input, "Add")==0){
      add_name(testing);
      printf("\n");
    }
    
    else if(strcmp(user_input, "Delete")==0){
      delete_name(testing);
      printf("\n");
    }
    
    else if(strcmp(user_input, "Store")==0){
      printf("Thank you for using the PMS interface! We hope to see you again soon!\n");
      printf("Names stored in the database, printing contents to proof\n");
      printf("\n");
      loop=0;
    }
  }
  
  // create the root
  root=init_tree();

  //Open the file
  testing =fopen("testing.txt", "r");
  
  while(fgets(emp_name, sizeof emp_name, testing)!=NULL){
    insert_node(root,emp_name);
  }
      
  display_bst(root);
  fclose(testing);
  
  return 0;
}
//Creates the first node of the tree, making it the default node
bst *init_tree(){
  bst *temp;
  temp = malloc(sizeof(bst));
  temp->name = "Manager"; //Every company has its Manager, so its the head of the bst
  temp->left = NULL;
  temp->right = NULL;
  return temp;
}

bst *create_node(char *new_name){
  bst *temp;
  int len;
  char *copy_string;
  
  /* Allocating memory for the string */
  for(len=0; new_name[len]; len++); //determines the size of the string
  copy_string = (char *)malloc(len+1);
  for(len=0; new_name[len]; len++)
  copy_string[len]=new_name[len];
  copy_string[len-1]=0; //substracting 1 to remove the new line chracter so it can prints normally

  /*Allocating memory for the node */
  temp = malloc(sizeof(bst)); //Allocates memory for each new node created
  temp->name = copy_string;
  temp->left=NULL;
  temp->right=NULL;
  return temp;
}

bst *insert_node(bst *root, char *name){
  //Base case of the recursion
  
  if(root ==NULL){
    return create_node(name);
  }
  //First case, when the designated name is greater that the root name
  if(strcmp(name,root->name) > 0){
    //if there space to create it, do it instantly, then return the node
    if(root->right == NULL){
      root->right = create_node(name);
      return root;
    }
    else{
      root->right = insert_node(root->right, name);
      //if there is a node on the right side, continue to iterate until the is an empty space
      return root;
    }
  }
  //Same functionality happens when going to the right
  else if(strcmp(name,root->name) < 0){
    if(root->left == NULL){
      root->left = create_node(name);
      return root;
    }
    else{
      root->left = insert_node(root->left, name);
      return root;
    }
  } 
}
//Method to print the names of the employees in order
void display_bst(bst *root){
  if(root==NULL)
    return;
  
  display_bst(root->left);
  printf("%s\n", root->name);
  display_bst(root->right);
}

int add_name(FILE *file_testing){

  char nombre[100];
  file_testing=fopen("testing.txt", "a");
  
  printf("Please enter new name: \n");

  /* If it is true that fgets() successfully retreives a new name to add
   instead of assigning the max number of characters to be read, sizeof states 
  that the max number of chars accepted will be equal to the size of the variable nombre,
  stdin is used to specifies that standard input from the keybord is used that identifies where 
  chracters are read form, in this case it is user input*/
  
  if(fgets(nombre, sizeof nombre, stdin)){
    fputs(nombre,file_testing);//stores new name in the text file
    fclose(file_testing);
    printf(" \n");
    printf("New name added succesfuly\n");
    printf(" \n");
  }

  else{
    printf("error \n");
  }

}

int read_file(FILE *file_testing){

  char length[500];
  file_testing=fopen("testing.txt", "r");

  /* In case there is no such file to read */
  if(file_testing == NULL){
    perror("There is no such file");
    return(1);
  }
  
  //Prints the current Employees
  printf("The current employees are: \n");
  //While there is still names to read from the file
  while(fgets(length, sizeof length ,file_testing)!=NULL){
    printf("%s", length);
  }

  /* Closing the file after reading it */
  fclose(file_testing);

    return 0;
}

int delete_name(FILE *file_testing){
  FILE *file_testing2; //for the deleting approach, in which the new names will be added
  char name;
  int del_line, tmp = 1;
  char renamed_file[] = "testing.txt";
  
  //First, the original file must be open
  file_testing = fopen("testing.txt", "r");
  printf("Which employe name do you want to delete? Please enter the possition of the name\n");
  scanf("%d", &del_line);
  
  //Open thew new file in write mode, so the remaining names will be still there
  file_testing2 = fopen("testing2.txt", "w"); //there is no such file, the file will be created
  
  while((name=getc(file_testing)) != EOF){
    //while there are still names to read
    if(tmp!=del_line){
      putc(name,file_testing2);
      //place the names into the new file
    }
    //this if was moved from before the while to after it, so that and end of file characted does not appear "/337"
    if(name == '\n')
      tmp++;
  }
  
  fclose(file_testing);
  fclose(file_testing2);
  remove("testing.tx");

  //renaming the duplicate/new list as the original
  rename("testing2.txt",renamed_file);

  return 0;
}
