// Implement the functions of the Priority Queue for ER patients.
// This is the file that you need to complete!
// It should implement the Priority Queue in a Heap.
// Remember, a Heap is a complete binary tree.
// To insert in a heap, add the next available leaf on the bottom level.
// Then percolate the value up until it is not greater than its parent.
// To remove from a heap, remove the root and replace it with the
// the last leaf. 
// Then percolate it down until it is not less than it's larger child.
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "patientqueue.h"

struct q {
	Patient *p;
	PatientQueue *left, *right;
};


PatientQueue *newPQ(int size) {
	return NULL;
}

// Insert in the heap:
// Add to the next leaf.
// FINISH THIS
PatientQueue *PQAppend(PatientQueue *q, Patient *p) {
	// Insert the new patient according to priority: the last patient with the same priority.
	PatientQueue *newq = (PatientQueue *) malloc(sizeof(PatientQueue));
	PatientQueue *walker;
	newq->p = p;
	newq->left = NULL;
	
	if(PQEmpty(q)) return newq;

	return q;
}

// New thing: call by reference: the function needs to be able
// to change the parameter q.
// Remove from a heap.
// Move the last leaf to the root,
// "Percolate down" 
// FINISH THIS
Patient *PQMaxServe(PatientQueue **q){
	if(PQEmpty(*q)) return NULL;
	else {

	}
}

// Print a binary tree
// FINISH THIS
void printPQ(PatientQueue * q) {

	printf("\n");
}

int PQEmpty(PatientQueue *q) {
	return q == NULL;
}

int PQFull(PatientQueue *q){
	return 0;
}
