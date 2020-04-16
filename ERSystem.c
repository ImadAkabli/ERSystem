// ER.c
// This is the Emergency Room management program.
// It uses a priority queue to manage patient input, (triage)
// so that all patients are noted and the most severe
// patients are treated quickly.

#include <stdio.h>
#include <stdlib.h>
#include "patient_queue.h"


// Global time counter, is incremented after each operation.
int time = 0;
int tree_size = 20;

// Create a new patient record, by reading values from the keyboard.
patient getPatient() {
  patient P;
	printf("Enter patient name:  ");
	scanf("%s", P.name);
	printf("Enter patient ID:    ");
	scanf("%d", &P.patientID);
	printf("Enter severity (1-4):");
	scanf("%d", &P.severity);
	P.arrivalTime = time;
	return P;
	}

// Main program, reads one patient, and then processes patients until
// the queue is empty.
int main() {
    patient patients[tree_size];
    patient cases;
	char action;
	int time = 0;
	
	cases = getPatient();
	// If heap is empty NewPQ
	// Else PQAppend
  append(patients, cases);
	while(PQEmpty(patients) == -1){
    patients[0].severity = 99;
		printf("Enter an action; 'a' for arrive, 'n' for next: ");
		// A for append
		// N for delete 
		scanf(" %c", &action);
		switch(action) {
			case 'a': 
				if(PQFull(patients) == -1) {
					printf("Too many patients!  Go somewhere else.\n");
					break;
					}
				cases = getPatient();
                append(patients, cases);
				break;
			case 'n': 
				if(PQEmpty(patients) == -1) {
					printf("No patients!  Take a break.\n");
					break;
					}
				build_max_heap(patients);
				cases = max_severity(patients);
				printf("patient %s (%d, severity %d) helped after waiting %d.\n", cases.name, cases.patientID, 
					cases.severity, cases.arrivalTime);
			}
		printf("Queue at time %d:\n", time++);
		print_heap(patients);
	}
}
