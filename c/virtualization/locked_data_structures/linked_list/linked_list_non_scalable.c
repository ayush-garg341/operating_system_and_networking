#include <stdio.h>
#include <stdlib.h>
#include "../common.h"
#include "../common_threads.h"

typedef struct __node_t {
    int key;
    struct __node_t *next;
} node_t;

typedef struct __list_t {
    node_t *head;
    pthread_mutex_t lock;
} list_t;

void list_init(list_t *l){
    l->head = NULL;
    pthread_mutex_init(&l->lock, NULL);
}

int list_insert(list_t *l, int key){
    node_t *new_node = malloc(sizeof(node_t));
    if (new_node == NULL){
        perror("malloc");
        return -1;
    }
    new_node->key = key;
    Pthread_mutex_lock(&l->lock);
    new_node->next = l->head;
    l->head = new_node;
    Pthread_mutex_unlock(&l->lock);
    return 0;
}

int list_lookup(list_t *l, int key)
{
    int rv = -1;
    Pthread_mutex_lock(&l->lock);
    node_t *current = l->head;
    while (current != NULL) {
        if (current->key == key){
            rv = 0;
            break;
        }
        current = current->next;
    }
    Pthread_mutex_unlock(&l->lock);
    return rv;
}

int main(int argc, char *argv[])
{
    list_t *l = malloc(sizeof(list_t));
    list_init(l);
    printf("%d\n", list_insert(l, 5));
    printf("%d\n", list_insert(l, 3));
    printf("%d\n", list_insert(l, 8));
    printf("%d\n", list_lookup(l, 3));
}
