#include <queue>
using namespace std;

class MyStack {
private:
    queue<int> q;

public:
    // Constructor
    MyStack() {

    }

    // Push element x onto stack
    void push(int x) {
        q.push(x);

        // Move all previous elements behind the new one
        int n = q.size();
        while (n > 1) {
            q.push(q.front());
            q.pop();
            n--;
        }
    }

    // Removes the element on top of the stack and returns it
    int pop() {
        int x = q.front();
        q.pop();
        return x;
    }

    // Get the top element
    int top() {
        return q.front();
    }

    // Returns whether the stack is empty
    bool empty() {
        return q.empty();
    }
};