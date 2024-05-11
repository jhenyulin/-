#include <stdio.h>
#include <stdlib.h>
#define NAME_LENGTH 50

typedef struct node {
    int course_id;
    char name[NAME_LENGTH];
    struct course* next;
    struct course* prior;
} Node;

void add_node(Node** start, char value[NAME_LENGTH], int num_courses);
void print_current_course(Node* start);
void free_list(Node* node);

void add_node(Node** start, char value[NAME_LENGTH], int num_courses) {
    int course_id, next_id, prior_id;
    for (int i = 0; i < num_courses; i++) {
        Node* new_node = (Node*)malloc(sizeof(Node));

        strcpy(new_node->name, "init");
        new_node->next = NULL;
        new_node->prior = NULL;

        if (*start == NULL) {
            *start = new_node;
        } else {
            Node* current = *start;
            while (current->next != NULL) {
                current = current->next;
            }
            current->next = new_node;
            new_node->prior = current;
        }
    }
    for (int i = 0; i < num_courses; i++) {
        int course_id, next_id, prior_id;
        char value[NAME_LENGTH];
        printf("Enter:id, next, prior, name: ");
        scanf("%d %d %d %s", &course_id, &next_id, &prior_id, value);

        Node* current = *start;
        while (current != NULL) {
            if (current->course_id == course_id) {
                strcpy(current->name, value);
                break;
            }
            current = current->next;
        }
    }
    return;
}

void print_current_course(Node* start) {
    Node* current = start;
    printf("%s\n", current->name);
}

void free_list(Node* node) {
    Node *current, *temp;
    current = node;
    while (current != NULL) {
        temp = current;
        current = current->next;
        free(temp);
    }
}

int main() {
    int num_courses;
    char course_name[NAME_LENGTH];
    scanf("%d", &num_courses);

    Node* head = NULL;

    add_node(&head, course_name, num_courses);
}