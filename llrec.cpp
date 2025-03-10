#include "llrec.h"

//*********************************************
// Provide your implementation of llpivot below
//*********************************************

void llpivot(Node *&head, Node *&smaller, Node *&larger, int pivot){

  if(head == NULL){
    smaller = NULL;
    larger = NULL;
    return;
  }

  Node* nextAddress = head->next;

  if(head->val > pivot){
    larger = head;
    llpivot(nextAddress, smaller, larger->next, pivot);
  }
  else{
    smaller = head;
    llpivot(nextAddress, smaller->next, larger, pivot);
  }

  head = NULL;

  return;



}



