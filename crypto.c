#include <iostream>
#include <string>
#include <vector>
template <typename T>
class MyStack {
public:
    std::vector<T> queue;

    MyStack() {}

    MyStack(std::vector<T> new_queue) {
        queue = new_queue;
    }
    void push(T item) {
        queue.push_back(item);
    }
    T pop() {
        T topo = queue.back();
        queue.erase(queue.begin());
        std::cout << "Removido: " << topo << std::endl;
        return topo;
        }
    T top() {
        T topo = queue.back();
        std::cout << "Topo: " << topo << std::endl;
        return topo;
        }
    bool empty() {
        if (!queue.empty()) {
            std::cout << "Pilha não está vazia." << std::endl;
            return false;
        } else {
            std::cout << "Pilha vazia." << std::endl;
            return true;
        }
    }
}; 
int main(){
    std::vector<std::string> queue1;
    MyStack stack(queue1);
    std::string item1 = "A";
    std::string item2 = "B";
    stack.push(item1);
    stack.push(item2);
    stack.top();
    stack.pop();
    stack.empty();
    return 0;
}