#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

struct Node {
    string name;
    string drink;
    Node* next;
};

string names[] = {"Alex","Jamie","Taylor","Morgan","Riley"};
string drinks[] = {"Latte","Mocha","Espresso"};

int main() {
    srand(time(0));

    Node* head = nullptr;
    Node* tail = nullptr;

    for (int i = 0; i < 3; i++) {
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
    }

    for (int round = 1; round <= 10; round++) {
        cout << "\nRound " << round << endl;

        if (head != nullptr) {
            cout << "Serving " << head->name
                 << " ()" << head->drink << ")\n";
            Node*temp = head;
            head = head->next;
            if (head == nullptr) tail = nullptr;
            delete temp;
        } else {
            cout << "No customer to serve\n";
        }
        
    }
}