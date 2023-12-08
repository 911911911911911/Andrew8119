#include <iostream>
#include <vector>

using namespace std;

class PriorityQueue {
private:
    vector<int> heap;

    void heapifyUp(vector<int>::size_type index) {
        while (index > 0) {
            vector<int>::size_type parent = (index - 1) / 2;
            if (heap[parent] > heap[index]) {
                swap(heap[parent], heap[index]);
                index = parent;
            } else {
                break;
            }
        }
    }

    void heapifyDown(vector<int>::size_type index) {
        vector<int>::size_type size = heap.size();
        while (index < size) {
            vector<int>::size_type left = 2 * index + 1;
            vector<int>::size_type right = 2 * index + 2;
            vector<int>::size_type smallest = index;
            if (left < size && heap[left] < heap[smallest]) {
                smallest = left;
            }
            if (right < size && heap[right] < heap[smallest]) {
                smallest = right;
            }
            if (smallest != index) {
                swap(heap[index], heap[smallest]);
                index = smallest;
            } else {
                break;
            }
        }
    }

public:
    void push(int value) {
        heap.push_back(value);
        heapifyUp(heap.size() - 1);
    }

    void pop() {
        if (heap.empty()) {
            return;
        }
        heap[0] = heap.back();
        heap.pop_back();
        heapifyDown(0);
    }

    int top() {
        if (!heap.empty()) {
            return heap[0];
        }
        return -1; 
    }

    bool empty() {
        return heap.empty();
    }
};

int main() {
    PriorityQueue pq;
    pq.push(3);
    pq.push(2);
    pq.push(5);
    pq.push(1);

    while (!pq.empty()) {
        cout << pq.top() << " ";
        pq.pop();
    }

    cout << endl;

    return 0;
}
