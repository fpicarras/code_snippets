#ifndef _H_CONNECTIVITY
#define _H_CONNECTIVITY

/** @file connectivity.h
 *  @brief Icludes all the functions to the Connectivity Data Structures
 *  
 *      This incorporates the create, delete (free mem), check connections
 *      and add connection functions.
 * 
 *      The type of algorithm used is based on the Compressed Weighted Uninion
 *      and works only for integers.
 *
 *  @author Filipe Piçarra (fpicarra)
 *  @bug No known bugs.
 */

#include <stdlib.h>

typedef struct _connections Connections;

/** @brief Creates a new Connections structure. 
 *
 *  The allocation of the structure is followed by it's initialization.
 *  A number of integers corresponding to the total amount of nodes is given and
 *  a pointer to said structure is returned, if anything goes wrong or there is an invalid
 *  input, a NULL pointer is returned.
 *
 *  @param sz Number of Connections to create, size of the connection array.
 *  @return Pointer to a Connections Structure
 */
Connections *newConn(int sz);

/** @brief Checks if two nodes are connected. 
 *
 *  By tracing each node back to it's root, we are able to determine if said notes
 *  are connected if they share the same root. A True value is return if this condition
 *  is verified, else or if anything goes wrong, a False one.
 *
 *  @param conn Pointer to a Connections structure
 *  @param num1 Integer with node number 1
 *  @param num2 Integer with node number 2
 *  @return TRUE if nodes are Connected, else FALSE
 */
int isConnected(Connections *conn, int num1, int num2);

/** @brief Adds a connection between two nodes. 
 * 
 *  If the two nodes aren't already connected, we use the CWU algorithm to add them together.
 *
 *  @param conn Pointer to a Connections structure
 *  @param num1 Integer with node number 1
 *  @param num2 Integer with node number 2
 */
void addConn(Connections *conn, int num1, int num2);

/** @brief Deletes a Connections structure
 * 
 *  Frees the allocated memory used for the structure.
 *
 *  @param conn Pointer to a Connections structure
 *  @return Pointer to a Connections Structure
 */
void delConn(Connections *conn);

#endif