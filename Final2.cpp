#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <deque>
using namespace std;

struct Node {
    string name;
    string drink;
    Node* next;
};

string names[] = {"Alex","Jamie","Taylor","Morgan","Riley"};
string drinks[] = {"Latte","Mocha","Espresso"};
string muffins[] = {"Blueberry","Chocolate","Banana Nut","Pumpkin"};

void enqueue(Node* &head, Node* &tail) {
    Node* n = new Node;
    n->name = names[rand() % 5];
    n->drink = drinks[rand() % 3];
    n->next = nullptr;
        
    if (tail == nullptr) {
        head = tail = n;
    } else {
        tail->next = n;
        tail = n;
    }
    cout << n->name << " joined the coffee queue\n";
}

void serve(Node* &head, Node* &tail) {
    if (head == nullptr) {
        cout << "No customer to serve\n";
        return;
    }

    cout << "Serving coffee to " << head->name
         << " (" << head->drink << ")\n";

    Node* temp = head;
    head = head->next;
    if (head == nullptr) tail = nullptr;
    delete temp;
}

void enqueuMuffin(deque<string &q) {
    string customer = names[rand() % 5] + string(" (") +
                      muffins[rand() % 4] + ")";
    q.push-back(customer);
    cout << customer << " joined the miffin queue"
}

void serveMuffin(deque<string> &q) {
    if(q.empty()) {
        cout << "no muffin customer to serve";
    }
    return;
}

int main() {
    srand(time(0));

    Node* head = nullptr;
    Node* tail = nullptr;

    for (int i = 0; i < 3; i++) {
        enqueue(head, tail);
    }

    for (int round = 1; round <= 10; round++) {
        cout << "\nRound " << round << endl;
        serve(head, tail);
        if (rand() % 2 == 0) {
            enqueue(head, tail);
        }
    }

    return 0;
}