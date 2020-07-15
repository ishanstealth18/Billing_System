/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: Ishan Kansara
 *
 * Created on July 5, 2020, 9:31 PM
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//Declaration and initialization of variables
struct Node *tempNode = NULL;
struct Node *newNode = NULL;
int cust_num;
char cust_name[50];
int acc_num;
char pay_date[10];

//Created a node for linked list
struct Node{
    int custNum;
    int accNum;
    char custName[50];
    char payDate[10];
    struct Node *nxt;
    struct Node *back;
}*root = NULL;

/**
 * @description This function displays all the records stored in from of linked list
 * @return void
 * @param start
 */
void displayList(struct Node *start)
{
    //Condition where root will be null, it means no customer is stored
    if(start == NULL)
    {
        printf("********No customers to be found!!******** \n");
        return;
    }
    
    printf("******Customer Details: ******\n");
    struct Node *startNode = NULL;
    //Storing root node in to temporary node to avoid using root node directly anywhere
    startNode = start;
    //Iterate through linked list and display records
    while(startNode != NULL)
    {
        printf("Customer Number: %d\n",startNode->custNum);
        printf("Customer Name: %s\n",startNode->custName);
        printf("Account Number: %d\n",startNode->accNum);
        printf("Pay Date: %s\n",startNode->payDate);
        startNode = startNode->nxt;
    }
}

/**
 * @descrption This function will create customer and will store it in form of linked list.
 * @param NA
 * @return void
 */
void createCustomer()
{
    //Asking user for all the details and scanning it 
    printf("\nEnter customer number: \n");
    scanf("%d",&cust_num);
    printf("Enter customer name: \n");
    
    scanf(" %[^\t\n]s",&cust_name);
    printf("Enter account number: \n");
    scanf("%d",&acc_num);
    printf("Enter pay date: \n");
    scanf("%s",&pay_date);
    //Condition if root is null, create root node and allocate all attributes
    if(root == NULL)
    {
        root = (struct Node*)malloc(sizeof(struct Node));
        root->custNum = cust_num;
        strcpy(root->custName,cust_name);
        root->accNum = acc_num;
        strcpy(root->payDate,pay_date);
        root->nxt = NULL;
        root->back = NULL;  
    }
    else
    {
        //Assigning root node to temporary node to avoid using root node directly
        tempNode = root;
        //First iterate through the linked list to check if any existing nodes 
        while(tempNode->nxt != NULL)
        {
            tempNode = tempNode->nxt;
        }
        //Create a new node and link it to the existing nodes at last
        newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->custNum = cust_num;
        strcpy(newNode->custName,cust_name);
        newNode->accNum = acc_num;
        strcpy(newNode->payDate,pay_date);
        tempNode->nxt = newNode;
        newNode->back = tempNode;
        newNode->nxt = NULL;    
    }
    printf("\n****Customer Created!!****\n");
}

/**
 * @description This function will help in searching a customer using customer number as a key.
 * @return void
 * @param searchNode
 */
void searchCustomer(struct Node *searchNode)
{
    //Asking user input for customer number as key
    int search_cust_num = 0;
    printf("\nEnter customer number to be searched: \n");
    scanf("%d",&search_cust_num);
    struct Node *tempSearchNode = NULL;
    tempSearchNode = searchNode;
    //Iterate through the whole linked list and search for the key, if present it will display all the details
    //related to that customer
    while(tempSearchNode != NULL)
    {
        if(tempSearchNode->custNum == search_cust_num)
        {
            printf("********Customer Details********\n");
            printf("Customer Number: %d\n",tempSearchNode->custNum);
            printf("Customer Name: %s\n",tempSearchNode->custName);
            printf("Account Number: %d\n",tempSearchNode->accNum);
            printf("Pay Date: %s\n",tempSearchNode->payDate);
            printf("*********************************\n");
            break;
        }
        tempSearchNode = tempSearchNode->nxt;
    }
}

/**
 * @dedscription This function helps in editing a customer's details.
 * @return void
 * @param editNode
 */
void editDetails(struct Node *editNode)
{
    //Asking user input for customer number as key
    int edit_cust_num = 0;
    printf("\nEnter customer number to be edited: \n");
    scanf("%d",&edit_cust_num);
    //Declaring and initializing all variables
    struct Node *tempEditNode = NULL;
    tempEditNode = editNode;
    int editOptions = 0;
    int newCustNum = 0;
    char newCustName [50];
    int newAccNum = 0;
    char newPayDate[50];
    //Iterate through the whole linked list to search key, if found, ask user to input new details 
    //and edit the record, save it in linked list
    while(tempEditNode != NULL)
    {
        //Condition if customer number is key
        if(tempEditNode->custNum == edit_cust_num)
        {
            printf("Enter option to edit details as follow: \n");
            printf("Enter 1 to edit customer number\n"
                   "Enter 2 to edit customer name\n"
                   "Enter 3 to edit account number\n"
                   "Enter 4 to edit pay date\n");
            printf("Enter option: ");
            scanf("%d",&editOptions);
            if(editOptions == 1)
            {
                printf("Enter new customer number: \n");
                scanf("%d",&newCustNum);
                tempEditNode->custNum = newCustNum;
                break;
            }
            else if(editOptions == 2)
            {
                printf("Enter new customer name: \n");
                scanf(" %[^\t\n]s",newCustName);
                strcpy(tempEditNode->custName,newCustName);
                break;
            }
            else if(editOptions == 3)
            {
                printf("Enter new account number: \n");
                scanf("%d",&newAccNum);
                tempEditNode->accNum = newAccNum;
                break;
            }
            else
            {
                printf("Enter new pay date: \n");
                scanf("%s",newPayDate);
                strcpy(tempEditNode->payDate,newPayDate);
                break;
            }
        }
        tempEditNode = tempEditNode->nxt;
    }
    printf("*********Customer details updated!!*********\n");
}

/**
 * @description This function will delete any customer record from linked list
 * @return void
 * @param deleteNode
 */
void deleteCustomer(struct Node *deleteNode)
{
    //Condition in case where there are no customers in the list i.e all customer records are deleted 
    if(deleteNode == NULL)
    {
        printf("********No customers to be found!!******** \n");
        return;
    }
    //Declaring and initialization
    struct Node *tempDeleteNode = NULL;
    //Storing root node in temporary node to be used indirectly
    tempDeleteNode = deleteNode;
    int deleteCust = 0;
    printf("Enter customer number to be deleted: \n");
    scanf("%d",&deleteCust);
    //Iterate through whole linked list, if customer key found to be deleted, remove it from the list
    while(tempDeleteNode != NULL)
    {
        //Condition if customer key matches
        if(tempDeleteNode->custNum == deleteCust)
        {
            //Condition if there is only one node in the list 
            if(tempDeleteNode->back == NULL && tempDeleteNode->nxt == NULL)
            {
                root = NULL;
                free(tempDeleteNode);
                break;
            }
            //Condition if node to be deleted is 1st node and is linked to other nodes
            else if(tempDeleteNode->back == NULL && tempDeleteNode->nxt != NULL)
            {
                tempDeleteNode->nxt->back = NULL;
                root = tempDeleteNode->nxt;
                tempDeleteNode->nxt = NULL;
                free(tempDeleteNode);
                break;
            }
            //Condition to remove node which is linked to both front and back nodes
            else if(tempDeleteNode->back != NULL && tempDeleteNode->nxt != NULL)
            {
                tempDeleteNode->back->nxt = tempDeleteNode->nxt;
                tempDeleteNode->back = NULL;
                tempDeleteNode->nxt = NULL;
                free(tempDeleteNode);
                break;
            }
            //Condition to remove last node from the list
            else if(tempDeleteNode->nxt == NULL && tempDeleteNode->back != NULL)
            {
                tempDeleteNode->back->nxt = NULL;
                tempDeleteNode->back = NULL;
                free(tempDeleteNode);
                break;
            }
        }
        tempDeleteNode = tempDeleteNode->nxt;
    }
}

/**
 * @description this function writes the updated records to a file on the system
 * @return void
 * @param writeNode
 */
void writeFile(struct Node *writeNode)
{
    //Declaration and initialization
    struct Node *tempWriteNode = NULL;
    tempWriteNode = writeNode;
    FILE *fptr;
    //Creating file pointer, 'r+' mode is to avoid overwriting the file
    fptr = fopen("E:/Bank_Details.txt","r+");
    //Condition if file do not open
    if(fptr == NULL)
    {
        printf("File opening error!!");
        exit(1);
    }
    int c = getc(fptr);
    //Logic to reach end of file to insert new records after existing ones
    while(c != EOF)
    {
        c = getc(fptr);
    }
    //Iterate through updated linked list and write file
    while(tempWriteNode != NULL)
    {
        fprintf(fptr,"%s %d\n","Customer Number: ", tempWriteNode->custNum);
        fprintf(fptr,"%s %s\n","Customer Name: ", tempWriteNode->custName);
        fprintf(fptr,"%s %d\n","Account Number: ", tempWriteNode->accNum);  
        fprintf(fptr,"%s %s\n","Pay Date: ", tempWriteNode->payDate);
        tempWriteNode = tempWriteNode->nxt;
    }
    fclose(fptr);
}
/*
 * 
 */
int main(int argc, char** argv) {
    
    printf("\t**********ABC Billing System**********");
    printf("\nChoose your option: \n");
   
    int mainOption = 0;
    while(1)
    {
        printf("\nEnter 1 to Create Customer\n"
               "Enter 2 to Search Customer\n"
               "Enter 3 to Display Details\n" 
               "Enter 4 to Edit Details\n"
               "Enter 5 to Delete Details\n" 
               "Enter 9 to exit\n");
         
        printf("Enter option: \n");
        
        scanf("%d",&mainOption);
        if(mainOption == 9)
        {
            writeFile(root);
            printf("Exiting......\n");
            break;
        }
        switch(mainOption)
        {
            case 1: 
               createCustomer();
               break;
            case 2:
                searchCustomer(root);
                break;
            case 3: 
               displayList(root);
               break;
            case 4:
                editDetails(root);
                break;
            case 5:
                deleteCustomer(root);
                break;
        }   
    }   
    return 0;
}

