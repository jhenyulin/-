#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NAME_LENGTH 50

typedef struct course {
    int id;
    char name[NAME_LENGTH];
    struct course* next;
    struct course* prior;
} Course;

void add_course(Course** start,
                int id,
                char name[NAME_LENGTH],
                int next_id,
                int prior_id) {
    Course* new_course = (Course*)malloc(sizeof(Course));
    if (new_course == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    new_course->id = id;
    strcpy(new_course->name, name);
    new_course->next = NULL;
    new_course->prior = NULL;

    if (*start == NULL) {
        *start = new_course;
        return;
    }

    Course* current = *start;
    while (current != NULL) {
        if (current->id == next_id) {
            new_course->next = current;
            //current->prior = new_course;//有問題
        }
        current = current->next;
} while (current != NULL) {
        if (current->id == prior_id) {
            new_course->prior = current;
        }
        current = current->prior;
}
    
}

void print_course_list(Course* start) {
    Course* current = start;
    while (current != NULL) {
        printf("%d %s\n", current->id, current->name);
        current = current->next;
    }
}

void free_course_list(Course** start) {
    if (*start == NULL) {
        return;  
    }

    Course* current = *start;
    while (current != NULL) {
        Course* temp = current;
        current = current->next;
        free(temp);
    }

    *start = NULL;  
}

int main() {
    int num_courses;
    scanf("%d", &num_courses);

    Course* head = NULL;

    for (int i = 0; i < num_courses; i++) {
        int id, next_id, prior_id;
        char name[NAME_LENGTH];
        scanf("%d %d %d %s", &id, &next_id, &prior_id, name);

        add_course(&head, id, name, next_id, prior_id);
    }

    printf("Current Course: %s\n", head->name);
   


    char choice;
    Course* current = head;  // Initialize current pointer
    do {
        printf("[n] Next course. [p] Prior course [q] Quit:");
        scanf(" %c", &choice);

        switch (choice) {
            case 'n':
                if (current != NULL && current->next != NULL) {
                    current = current->next;
                } else {
                    printf("There is no next course.\n");
                }
                printf("Current Course: %s\n", current->name);
                break;
            case 'p':
                if (current != NULL && current->prior != NULL) {
                    current = current->prior;
                } else {
                    printf("There is no previous course.\n");
                }
                printf("Current Course: %s\n", current->name);
                break;
            case 'q':
                break;
        }
    } while (choice != 'q');



    free_course_list(&head);  
    head = NULL;

    return 0;
}