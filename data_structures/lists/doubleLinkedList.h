#ifndef _H_DOUBLELINKEDLIST
#define _H_DOUBLELINKEDLIST

/** @file doubleLinkedList.h
 *  @brief Icludes all the functions to create and manage a Double Linked List Data Structure
 *  
 *      The lists created and linked to the next and previous node and have a poointer to a void* (Item datatype),
 *      the lists have a pointer to the head and tail.
 *      This file incorporates the functions necessary to manage this data structure, listed bellow:
 * 
 *      # createDoubleList ---> Creates a Double Linked List
 *      # deleteDoubleList ---> Deletes the list, freeing the allocated memory for the list aswell as for the Items
 *      # D_appendStart ------> Appends Item at the start of a list
 *      # D_appendEnd --------> Appends Item at the end of a list
 *      # popHead ------------> Return the content of the head of the list, deleting said node
 *      # popTail ------------> Return the content of the tail of the list, deleting said node
 *      # getHead ------------> Returns a pointer to the Head Node
 *      # getTail ------------> Returns a pointer to the Tail Node
 *      # getNext ------------> Given a Node, returns the linked next one
 *      # getPrev ------------> Given a Node, returns the linked previous one
 *      # getItem ------------> Returns the content in a Node
 *      # replaceItem --------> Given a Node and a new Item, replaces the content returning the old Item in the Node
 *      # deleteNode ---------> Given a Node, deletes it from the list, fixing the gap it leaves on the data structure
 * 
 *      The ability to append and remove Items at the start of the list allows this structure to be used as stack.
 *      With the addition of the popTail function, removing Items at the end allows the creation of queues.
 *
 *  @author Filipe Piçarra (fpicarra)
 *  @bug No known bugs.
 */

#include <stdlib.h>

typedef void* Item;

typedef struct _D_linkedList DList;

typedef struct _D_node DNode;

/** @brief Creates a new List structure. 
 *
 *  The allocation of the structure is followed by it's initialization.
 *
 *  @return Pointer to a Simple Linked List Structure
 */
DList *createDoubleList();

/** @brief Deletes a given list, freeing it's allocated memory. 
 *
 *  The content in each node is also freed!! This happens parsing a function that frres the Items stored in the list,
 *  if you don't want this to happen, simply parse a function that returns on entry.
 *
 *  @param l Pointer to list to be freed.
 *  @param freeItem Function that recieves an Item and frees the memory allocated by it, no matter the type, returns void.
 *  @return NONE
 */
void deleteDoubleList(DList *l, void (*freeItem)(Item i));

/** @brief Appends an Item to the start of a list. This Item will be the new head.
 *
 *  @param l Pointer to list to be inserted an Item.
 *  @param i Item to be inserted.
 *  @return NONE
 */
void D_appendStart(DList *l, Item i);

/** @brief Appends an Item to the end of a list. This Item will be the new tail.
 *
 *  @param l Pointer to list to be inserted an Item.
 *  @param i Item to be inserted.
 *  @return NONE
 */
void D_appendEnd(DList *l, Item i);

/** @brief Removes the head Node, and returns it's content.
 * 
 *  The node following the head will be the new head.
 *
 *  @param l Pointer to list.
 *  @return Item in the head of the list, NULL if there is no head.
 */
Item D_popHead(DList *l);

/** @brief Removes the tail Node, and returns it's content.
 * 
 *  The node previous to it will be the new tail.
 *
 *  @param l Pointer to list.
 *  @return Item in the head of the list, NULL if there is no tail.
 */
Item D_popTail(DList *l);

/** @brief Returns a pointer to the head node.
 *
 *  @param l Pointer to list.
 *  @return Pointer to the head of the list (*Node), NULL if there is no head.
 */
DNode *D_getHead(DList *l);

/** @brief Returns a pointer to the tail node.
 *
 *  @param l Pointer to list.
 *  @return Pointer to the tail of the list (*Node), NULL if there is no tail.
 */
DNode *D_getTail(DList *l);

/** @brief Given a node pointer, return a pointer to the next Node
 *
 *  @param n Pointer to Node.
 *  @return Pointer to the node following the one parsed, NULL if there is no next Node.
 */
DNode *D_getNext(DNode *n);

/** @brief Given a node pointer, return a pointer to the previous Node
 *
 *  @param n Pointer to Node.
 *  @return Pointer to the node previous the one parsed, NULL if there is no previous Node.
 */
DNode *D_getPrev(DNode *n);

/** @brief Returns the content in a Node.
 *
 *  @param n Pointer to node.
 *  @return Content in the Node (Item)
 */
Item D_getItem(DNode *n);

/** @brief Replaces the Item in a Node, returning the old content.
 * 
 *  When given a node and an Item it will place said Item in the Node, then the previous content is returned
 *  to the user.
 *
 *  @param n Pointer to node.
 *  @param i Item to be placed in the Node.
 *  @return OLD Content in the Node (Item)
 */
Item replaceItem(DNode *n, Item i);

/** @brief Given a Node deletes it in the list, fixing the gap it leaves behind and return the content.
 * 
 *  With the addition of the "prev" node pointer, there is now the ability to remove any Node in a list,
 *  when this happens the perv and next nodes are linked, fixing the gap left behind by the deletion.
 *  If the Node given is either the head or the tail of the list, this function is no different than the D_popHead
 *  and D_popTail. It's because of the occurrence of this cases that we have to parse the pointer to the list, 
 *  so that we can update the Head and Tail, if needed.
 * 
 *  Just like said functions, the content in the removed Item is returned.
 *  
 *  @param l List where the Node will be removed from
 *  @param n Pointer to node.
 *  @return Content in the Node (Item)
 */
Item deleteNode(DList *l, DNode *n);

#endif