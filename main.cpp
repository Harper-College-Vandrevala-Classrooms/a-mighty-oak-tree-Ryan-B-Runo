#include <iostream>

using namespace std;

class Squirrel {
private:
    string name;

public:
    Squirrel(string name) {
        this->name = name;
    }

    string get_name() {
        return this->name;
    }
};

class Node {
    private:
    Node *leftNode, *rightNode;
    Squirrel *parent;
    public:
    Node(Squirrel *p) {
        leftNode = nullptr;
        rightNode = nullptr;
        parent = p;
    }
    void setLeft(Node *left) {
        this->leftNode = left;
    }
    void setRight(Node *right) {
        this->rightNode = right;
    }
    Squirrel* getSquirrel() {
        return parent;
    }
    Node* left() {
        return leftNode;
    }
    Node* right() {
        return rightNode;
    }
};

int main() {
    Squirrel cheeks = Squirrel("Cheeks");
    Node node_one = Node(&cheeks);

    Squirrel squeaks = Squirrel("Squeaks");
    Node node_two = Node(&squeaks);

    Squirrel fluffybutt = Squirrel("Mr. Fluffy Butt");
    Node node_three = Node(&fluffybutt);

    node_one.setLeft(&node_two);
    node_one.setRight(&node_three);

    cout << node_one.left()->getSquirrel()->get_name() << endl;; // This should retrieve the left node
    cout << node_one.right()->getSquirrel()->get_name() << endl;; // This should retrieve the right node
    cout << node_one.getSquirrel()->get_name() << endl;
    return 0;
}