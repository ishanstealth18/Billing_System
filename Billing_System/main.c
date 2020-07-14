/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: ishan
 *
 * Created on July 5, 2020, 9:31 PM
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct Node *tempNode = NULL;
struct Node *newNode = NULL;
int cust_num;
char cust_name[50];
int acc_num;
char pay_date[10];

struct Node{
    int custNum;
    int accNum;
    char custName[50];
    char payDate[10];
    struct Node *nxt;
}*root = NULL;

void displayList(struct Node *start)
{
    printf("******Customer Details: ******\n");
    struct Node *startNode = NULL;
    startNode = start;
    while(startNode != NULL)
    {
        printf("Customer Number: %d\n",startNode->custNum);
        printf("Customer Name: %s\n",startNode->custName);
        printf("Account Number: %d\n",startNode->accNum);
        printf("Pay Date: %s\n",startNode->payDate);
        startNode = startNode->nxt;
    }
}

void createCustomer()
{
    printf("\nEnter customer number: \n");
    scanf("%d",&cust_num);
    printf("Enter customer name: \n");
    scanf("%s",cust_name);
    printf("Enter account number: \n");
    scanf("%d",&acc_num);
    printf("Enter pay date: \n");
    scanf("%s",&pay_date);
    
    
    FILE *fptr;
    fptr = fopen("E:/Bank_Details.txt","r+");
    if(fptr == NULL)
    {
        printf("File opening error!!");
        exit(1);
    }
    int c = getc(fptr);
    
    if(root == NULL)
    {
        root = (struct Node*)malloc(sizeof(struct Node));
        root->custNum = cust_num;
        strcpy(root->custName,cust_name);
        root->accNum = acc_num;
        strcpy(root->payDate,pay_date);
        
        
        printf("Customer Num: %d\n",root->custNum);
        printf("Customer Name: %s\n",root->custName);
        printf("Account Num: %d\n",root->accNum);
        printf("Pay Date: %s\n",root->payDate);
        root->nxt = NULL;
        while(c != EOF)
        {
            c = getc(fptr);
        }
        
        fprintf(fptr,"%s %d\n","Customer Number: ", root->custNum);
        fprintf(fptr,"%s %s\n","Customer Name: ", root->custName);
        fprintf(fptr,"%s %d\n","Account Number: ", root->accNum);  
        fprintf(fptr,"%s %s\n","Pay Date: ", root->payDate);  
    }
    else
    {
        tempNode = root;
        while(tempNode->nxt != NULL)
        {
            tempNode = tempNode->nxt;
        }
        newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->custNum = cust_num;
        strcpy(newNode->custName,cust_name);
        newNode->accNum = acc_num;
        strcpy(newNode->payDate,pay_date);
        printf("Customer Num: %d\n",newNode->custNum);
        printf("Customer Name: %s\n",newNode->custName);
        printf("Account Num: %d\n",newNode->accNum);
        printf("Pay Date: %s\n",newNode->payDate);
        
        tempNode->nxt = newNode;
        newNode->nxt = NULL;
        
        while(c != EOF)
        {
            c = getc(fptr);
        }
        fprintf(fptr,"\n%s %d\n","Customer Number: ", newNode->custNum);
        fprintf(fptr,"%s %s\n","Customer Name: ", newNode->custName);
        fprintf(fptr,"%s %d\n","Account Number: ", newNode->accNum);
        fprintf(fptr,"%s %s\n","Pay Date ", newNode->payDate);
     }
    printf("\n****Customer Created!!****\n");
    fclose(fptr);
}

void searchCustomer(struct Node *searchNode)
{
    int search_cust_num = 0;
    printf("\nEnter customer number to be searched: \n");
    scanf("%d",&search_cust_num);
    struct Node *tempSearchNode = NULL;
    tempSearchNode = searchNode;
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

/*
 * 
 */
int main(int argc, char** argv) {
    
    printf("\t**********ABC Bank**********");
    printf("\nChoose your option: \n");
   
    int mainOption = 0;
    
    while(1)
    {
        printf("\nEnter 1 to Create Customer\n"
               "Enter 2 to Search Customer\n"
               "Enter 3 to Display Details\n" 
               "Enter 9 to exit\n");
         
        printf("Enter option: \n");
        
        scanf("%d",&mainOption);
        if(mainOption == 9)
        {
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
        }   
    }   
    return 0;
}

