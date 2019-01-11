#include<iostream>
template <typename T>
class node{
private:
  T v; // value
  node* left; //pointer to left node
  node* right; // pointer to right node
public:
  node(): v(0), left(NULL),right(NULL){

  }
  node(T nv):v(nv),left(NULL),right(NULL){

  }
  node(T nv, node* ln, node* rn):v(nv),left(ln),right(rn){

  }
  ~node(){
    left = NULL;
    right = NULL;
  }

};

template<typename T>
class BinaryST{
private:
  node<T>* root; //pointer to root

public:
  BinaryST<T> ():root(NULL){
    root = new node;
  }
}