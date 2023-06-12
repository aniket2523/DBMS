#include<iostream>
using namespace std;

class Node {
public:
    int coeff;
    int power;
    Node* next;
};

class LinkedList {
public:
Node* head;
    LinkedList() {
        head = NULL;
    }

    void accept() {
        int numTerms;
        cout << "Enter the number of terms: ";
        cin >> numTerms;

        for (int i = 0; i < numTerms; i++) {
            int coeff, power;
            cout << "Enter the coefficient and exponent of term " << i+1 << ": ";
            cin >> coeff >> power;
            insert(coeff, power);
        }
    }
    void insert(int c, int p) {
        Node* temp = new Node;
        temp->coeff = c;
        temp->power = p;
        temp->next = head;

        if(head == NULL) {
            head = temp;
            head->next = head;
        }
        else {
            Node* curr = head;
            while(curr->next != head) {
                curr = curr->next;
            }
            curr->next = temp;
        }
    }

    void addPoly(LinkedList poly1, LinkedList poly2) {
        Node* ptr1 = poly1.head;
        Node* ptr2 = poly2.head;

        do {
            if(ptr1->power == ptr2->power) {
                int sum = ptr1->coeff + ptr2->coeff;
                insert(sum, ptr1->power);
                ptr1 = ptr1->next;
                ptr2 = ptr2->next;
            }
            else if(ptr1->power > ptr2->power) {
                insert(ptr1->coeff, ptr1->power);
                ptr1 = ptr1->next;
            }
            else {
                insert(ptr2->coeff, ptr2->power);
                ptr2 = ptr2->next;
            }
        } while(ptr1 != poly1.head || ptr2 != poly2.head);
    }

    void display() {
        Node* curr = head;
        do {
            cout << curr->coeff << "x^" << curr->power;
            curr = curr->next;
            if(curr != head) {
                cout << " + ";
            }
        } while(curr != head);
    }
};

int main() {
    LinkedList poly1, poly2, result;

    cout << "Accepting polynomial 1" << endl;
    poly1.accept();
    cout << "Accepting polynomial 2" << endl;
    poly2.accept();
   
    cout << "Polynomial 1: ";
    poly1.display();
    cout<<endl;
    cout << "Polynomial 2: ";
    poly2.display();
    cout<<endl;
    result.addPoly(poly1, poly2);
    cout<<"\nAddition is : ";
    // Display the result
    result.display();   
    return 0;
}
