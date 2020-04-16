// Define patient structure that will go within the array
typedef struct p {
	char name[30];
	int patientID;
	int severity;
	int arrivalTime;
} patient;

void swap(patient *a, patient *b);
int get_right_child(patient P[], int index);
int get_left_child(patient P[], int index);
int get_parent(patient P[], int index);
void max_heapify(patient P[], int index);
void build_max_heap(patient P[]);
patient max_severity(patient P[]);
void add_patient(patient P[], int index, patient key);
void append(patient P[], patient key);
void print_heap(patient P[]);

int PQEmpty(patient P[]);
int PQFull(patient P[]);
