#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <deque>
#include <vector>
using namespace std;

struct Node {
    string name;
    string drink;
    Node* next;
};

string names[] = {"Alex","Jamie","Taylor","Morgan","Riley"};
string drinks[] = {"Latte","Mocha","Espresso"};
string muffins[] = {"Blueberry","Chocolate","Banana Nut","Pumpkin"};
string bracelets[] = {"Red","Blue","Green","Purple","Pink"};

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

void enqueueMuffin(deque<string> &q) {
    string customer = names[rand() % 5] + string(" (") +
                      muffins[rand() % 4] + ")";
    q.push_back(customer);
    cout << customer << " joined the muffin queue\n";
}

void serveMuffin(deque<string> &q) {
    if(q.empty()) {
        cout << "No muffin customer to serve\n";
        return;
    }
    cout << "Serving muffin to " << q.front() << endl;
    q.pop_front();
}

void enqueueBracelet(vector<string> &v) {
    string customer = names[rand() % 5] + string(" (") +
                      bracelets[rand() % 5] + ")";
    v.push_back(customer);
    cout << customer << " joined the bracelet queue\n";
}

void serveBracelet(vector<string> &v) {
    if (v.empty()) {
        cout << "No bracelet customer to serve\n";
        return;
    }

    cout << "Serving bracelet to " << v.front() << endl;
    v.erase(v.begin());
}

int main() {
    srand(time(0));

    Node* head = nullptr;
    Node* tail = nullptr;
    deque<string> muffinQ;
    vector<string> braceletQ;

    for (int i = 0; i < 3; i++) {
        enqueue(head, tail);
        enqueueMuffin(muffinQ);
        enqueueBracelet(braceletQ);
    }

    for (int round = 1; round <= 10; round++) {
        cout << "\nRound " << round << endl;

        serve(head, tail);
        serveMuffin(muffinQ);
        serveBracelet(braceletQ);

        if (rand() % 2 == 0) enqueue(head, tail);
        if (rand() % 2 == 0) enqueueMuffin(muffinQ);
        if (rand() % 2 == 0) enqueueBracelet(braceletQ);
    }

    return 0;
}