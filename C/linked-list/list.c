#include<stdio.h>
#include<stdlib.h>

/**
 *              --- Linked List ---
 *      
 *   Linked list is a data struct where exist a set of nodes 
 *   interconnected. The last node always reference NULL.
 *       
 *   Methods: alloc: Make a memory allocation for all node. 
 *                  params: None || return: None
 * 
 *            add:  Add a new node. 
 *                  params: list, value || return None
 * 
 *            delete: Delete a node.
 *                  params: list, value || return: None
 * 
 *            show: show all nodes. 
 *                  params: list || return: None
 * 
 *            get: get a value on list 
 *                  params: list position || return: [x, -9999999](int)
 * 
 *            has:  verify if the number exists on list
 *                  params: list, value || return [1,0] (int)
 * 
 *            getSize: return the size of List
 *                  params: None || return (int)
**/


//
//Variables

struct Node{
    int value;
    struct Node *next;
};

typedef struct Node node;
int size = 0;

//
//Methods

void show(node *list){
    if(size != 0){
        node *temp = list;
        while(temp != NULL){
            printf("[ %i ] -> ", temp->value);
            temp = temp->next;
        }
        printf("NULL \n");
    }
}
 
node *alloc(){
    node *n =  (node *) malloc(sizeof(node));
    n->next = NULL;
    return n;
}

void add(node *list, int n){    
    node *temp = list;
    if(size != 0){
        while(temp->next != NULL){
            temp = temp->next;
        }
        node *new = alloc();
        temp->next = new;
        temp->next->value = n;
    }else{
        temp->value = n;
    }
    size++;
}

int get(node *list, int p){
    if(p >= 1 && p < size){
        node *temp = list;
        while(p > 1){
            temp = temp->next;
            p--;    
        }
        return temp->value;
    }
    return -99999999;
}

int getSize(){
    return size;
}

void delete(node *list, int p){
    if(p > 0 && size > 0){
        node *temp = list;
        while(p > 1){
            temp = temp->next;
            p--;
        }
        temp->value = temp->next->value;
        temp->next = temp->next->next;
        size--;
    }
}

int has(node *list, int n){
    if(size != 0){
        node *temp = list;
        while(temp != NULL){
            if(temp->value == n){
                return 1;
            }
            temp = temp->next;
        }
    }
    return 0;
}


//main
void main(){
node *list =  alloc();

add(list, 2);
add(list, 5);
add(list, 15);
add(list, 4);
add(list, 8);

show(list);

delete(list,1);

show(list);

printf("position: 1 ||  value: %d\n", get(list, 1));
printf("has 15? %d\n", has(list, 15));
printf("has -3? %d\n", has(list, -3));
printf("size: %d", getSize());

printf("\n\n");
system("pause");

}



