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

    printf("Deðer baþarýyla eklendi.\n");
}

void elemanSil(struct Queue* queue) {
    if (queue->front == NULL) {
        printf("Kuyruk boþ!\n");
    } else {
        struct Node* silinecekNode = queue->front;
        queue->front = queue->front->next;
        free(silinecekNode);

        printf("Eleman baþarýyla silindi.\n");
    }
}

void kuyrugunGoruntule(struct Queue* queue) {
    if (queue->front == NULL) {
        printf("Kuyruk boþ!\n");
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
        printf("Lütfen aþaðýdaki iþlemlerden birini seçin:\n");
        printf("1) Ekleme\n2) Silme\n3) Görüntüleme\n4) Çýkýþ\nSeçiminiz: ");
        scanf("%d", &secim);

        switch (secim) {
            case 1:
                printf("Eklemek istediðiniz deðeri girin: ");
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
                printf("Programdan çýkýlýyor.\n");
                return 0;
            default:
                printf("Geçersiz seçim!\n");
        }
    }

    return 0;
}

