#include <stdio.h>
#include "patient_queue.h"

extern int tree_size;
int heap_size = 0;
const int INF = 100000;

void swap(patient *a, patient *b) {
  patient t;
  t = *a;
  *a = *b;
  *b = t;
}

//function to get right child of a node of a tree
int get_right_child(patient P[], int index) {
  if((((2*index)+1) < tree_size) && (index >= 1))
    return (2*index)+1;
  return -1;
}

//function to get left child of a node of a tree
int get_left_child(patient P[], int index) {
    if(((2*index) < tree_size) && (index >= 1))
        return 2*index;
    return -1;
}

//function to get the parent of a node of a tree
int get_parent(patient P[], int index) {
  if ((index > 1) && (index < tree_size)) {
    return index/2;
  }
  return -1;
}

void max_heapify(patient P[], int index) {
  int left_child_index = get_left_child(P, index);
  int right_child_index = get_right_child(P, index);

  // finding largest among index, left child and right child
  int largest = index;

  if ((left_child_index <= heap_size) && (left_child_index>0)) {
    if (P[left_child_index].severity > P[largest].severity) {
      largest = left_child_index;
    }
  }

  if ((right_child_index <= heap_size && (right_child_index>0))) {
    if (P[right_child_index].severity > P[largest].severity) {
      largest = right_child_index;
    }
  }

  // largest is not the node, node is not a heap
  if (largest != index) {
    swap(&P[index], &P[largest]);
    max_heapify(P, largest);
  }
}

void build_max_heap(patient P[]) {
  int i;
  for(i=heap_size/2; i>=1; i--) {
    max_heapify(P, i);
  }
}

patient max_severity(patient P[]) {
  patient max = P[1];
  P[1] = P[heap_size];
  heap_size--;
  max_heapify(P, 1);
  return max;
}

void add_patient(patient P[], int index, patient pt) {
  P[index] = pt;
  while((index>1) && (P[get_parent(P, index)].severity < P[index].severity)) {
    swap(&P[index], &P[get_parent(P, index)]);
    index = get_parent(P, index);
  }
}

void append(patient P[], patient pt) {
  heap_size++;
  P[0].severity = -1;
  P[heap_size].severity = -1*INF;
  add_patient(P, heap_size, pt);
}

void print_heap(patient P[]) {
  int i;
  for(i=1; i<=heap_size; i++) {
    printf("Name: %s, PatientID: %d, Severity: %d\n",P[i].name, P[i].patientID, P[i].severity);
  }
  printf("\n");
}

int PQEmpty(patient P[]) {
    if(P[0].severity == -1) return -1;
    return 99;
}

int PQFull(patient P[]) {
    if(heap_size == tree_size) return -1;
    return 99;
}