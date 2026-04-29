#include <stdio.h>
#include <string.h>

#define SIZE 10

typedef struct {
    char buffer[SIZE];
    int head;
    int tail;
    int count;
} CircularBuffer;

void init(CircularBuffer *cb) {
    cb->head = 0;
    cb->tail = 0;
    cb->count = 0;
}

int isFull(CircularBuffer *cb) {
    return cb->count == SIZE;
}

int isEmpty(CircularBuffer *cb) {
    return cb->count == 0;
}

void write(CircularBuffer *cb, char data) {
    if (isFull(cb)) {
        return;
    }
    cb->buffer[cb->head] = data;
    cb->head = (cb->head + 1) % SIZE;
    cb->count++;
}

char read(CircularBuffer *cb) {
    if (isEmpty(cb)) {
        return '\0';
    }
    char data = cb->buffer[cb->tail];
    cb->tail = (cb->tail + 1) % SIZE;
    cb->count--;
    return data;
}

int main() {
    CircularBuffer cb;
    init(&cb);

    char name[100];
    char suffix[] = "CE-ESY";
    int overflow_printed = 0;

    printf("Enter name: ");
    scanf("%s", name);

    strcat(name, suffix);

    for (int i = 0; i < strlen(name); i++) {
        if (isFull(&cb)) {
            if (!overflow_printed) {
                printf("\nBuffer Overflow\n");
                overflow_printed = 1;
            }
        }
        write(&cb, name[i]);
    }

    printf("Buffer Content: ");
    while (!isEmpty(&cb)) {
        printf("%c", read(&cb));
    }
    printf("\n");

    return 0;
}
