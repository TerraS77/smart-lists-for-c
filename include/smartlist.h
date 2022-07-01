/**
 * @file SmartList.h
 * @brief Manage Lists
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#ifndef SMART_LIST
#define SMART_LIST

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


typedef void (*voidFunction)(void);
typedef int (*compareTwoPointersFunction)(void *data1, void *data2);
typedef void (*voidOnePointersFunction)(void *data);
typedef struct chainItem chainItem;
int COMPARE_PTR(void *data1, void *data2);

/**
 * @brief Item container of list 
 * 
 */
struct chainItem{
    /**Pointer to stored data*/
    void *data; 
    /**Previous item in list, NULL if none*/
    chainItem *previous;
    /**Next item in list, NULL if none */
    chainItem *next; 
};

/**
 * @brief List object
 * 
 */
typedef struct{
    /** Length of list*/
    int length;
    /** Size of list in memory*/
    int memLength;
    /** Map of index*/
    chainItem **indexMap;
    /** First item of the list*/
    chainItem *first;
    /** Last item of the list*/
    chainItem *last;
    /** Function to compare data on the list*/
    compareTwoPointersFunction comparator;
} list;

/**
 * @brief Allow to create a new list
 * 
 * @param comparatorFunction
 * @return list
 */
list *newList(compareTwoPointersFunction comparatorFunction);

/**
 * @brief Get the Data at index in list
 * 
 * @param list List to get data from
 * @param index Index of data to get
 * @return pointer to data
 */

void *getDataAtIndex(list list, int index);

/**
 * @brief Get the Item At Index object
 * 
 * @param list List to get item from
 * @param index Index of item to get
 * @return chainItem* 
 */

void deleteItemAtIndex(list *list, int index);

/**
 * @brief Delete the item in the List
 * 
 * @param list List to delete item from
 * @param data Data to delete
 */

void deleteInList(list *list, void *data);

/**
 * @brief Add the item at the end of the list
 * 
 * @param list List to add item to
 * @param data Data to add
 */

void pushInList(list *list, void *data);

/**
 * @brief Add the item at the beginning of the list
 * 
 * @param list List to add item to
 * @param data Data to add
 */

void appendInList(list *list, void *data);

/**
 * @brief Add the item at the emplacement of the index in the list
 * 
 * @param list List to add item to
 * @param data Data to add
 * @param index Index to add item at
 */

void appendAtInList(list *list, void *data, int index); 

/**
 * @brief Search the Index in the list
 * 
 * @param list List to search in
 * @param data Data to search
 * @return Index of data in list
 */

int searchIndexInList(list list, void *data);

/**
 * @brief Search the data in the List
 * 
 * @param list List to search in
 * @param data Data to search
 * @return pointer to data
 */
void *searchDataInList(list list, void *data);

/**
 * @brief Apply a specified function to all data of an array
 * 
 * @param list List of data
 * @param function Function to execute for each data
 */
void forEach(list *list, void (*function)(void *data));

/**
 * @brief Sort a list based on a specified function
 * 
 * @param list List of data to sort
 * @param function Function to compare two data, use list comparator if NULL
 * @param ascending If true, sort in ascending order, else sort in descending order
 */
void sortList(list *listToSort, compareTwoPointersFunction comparatorFunction, bool ascending);

/**
 * @brief Delete All Items in the list
 * 
 * @param list List to delete all items from
 */

void emptyList(list *list);

/**
 * @brief Delete All Items in the list and free it
 * 
 * @param list List to delete all items from
 */

void freeList(list *list);
#endif