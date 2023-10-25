#include <string.h>
#include <stdio.h>
#include "linkedList.h"

//Compiling: gcc -o lists_example lists_example.c linkedList.c

/**
 * Item is a typedef for a void* (8B).
 * To convert other values to an Item you simply cast it: (Item)var.
 * To return to it's original type, you just cast it back! This allows this data structures not to
 * be limited to a single datatype, instead you can use the same .h file for lists to store multiple different values.
 */

/**
 * This function is used to be parsed when deleting a list,
 * Since we are using the list as a strings list, what this will do is simply free said string pointer
 * when an Item is parsed to it.
 */
void freeItem(Item i){
    free((char*)i);
}

int main(){
    //Initialization of the strings (to be used as example)
    char *str1 = (char*)malloc(50*sizeof(char));
    strcpy(str1, "Back in Time");
    char *str2 = (char*)malloc(50*sizeof(char));
    strcpy(str2, "Somewhere");

    //Creation of a list named Test
    List *test = createList();

    /**
     * Append the two strings at the end and start of the list, making it "look" like this:
     *                                             (head) Somewhere <-> Back in Time (tail)
     */
    appendEnd(test, (Item)str1);
    appendStart(test, (Item)str2);

    /**
     * Using the popHead we get the content in the head node and delete said node
     * This Item was a string, so we have to free the allocated memory.
     */
    free(popHead(test));

    /** 
     * Now let's print the last string on the list.
     * Again we use the getHead function to get the pointer to the head node, using that pointer we get it's content
     * with the D_getItem, now all we have to do is cast the returned value back to a string (char*)
     */
    printf("%s\n", (char*)getItem(getHead(test)));

    //Deleting the list and freeing the allocated memory
    deleteList(test, freeItem);
    return 0;
}