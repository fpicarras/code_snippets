#ifndef _H_LINKEDLIST
#define _H_LINKEDLIST

/** @file linkedList.h
 *  @brief Icludes all the functions to create and manage a Simple Linked List Data Structure
 *  
 *      The lists created are linked to the next node and have a poointer to a void* (Item datatype),
 *      the lists have a pointer to the head and tail.
 *      This file incorporates the functions necessary to manage this data structure, listed bellow:
 * 
 *      # createList -------> Creates a Simple Linked List
 *      # deleteList -------> Deletes the list, freeing the allocated memory for the list aswell as for the Items
 *      # appendStart ------> Appends Item at the start of a list
 *      # appendEnd --------> Appends Item at the end of a list
 *      # popHead ----------> Return the content of the head of the list, deleting said node
 *      # getHead ----------> Returns a pointer to the Head Node
 *      # getTail ----------> Returns a pointer to the Tail Node
 *      # getNext ----------> Given a Node, returns the linked next one
 *      # getItem ----------> Returns the content in a Node
 * 
 *      The ability to append and remove Items at the start of the list allows this structure to be used as stack.
 *
 *  @author Filipe Piçarra (fpicarra)
 *  @bug No known bugs.
 */

#include <stdlib.h>

typedef void* Item;

typedef struct _linkedList List;

typedef struct _node Node;

/** @brief Creates a new List structure. 
 *
 *  The allocation of the structure is followed by it's initialization.
 *
 *  @return Pointer to a Simple Linked List Structure
 */
List *createList();

/** @brief Deletes a given list, freeing it's allocated memory. 
 *
 *  The content in each node is also freed!! This happens parsing a function that frres the Items stored in the list,
 *  if you don't want this to happen, simply parse a function that returns on entry.
 *
 *  @param l Pointer to list to be freed.
 *  @param freeItem Function that recieves an Item and frees the memory allocated by it, no matter the type, returns void.
 *  @return NONE
 */
void deleteList(List *l, void (*freeItem)(Item i));

/** @brief Appends an Item to the start of a list. This Item will be the new head.
 *
 *  @param l Pointer to list to be inserted an Item.
 *  @param i Item to be inserted.
 *  @return NONE
 */
void appendStart(List *l, Item i);

/** @brief Appends an Item to the end of a list. This Item will be the new tail.
 *
 *  @param l Pointer to list to be inserted an Item.
 *  @param i Item to be inserted.
 *  @return NONE
 */
void appendEnd(List *l, Item i);

/** @brief Removes the head Node, and returns it's content.
 * 
 *  The node following the head will be the new head.
 *
 *  @param l Pointer to list.
 *  @return Item in the head of the list, NULL if there is no head.
 */
Item popHead(List *l);

/** @brief Returns a pointer to the head node.
 *
 *  @param l Pointer to list.
 *  @return Pointer to the head of the list (*Node), NULL if there is no head.
 */
Node *getHead(List *l);

/** @brief Returns a pointer to the tail node.
 *
 *  @param l Pointer to list.
 *  @return Pointer to the tail of the list (*Node), NULL if there is no tail.
 */
Node *getTail(List *l);

/** @brief Given a node pointer, return a pointer to the next Node
 *
 *  @param n Pointer to Node.
 *  @return Pointer to the node following the one parsed, NULL if there is no next Node.
 */
Node *getNext(Node *n);

/** @brief Returns the content in a Node.
 *
 *  @param n Pointer to node.
 *  @return Content in the Node (Item)
 */
Item getItem(Node *n);

#endif