/*
leetcode exercise LinkedList implementation
*/

#include<iostream>

class MyLinkedList {
  struct node
  {
    int val_;
    node* next;
    node(int x): val_(x),next(NULL){}
    /* data */
  };
  node* head;
  int num_node;
public:
    /** Initialize your data structure here. */
    MyLinkedList() {
        //head = new node(0);
        num_node = 0;
    }
    
    /** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
    int get(int index) {
        if(index >=num_node)
        {
          return -1;
        }
        else
        {
          std::cout<<"get value of index "<<index;
          node* tmp = head;
          for(int i = 0;i<index;i++){
            tmp = tmp->next;
          }
          std::cout<<(*tmp).val_<<endl;
          return (*tmp).val_;
        }
      
    }
    /** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
    void addAtHead(int val) {
      std::cout<<"add at head with value: "<<val<<endl;
        if(num_node==0){ //create head if there is no head
          head = new node(val);
        }else{ //then we need 
          node *new_node = new node(val);
          new_node->next = head;
          head = new_node;
        }
        num_node++;
        //showlist();
    }
    /** Append a node of value val to the last element of the linked list. */
    void addAtTail(int val) {
      std::cout<<"add at tail with value: "<<val<<endl;
        node * tmp = head;
        node * new_node = new node(val);
        while(tmp->next != NULL){
          tmp = tmp->next;
        }
        tmp->next = new_node;
        num_node++;
        //showlist();
    }
    
    /** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
    void addAtIndex(int index, int val) {
      std::cout<<"add at index "<<index << " with value "<< val<<endl;
        if(index > num_node){
         std::cout<<"invalid index"<<endl;
        }
        else if(index == 0){ //need to check if it is head first , then check tail
          addAtHead(val);
        }
        else if (index==num_node)
        {
          addAtTail(val);
        }

        else
        {
          node * tmp = head;
          node * new_node = new node(val);
          for(int i=0;i<index-1;i++){
            tmp = tmp->next;
          }
          new_node->next = tmp->next;
          tmp->next = new_node;
          num_node++;
        }
        //showlist();
    }
    
    /** Delete the index-th node in the linked list, if the index is valid. */
    void deleteAtIndex(int index) {
      std::cout<<"delete node with index: "<<index <<endl;
      if( (index<0) ||(index>=num_node)){
        std::cout<<"invalid input of delete function"<<endl;
      }
      else{
        node * tmp = head;
        for(int i=0;i<index-1;i++){
          tmp = tmp->next;
        }
        node * tmp1 = tmp->next;
        tmp->next = tmp1->next;
        delete(tmp1);
        num_node--;
      }
      //showlist();
    }
private:
  void showlist(){
      if(num_node==0){
        std::cout<<"empty list"<<endl;
      }
      else{
        std::cout<<"show list:";
        node * tmp = head;
        for(int i=0;i<num_node;i++){
          std::cout<< (*tmp).val_;
          tmp = tmp->next;
        }
        std::cout<<endl;
      }
    }
};
/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList obj = new MyLinkedList();
 * int param_1 = obj.get(index);
 * obj.addAtHead(val);
 * obj.addAtTail(val);
 * obj.addAtIndex(index,val);
 * obj.deleteAtIndex(index);
 */