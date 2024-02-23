#include <iostream>

using namespace std;

const int n = 100; // Maximum stack size

int stack[n];
int top = -1; // Initialize top to -1 (empty stack)

void push() {
    if (top == n - 1) {
        cout << "Stack overflow!\n";
        return;
    }

    int element;
    cout << "Enter element to push: ";
    cin >> element;

    top++; // Increment top before assigning to avoid overwriting elements
    stack[top] = element;
    cout << element << " pushed successfully.\n";
}

void pop() {
    if (top == -1) {
        cout << "Stack underflow!\n";
        return;
    }

    int element = stack[top];
    top--;
    cout << element << " popped successfully.\n";
}

void display() {
    if (top == -1) {
        cout << "Stack is empty.\n";
        return;
    }

    cout << "Stack elements: ";
    for (int i = top; i >= 0; i--) {
        cout << stack[i] << " ";
    }
    cout << endl;
}

int main() {
    char operation;

    while (true) {
        cout << "\nStack Operations:\n";
        cout << "1. Push\n";
        cout << "2. Pop\n";
        cout << "3. Display\n";
        cout << "4. Exit\n";
        cout << "Enter your choice ('1', '2', '3' or '4'): ";
        cin >> operation;

        if (operation == '1') {
            push();
        } else if (operation == '2') {
            pop();
        } else if (operation == '3') {
            display();
        } else if (operation == '4') {
            cout << "Exiting...\n";
            return 0;
        } else {
            cout << "Invalid choice.\n";
        }
    }

    return 0;
}
