#include <iostream>
#include <string>
using namespace std;

// Node structure for Linked List
struct Node {
    string event;
    Node* next;

    Node(string e) {
        event = e;
        next = nullptr;
    }
};

// Stack to store past events
class Stack {
private:
    Node* top;

public:
    Stack() {
        top = nullptr;
    }

    void push(string event) {
        Node* newNode = new Node(event);
        newNode->next = top;
        top = newNode;
    }

    string pop() {
        if (top == nullptr) {
            return "";
        }

        Node* temp = top;
        string event = temp->event;

        top = top->next;
        delete temp;

        return event;
    }

    bool empty() {
        return top == nullptr;
    }
};

// Queue to store future events
class Queue {
private:
    Node* front;
    Node* rear;

public:
    Queue() {
        front = nullptr;
        rear = nullptr;
    }

    void enqueue(string event) {
        Node* newNode = new Node(event);

        if (rear == nullptr) {
            front = rear = newNode;
        }
        else {
            rear->next = newNode;
            rear = newNode;
        }
    }

    string dequeue() {
        if (front == nullptr) {
            return "";
        }

        Node* temp = front;
        string event = temp->event;

        front = front->next;

        if (front == nullptr) {
            rear = nullptr;
        }

        delete temp;

        return event;
    }

    bool empty() {
        return front == nullptr;
    }
};

// Main function
int main() {

    Stack past;
    Queue future;

    string current = "Present Day";

    // Adding some initial future events
    future.enqueue("College Begins");
    future.enqueue("First Semester Exam");
    future.enqueue("Annual Function");

    int choice;
    string event;

    cout << "============================================" << endl;
    cout << "        TIME TRAVEL SIMULATOR" << endl;
    cout << "============================================" << endl;

    while (true) {

        cout << "\n--------------------------------------------" << endl;
        cout << "Current Event: " << current << endl;
        cout << "--------------------------------------------" << endl;

        cout << "1. Travel Forward" << endl;
        cout << "2. Travel Back" << endl;
        cout << "3. Undo Time Travel" << endl;
        cout << "4. Add Future Event" << endl;
        cout << "5. Exit" << endl;

        cout << "\nEnter your choice: ";
        cin >> choice;

        switch (choice) {

        // Travel Forward using Queue
        case 1:

            if (future.empty()) {
                cout << "\nNo future events available!" << endl;
            }
            else {
                past.push(current);

                current = future.dequeue();

                cout << "\nTravelled Forward to: "
                     << current << endl;
            }

            break;

        // Travel Back using Stack
        case 2:

            if (past.empty()) {
                cout << "\nNo past events available!" << endl;
            }
            else {

                // Save current event into future queue
                future.enqueue(current);

                current = past.pop();

                cout << "\nTravelled Back to: "
                     << current << endl;
            }

            break;

        // Undo last time travel
        case 3:

            if (past.empty()) {
                cout << "\nNo previous event available for undo!" << endl;
            }
            else {

                future.enqueue(current);

                current = past.pop();

                cout << "\nUndo Time Travel -> "
                     << current << endl;
            }

            break;

        // Add a new future event
        case 4:

            cout << "\nEnter new future event: ";
            cin.ignore();
            getline(cin, event);

            if (event.empty()) {
                cout << "Event cannot be empty!" << endl;
            }
            else {
                future.enqueue(event);

                cout << "Future event added: "
                     << event << endl;
            }

            break;

        // Exit
        case 5:

            cout << "\nThank you for using Time Travel Simulator!" << endl;
            return 0;

        default:

            cout << "\nInvalid choice! Please try again." << endl;
        }
    }

    return 0;
}