#include <iostream>
#include <string>

struct Node {
    std::string data;
    Node* next;
};

struct Stack {
    Node* topNode;
    int count;
};

void init(Stack& s) {
    s.topNode = nullptr;
    s.count = 0;
}

bool isEmpty(const Stack& s) {
    return s.topNode == nullptr;
}



void push(Stack& s, const std::string& value) {
    Node* newNode = new Node;
    newNode->data = value;
    newNode->next = s.topNode;
    s.topNode = newNode;
    s.count++;
}

void pop(Stack& s) {
    if (isEmpty(s)) {
        std::cout << "stack is empty" << std::endl;
        return;
    }
    Node* oldTop = s.topNode;
    s.topNode = s.topNode->next;
    delete oldTop;
    s.count--;
}

std::string& top(Stack& s) {
    if (isEmpty(s)) {
        std::cout << "stack is empty" << std::endl;
        static std::string empty;
        return empty;
    }
    return s.topNode->data;
}

void clear(Stack& s) {
    while (!isEmpty(s)) pop(s);
}


int size(const Stack& s) {
    return s.count;
}



int main() {
    Stack s;
    init(s);

    push(s, "Hello");
    push(s, "World");
    push(s, "C++");

    std::cout << "top element " << top(s) << std::endl;
    std::cout << "stack size" << size(s) << std::endl;

    pop(s);
    std::cout << "pop result" << top(s) << std::endl;

    push(s, "Programming");
    std::cout << "pop result " << top(s) << std::endl;

    clear(s);
    std::cout << "is stack empty? " << (isEmpty(s) ? "Да" : "Нет") << std::endl;

    return 0;
}