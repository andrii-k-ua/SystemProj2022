#include <stdio.h>
#include <stdlib.h>

typedef struct RingBuffers {
    int size;
    int RD_index;
    int WR_index;
    char *array;
} RingBuffer;

RingBuffer *createRingBuffer(int size);
void readRB(RingBuffer *rb, char *c);
void writeRB(RingBuffer *rb, char c);

int main() {
    RingBuffer *ringBuffer = NULL;

    while(1) {
        printf("1 - Create ring buffer\n");
        if(ringBuffer != NULL) {
            printf("2 - Read from buffer\n");
            printf("3 - Write to buffer\n");
        }
        printf(">> ");
        int m = 0;
        scanf("%d", &m);
        switch(m) {
            case 1: 
                if(ringBuffer != NULL) {
                    free(ringBuffer->array);
                    free(ringBuffer);
                }
                printf("Enter size: ");
                int size = 0;
                scanf("%d", &size);
                ringBuffer = createRingBuffer(size);
                printf("Done!\n\n");
                break;
            case 2: 
                if(ringBuffer == NULL) 
                    break;
                char c;
                readRB(ringBuffer, &c);
                printf("\nOutput: %c\n\n", c);
                break;
            case 3: 
                if(ringBuffer == NULL) 
                        break;
                printf("Enter char: ");
                char tmp;
                scanf(" %c", &tmp);
                writeRB(ringBuffer, tmp);
                printf("Done!\n");
                break;
        } 
    }

    return 0;     
}

RingBuffer *createRingBuffer(int size) {
    RingBuffer *tmp = malloc(sizeof(RingBuffer));

    if(tmp == NULL) return NULL;

    tmp->size = size;
    tmp->RD_index = 0;
    tmp->WR_index = 0;
    tmp->array = malloc(size*sizeof(char));

    if(tmp->array == NULL) return NULL; 

    return tmp;
}

void readRB(RingBuffer *rb, char *c) {
    *c = rb->array[rb->RD_index];

    if(rb->RD_index == rb->size - 1) {
        rb->RD_index = 0;
    } else {
        rb->RD_index++;
    }
}

void writeRB(RingBuffer *rb, char c) {
    rb->array[rb->WR_index] = c;

    if(rb->WR_index == rb->size - 1) {
        rb->WR_index = 0;
    } else {
        rb->WR_index++;
    }
}
