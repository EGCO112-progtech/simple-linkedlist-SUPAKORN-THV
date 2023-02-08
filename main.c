//
//  main.c
//  simple linkedlist
//
//  Created by Mingmanas Sivaraksa on 4/2/2566 BE.
//

#include <stdio.h>
#include <stdlib.h>
#include "node.h"

int main(int argc, const char * argv[]) {
    int c=5;
    //struct node a,b,*head ;
    typedef struct node Node;
    typedef Node* NodePtr;
    NodePtr head;
    //struct node *p = (struct node*) malloc(sizeof(struct node));
    //Node *p = (NodePtr) malloc(sizeof(Node));
    NodePtr p = (NodePtr) malloc(sizeof(Node));
    p->value = c;      //a.value = c;
    p->next = (NodePtr) malloc(sizeof(Node));      //a.next=&b;
    head=p; // head=&a;
    p->next->value = head->value+3;
    printf("\n==DEMO==\n");
    printf("%d\n", head->value ); //what value for 5
    printf("%d\n", head->next->value ); //what value for 8
  
/*  Exercise I
    1. Add 1 more than at the end
    2. Add value(11)
    3. Make next become NULL
 */
    head->next->next = (NodePtr) malloc(sizeof(Node));//struct node ex1;
    head->next->next->value = 11;
    head->next->next->next = NULL;
  //printf("%d\n",d.value);
  //printf("%d\n",b.next->value);
  //printf("%d\n",a.next->next->value);
    printf("\n==Ex1==\n");
    printf("%d\n", head->next->next->value);
  
/*  Exercise II
        1. Add 1 more than at the begining!!!!
        2. Add value (2)
*/
    NodePtr ex2 = (NodePtr) malloc(sizeof(Node));//struct node ex2;
    head = ex2;//head = &ex2;
    ex2->value = 2;//ex2.value= 2;
    ex2->next = p; //ex2.next = &a;
    printf("\n==Ex2==\n");
    printf("%d -> ", head->value); //ex2
    printf("%d -> ", head->next->value); //a
    printf("%d -> ", head->next->next->value); //b
    printf("%d -> \n", head->next->next->next->value); //ex1

    typedef struct node* NodePtr;
    NodePtr tmp=head; //add temp value to faciliate
    /*  Exercise III Use loop to print everything
        int i,n=5;
        for(i=0;i<n;i++){
            printf("%3d", tmp->value);
          // What is missing???
        }
    */
      printf("\n==Ex3==\n");
      int i,n=4;
        for(i=0;i<n;i++){
            printf("%3d -> ", tmp->value);
            tmp = tmp->next; //--Next Box--
        }
      printf("%3p\n", tmp);
      
    
   /*  Exercise IV change to while loop!! (you can use NULL to help)
       
         while(){
            printf("%3d", tmp->value);
           // What is missing???
        }
    */    
      printf("\n==Ex4==\n");
      tmp=head;
      while(tmp!=NULL){
      printf("%3d -> ", tmp->value);
      tmp = tmp->next; //--Next Box--
      }
      printf("%3p\n", tmp);
 /*  Exercise V Use malloc to create all nodes, instead of create a struct!!
         //use a loop to help
          
     */
     printf("\n==Ex5==\n");
     tmp=head;
     n=4;
     for(i=0;i<n;i++){
     tmp->next = (NodePtr) malloc(sizeof(Node));
     tmp=tmp->next;
     tmp->value=c+i+1;
     tmp->next=NULL;
    }
  
      tmp=head;
      while(tmp!=NULL){
      printf("%3d -> ", tmp->value);
      tmp = tmp->next; //--Next Box--
      }
      printf("%3p\n", tmp);
    /*  Exercise VI Free all node !!
         //use a loop to help
          
     */
    NodePtr tmp2=head; //add temp value to faciliate
    tmp=head;
    while(tmp!=NULL){
      printf("deleting %d\n", tmp->value);
      //Do not use the right-sided tmp
      tmp2 = tmp -> next;
      free(tmp);
      tmp = tmp2;
    }
      printf("\n");
    return 0;
}
