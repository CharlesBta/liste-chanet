
#include <stdio.h>
#include <stdlib.h>

typedef struct list_element {
    int element_value;
    struct list_element *next;
} list_element;

int get_element_value_from_index (int index,list_element *current_element_of_list_elements){
    for (int i=0; i <= index; i++) {
        printf("%d\n", current_element_of_list_elements-> element_value);
        current_element_of_list_elements = current_element_of_list_elements -> next;
    }
    return current_element_of_list_elements -> element_value;

}

void show_value_of_element (list_element *element){
    printf("The value of the element is : %d\n", element -> element_value);
}

void show_all_value_of_element_with_sentence(list_element *list){
    while (list->next != NULL){
        show_value_of_element(list);
        list = list->next;
    }
    show_value_of_element(list);
}

void append_element_to_list(list_element *list, int value){
    list_element *temporary_value = malloc(sizeof(list_element));
    temporary_value->element_value = value;
    while (list->next != NULL){
        list = list->next;
    }
    list->next = temporary_value;
}

void pop(list_element *list){
    list_element *previus_element = NULL;
    while(list->next != NULL){
        previus_element = list;
        list = list->next;
    }
    previus_element->next = NULL;
    free(list);
}

int main (int argc, const char *argv[]) {

    list_element *temporary_element = NULL;
    list_element *list = NULL;

    for (int i=0; i<11; i++) {
        list_element *temporary_value = malloc(sizeof(list_element));
        temporary_value->element_value=i;

        if(temporary_element != NULL) {
            temporary_element -> next = temporary_value ;
        }

        if (temporary_element == NULL) {
            list = temporary_value;
        }

        temporary_element = temporary_value;
    }

//    show_value_of_element(list);

    show_all_value_of_element_with_sentence(list);
    printf("\n");
    append_element_to_list(list, 40);
    show_all_value_of_element_with_sentence(list);
    pop(list);
    printf("\n");
    show_all_value_of_element_with_sentence(list);

//    printf("Choose an index :\n");
//    int choice;
//    scanf("%d",&choice);
//
//    printf("The value at the index %d is %d.\n",choice, get_element_value_from_index(choice,list));
//
//
//    printf("Congrats !!\n");
    return 0;
}