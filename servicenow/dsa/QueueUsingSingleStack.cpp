#include <iostream>
#include <stack>
using namespace std;

class QueueUsingOneStack {
    stack<int> st;

public:
    // Enqueue: simply push the element
    void enqueue(int x) {
        st.push(x);
    }

    // Dequeue: recursive function to get front element
    int dequeue() {
        if (st.empty()) {
            cout << "Queue is empty!" << endl;
            return -1;
        }

        int x = st.top();
        st.pop();

        // Base case: if this is the last element, return it
        if (st.empty()) {
            return x;
        }

        // Recursive call to reach the bottom element
        int front = dequeue();

        // Push the held elements back to maintain order
        st.push(x);

        return front;
    }

    // To check if queue is empty
    bool empty() {
        return st.empty();
    }
};

int main() {
    QueueUsingOneStack q;

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);

    cout << q.dequeue() << endl; // Output: 10
    cout << q.dequeue() << endl; // Output: 20
    cout << q.dequeue() << endl; // Output: 30
    cout << q.dequeue() << endl; // Output: Queue is empty!
}
