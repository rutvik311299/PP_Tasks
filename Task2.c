#include <stdio.h>

#define BUFFER_SIZE 5  

// Define the circular buffer structure
typedef struct {
    int buffer[BUFFER_SIZE];  // Array to hold the data
    int head;                 // Index to the next place to push data
    int tail;                 // Index to the next place to pop data
    int size;                 // Number of elements in the buffer
} CircularBuffer;

// Function to initialize the buffer
void initBuffer(CircularBuffer* cb) {
    cb->head = 0;
    cb->tail = 0;
    cb->size = 0;
}

// Function to push data to the buffer
void push(CircularBuffer* cb, int data) {
    if (cb->size < BUFFER_SIZE) {
        cb->buffer[cb->head] = data;
        cb->head = (cb->head + 1) % BUFFER_SIZE;
        cb->size++;
    } else {
        printf("Buffer is full. Overwriting the oldest data.\n");
        cb->buffer[cb->head] = data;
        cb->head = (cb->head + 1) % BUFFER_SIZE;
        cb->tail = (cb->tail + 1) % BUFFER_SIZE;
    }
}

// Function to pop data from the buffer
int pop(CircularBuffer* cb) {
    if (cb->size == 0) {
        printf("Buffer is empty. Cannot pop data.\n");
        return -1;  // Return an error value
    } else {
        int data = cb->buffer[cb->tail];
        cb->tail = (cb->tail + 1) % BUFFER_SIZE;
        cb->size--;
        return data;
    }
}

// Function to print the current contents of the buffer
void printBuffer(CircularBuffer* cb) {
    if (cb->size == 0) {
        printf("Buffer is empty.\n");
        return;
    }

    printf("Buffer contents: [");
    int i = cb->tail;
    for (int j = 0; j < cb->size; j++) {
        printf("%d", cb->buffer[i]);
        if (j < cb->size - 1) {
            printf(", ");
        }
        i = (i + 1) % BUFFER_SIZE;
    }
    printf("]\n");
}

int main() {
    CircularBuffer cb;
    initBuffer(&cb);  // Init the buffer

    printf("Pushing data to the buffer...\n");

    for(int i=1;i<=5;i++)
    {
        push(&cb,i);
    }

    printBuffer(&cb); 

    printf("\nPopping 1 items from the buffer...\n");
    pop(&cb);

    printBuffer(&cb);  // Print buffer contents after pop operations

    return 0;
}
