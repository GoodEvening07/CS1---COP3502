// Lab 4 - COP 3502 -  Section 4
// Author : Gabriel Hernandez 
//UCF ID: 5498123

#include <stdio.h>
#include <stdlib.h>

typedef struct node{
  char letter;
  struct node* next;
} node;

//"length" Description://
  /*Calculate the length of the linkedlist using
  iteration method and return the total n number of
  nodes in the linkedlist back.*/

int length(node* head)
{
  node* checker = head;
  int counter = 0;

  while(checker != NULL)
    {
      counter++;
      checker = checker->next;
    }

  return counter;
 
}

//"toCString" description://
  /*parses the string in the linkedList
  if the linked list is head -> |a|->|b|->|c|
  then toCString function wil return "abc" */
char* toCString(node* head)
{
  //We call the length function to determine the amoune of nodes inside of the linkedlist. 
  int lengthCaluclation = length(head); 

  char* cString = (char*)malloc(sizeof(char) * (lengthCaluclation + 1));

  node* current = head;

  //We use a For While Loop Conversion to iterated for each node that is in the linkedlist//
  int i = 0;
  while(current != NULL)
    {
      cString[i] = current->letter;
      current = current->next;
      i++;
    }
  
//We account for the char terminal space as well.
  cString[lengthCaluclation] = '\0'; 

  return cString;
}

//"insertChar Description:// 
  /* inserts character to the linkedlist
  if the linked list is head -> |a|->|b|->|c|
  then insertChar(&head, 'x') will update the linked list as foolows:
  head -> |a|->|b|->|c|->|x| */
  
void insertChar(node** pHead, char c)
{

  node* newNode = (node*)malloc(sizeof(node)); //We create the space for the node
  newNode->letter = c; //We give the new node the char data item.
  newNode->next = NULL;

  if(*pHead == NULL) //We check if the linkedlist if is empty 
  {
  *pHead = newNode;

  }

  else
  {
    node* walker = *pHead;
    
    while(walker->next != NULL) //We travers through the linkedlist until NULL.
    {
      walker = walker->next; //We make the connection to the next node
    }

    walker->next = newNode; //We make the connection from the new node to the node we want to insert.
  }

}

//"deleteList" Description:// 
  /* We traverse through the linkedlist to 
    find the node that we want to deleted and 
    aim to deletes all nodes in the linkedlist*/
void deleteList(node** pHead)
{
  node* perish = *pHead;
  while(perish != NULL)
    {
      *pHead = perish->next;
      free(perish);
      perish = *pHead;
    }
  *pHead = NULL;
}


int main(void) {
  
  int i, strLen, numInputs;
  node* head = NULL;
  char* str;
  char c;
  FILE* inFile = fopen("input.txt", "r");
  fscanf(inFile, " %d\n", &numInputs);

  while (numInputs-- > 0) {
     fscanf(inFile, " %d\n", &strLen);
     for (i = 0; i < strLen; i++) 
     {
          fscanf(inFile, " %c", &c);
          insertChar(&head, c);
     }
    
     str = toCString(head);
     printf("String is : %s\n", str);
     free(str);
    
     deleteList(&head);
     if (head != NULL) {
          printf("deleteList is not correct!");
          break;
     }
}
fclose(inFile);
}