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

    for (int i = 0; i < 3, i++) {
        Node* n = new Node;
        n->name = names[rand() % 5];
        n->drink = drinks[rand() % 3];
        n->next = head;
        head = n;
    }

    if (head != nullptr) {
        cout << "Serving " << head-name << " (" << head->drink << ")\n";
        head = head->next;
    }
}