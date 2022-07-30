//
//  main.c
//  AlgC-Homework-5
//
//  Created by admin on 16.07.2022.
//

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <malloc/malloc.h>
#include <string.h>


void solution1();
//void solution2();
void solution3();
void solution4();
//void solution5();
void menu();

int main(int argc, const char * argv[]) {
    menu();
    return 0;
}

void menu() {
    srand( time(NULL) );
    int solutionNumber;
    printf("Choose solution (1..3):\n");
    scanf("%d", &solutionNumber);
    switch (solutionNumber) {
        case 1:
            solution1();
            break;
//        case 2:
//            solution2();
//            break;
        case 3:
            solution3();
            break;
        case 4:
            solution4();
            break;
//        case 5:
//            solution5();
//            break;
        default:
            printf("Wrong solution number!");
            break;
    }
}

struct TNode {
    int value;
    struct TNode *next;
};

typedef struct TNode Node;

struct Stack {
    Node *head;
    int size;
    int maxSize;
};

struct Stack Stack;

void push(int value) {
    if (Stack.size >= Stack.maxSize) {
        printf("Stack overflow");
        return;
    }
    
    Node *tmp;
    tmp = (Node*) malloc(sizeof(Node));
    
    tmp->value = value;
    tmp->next = Stack.head;
    
    Stack.head = tmp;
    Stack.size++;
}

int pop() {
    if (Stack.size == 0) {
        printf("Stack is empty");
        return -1;
    }
    
    Node* next = NULL;
    int value;
    value = Stack.head->value;
    
    next = Stack.head;
    Stack.head = Stack.head->next;
    
    free(next);
    
    Stack.size--;
    return value;
}

void printStack(struct Stack Stack) {
    Node *current = Stack.head;
    while(current != NULL) {
        printf("%d", current->value);
        current = current->next;
    }
}

void solution1() {
    printf("Solution 1:\n");
    
    Stack.maxSize = 1000;
    Stack.head = NULL;
    
    int number;
    printf("Input number:\n");
    scanf("%d", &number);
    
    while (number > 1) {
        push(number % 2);
        number /= 2;
    }
    
    printf("Binary number = %d", number);
    printStack(Stack);
    printf("\n");

}

struct CharNode {
    int value;
    struct CharNode *next;
};

typedef struct CharNode CNode;

struct CStack {
    CNode *head;
    int size;
    int maxSize;
};

struct CStack CStack;

void pushChar(int value) {
    if (CStack.size >= CStack.maxSize) {
        printf("Stack overflow");
        return;
    }
    
    CNode *tmp;
    tmp = (CNode*) malloc(sizeof(CNode));
    
    tmp->value = value;
    tmp->next = CStack.head;
    
    CStack.head = tmp;
    CStack.size++;
}

int popChar() {
    if (CStack.size == 0) {
        printf("Stack is empty");
        return -1;
    }
    
    CNode* next = NULL;
    int value;
    value = CStack.head->value;
    
    next = CStack.head;
    CStack.head = CStack.head->next;
    
    free(next);
    
    CStack.size--;
    return value;
}

void printCStack(struct CStack CStack) {
    CNode *current = CStack.head;
    while(current != NULL) {
        printf("%d", current->value);
        current = current->next;
    }
}

void solution3() {
    printf("Solution 3: \n");
    
    char bracketSequence[20] = "(1)[agd{}23]";
    printf("%s\n", bracketSequence);
    
    CStack.maxSize = 1000;
    CStack.head = NULL;
    
    int someBool = 0;
    for (int i = 0; i < strlen(bracketSequence); i++) {
        char someChar = bracketSequence[i];
        if (someChar == '(' || someChar == '{' || someChar == '[') {
            pushChar(bracketSequence[i]);
        }
        if (someChar == ')') {
            if (popChar() != '(') {
                someBool++;
                break;
            }
        }
        if (someChar == '}') {
            if (popChar() != '{') {
                someBool++;
                break;
            }
        }
        if (someChar == ']') {
            if (popChar() != '[') {
                someBool++;
                break;
            }
        }
    }
    if (CStack.size != 0 || someBool != 0) {
        printf("Incorrect bracket sequence\n");
    } else {
        printf("Correct bracket sequence\n");
    }
}

typedef struct Stack_new {
    Node *head;
    int size;
    int maxSize;
} Stack_new;

void push_new(Stack_new *stack, int value) {
    if (stack->size >= stack->maxSize) {
        printf("Stack overflow");
    }
    Node *tmp;
    tmp = (Node*) malloc(sizeof(Node));
    
    tmp->value = value;
    tmp->next = stack->head;
    
    stack->head = tmp;
    stack->size++;
}

int pop_new(Stack_new *stack) {
    if (stack->size == 0) {
        printf("Stack is empty");
    }
    
    Node* next = NULL;
    int value;
    value = stack->head->value;
    
    next = stack->head;
    stack->head = stack->head->next;
    
    free(next);
    
    stack->size--;
    return value;
}

void printStack_new(Stack_new *stack) {
    Node *current = stack->head;
    while(current != NULL) {
        printf("%d", current->value);
        current = current->next;
    }
}

void copyStack(Stack_new *oldStack, Stack_new *newStack) {
    
    Stack_new SomeStack;
    SomeStack.maxSize = 1000;
    SomeStack.size = 0;
    SomeStack.head = NULL;
    
    Node *current = oldStack->head;
    while(current != NULL) {
        push_new(&SomeStack, current->value);
        current = current->next;
    }
    
    Node *current_new = SomeStack.head;
    while(current_new != NULL) {
        push_new(newStack, current_new->value);
        current_new = current_new->next;
    }
}

void solution4() {
    Stack_new OldStack;
    OldStack.maxSize = 1000;
    OldStack.size = 0;
    OldStack.head = NULL;
    push_new(&OldStack, 1);
    push_new(&OldStack, 2);
    push_new(&OldStack, 3);
    printStack_new(&OldStack);
    
    Stack_new NewStack;
    NewStack.maxSize = 1000;
    NewStack.size = 0;
    NewStack.head = NULL;
    
    copyStack(&OldStack, &NewStack);
    printStack_new(&NewStack);
    push_new(&OldStack, 4);
    push_new(&NewStack, 5);
    printStack_new(&OldStack);
    printStack_new(&NewStack);
}
