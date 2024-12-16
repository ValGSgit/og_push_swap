#include <stdio.h>
#include <stdlib.h>

typedef struct s_node {
    int value;
    struct s_node *next;
} t_node;

typedef struct s_stack {
    t_node *top;
    int size;
} t_stack;

// Function prototypes
t_stack *create_stack();
void push(t_stack *stack, int value);
int pop(t_stack *stack);
void swap(t_stack *stack);
void rotate(t_stack *stack);
void reverse_rotate(t_stack *stack);
void push_a(t_stack *a, t_stack *b);
void push_b(t_stack *a, t_stack *b);
void free_stack(t_stack *stack);
void sort_stack(t_stack *a, t_stack *b);
void print_instructions(const char *instruction);
int is_sorted(t_stack *stack);

// Stack operations
t_stack *create_stack() {
    t_stack *stack = malloc(sizeof(t_stack));
    stack->top = NULL;
    stack->size = 0;
    return stack;
}

void push(t_stack *stack, int value) {
    t_node *new_node = malloc(sizeof(t_node));
    new_node->value = value;
    new_node->next = stack->top;
    stack->top = new_node;
    stack->size++;
}

int pop(t_stack *stack) {
    if (stack->size == 0)
        return 0;
    t_node *temp = stack->top;
    int value = temp->value;
    stack->top = temp->next;
    free(temp);
    stack->size--;
    return value;
}

void swap(t_stack *stack) {
    if (stack->size < 2)
        return;
    t_node *first = stack->top;
    t_node *second = first->next;
    first->next = second->next;
    second->next = first;
    stack->top = second;
}

void rotate(t_stack *stack) {
    if (stack->size < 2)
        return;
    t_node *first = stack->top;
    t_node *temp = stack->top;
    while (temp->next)
        temp = temp->next;
    stack->top = first->next;
    first->next = NULL;
    temp->next = first;
}

void reverse_rotate(t_stack *stack) {
    if (stack->size < 2)
        return;
    t_node *prev = NULL;
    t_node *current = stack->top;
    while (current->next) {
        prev = current;
        current = current->next;
    }
    current->next = stack->top;
    stack->top = current;
    prev->next = NULL;
}

void push_a(t_stack *a, t_stack *b) {
    if (b->size > 0) {
        int value = pop(b);
        push(a, value);
        print_instructions("pa");
    }
}

void push_b(t_stack *a, t_stack *b) {
    if (a->size > 0) {
        int value = pop(a);
        push(b, value);
        print_instructions("pb");
    }
}

void print_instructions(const char *instruction) {
    printf("%s\n", instruction);
}

void free_stack(t_stack *stack) {
    while (stack->size > 0)
        pop(stack);
    free(stack);
}

// Check if stack is sorted
int is_sorted(t_stack *stack) {
    if (stack->size < 2)
        return 1;
    t_node *current = stack->top;
    while (current->next) {
        if (current->value > current->next->value)
            return 0;
        current = current->next;
    }
    return 1;
}

// Sort stack using push_swap instructions
void sort_stack(t_stack *a, t_stack *b) {
    while (!is_sorted(a)) {
        if (a->top->value > a->top->next->value) {
            swap(a);
            print_instructions("sa");
        } else {
            push_b(a, b);
        }
    }
    while (b->size > 0) {
        push_a(a, b);
    }
}

// Main function
int main(int argc, char **argv) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <list of integers>\n", argv[0]);
        return 1;
    }

    t_stack *a = create_stack();
    t_stack *b = create_stack();

    for (int i = 1; i < argc; i++) {
        push(a, atoi(argv[i]));
    }

    sort_stack(a, b);

    free_stack(a);
    free_stack(b);
    return 0;
}
