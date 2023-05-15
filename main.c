#include <stdio.h>
#include <stdlib.h>
#include <locale.h>



struct Node {
    int data;
    struct Node* next;
};

struct Queue {
    struct Node* front;
    struct Node* rear;
};

void initializeQueue(struct Queue* queue) {
    queue->front = NULL;
    queue->rear = NULL;
}

void elemanEkle(struct Queue* queue, int deger) {
    struct Node* yeniNode = (struct Node*)malloc(sizeof(struct Node));
    yeniNode->data = deger;
    yeniNode->next = NULL;

    if (queue->front == NULL) {
        queue->front = yeniNode;
        queue->rear = yeniNode;
    } else {
        queue->rear->next = yeniNode;
        queue->rear = yeniNode;
    }

    printf("De�er ba�ar�yla eklendi.\n");
}

void elemanSil(struct Queue* queue) {
    if (queue->front == NULL) {
        printf("Kuyruk bo�!\n");
    } else {
        struct Node* silinecekNode = queue->front;
        queue->front = queue->front->next;
        free(silinecekNode);

        printf("Eleman ba�ar�yla silindi.\n");
    }
}

void kuyrugunGoruntule(struct Queue* queue) {
    if (queue->front == NULL) {
        printf("Kuyruk bo�!\n");
    } else {
        struct Node* current = queue->front;
        printf("Kuyruk: ");
        while (current != NULL) {
            printf("%d ", current->data);
            current = current->next;
        }
        printf("\n");
    }
}

int main() {
	setlocale(LC_ALL, "turkish");
    struct Queue queue;
    initializeQueue(&queue);

    int secim, deger;

    while (1) {
        printf("L�tfen a�a��daki i�lemlerden birini se�in:\n");
        printf("1) Ekleme\n2) Silme\n3) G�r�nt�leme\n4) ��k��\nSe�iminiz: ");
        scanf("%d", &secim);

        switch (secim) {
            case 1:
                printf("Eklemek istedi�iniz de�eri girin: ");
                scanf("%d", &deger);
                elemanEkle(&queue, deger);
                break;
            case 2:
                elemanSil(&queue);
                break;
            case 3:
                kuyrugunGoruntule(&queue);
                break;
            case 4:
                printf("Programdan ��k�l�yor.\n");
                return 0;
            default:
                printf("Ge�ersiz se�im!\n");
        }
    }

    return 0;
}

