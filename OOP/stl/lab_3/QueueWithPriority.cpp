// Created by Anastasia.

#include <deque>
#include <algorithm>
#include <string>
#include <stdexcept>
#include <iostream>

enum class ElementPriority { LOW, NORMAL, HIGH };

struct QueueElement {
    std::string name;
    ElementPriority priority;
};

class QueueWithPriority {

//private: std::deque<QueueElement> elements;
public:
   
    QueueWithPriority() {}

    ~QueueWithPriority() {}

    std::deque<QueueElement> elements;

    void PutElementToQueue(const QueueElement& element) {
        elements.push_back(element);
    }

    QueueElement GetElementFromQueue() {
        if (elements.empty()) {        
            throw std::runtime_error("Queue is empty!");
        }
      
        int max_index = 0;
        for (int i = 1; i < elements.size(); ++i) {
            if (elements[i].priority > elements[max_index].priority) {
                max_index = i;
            } else if (elements[i].priority == elements[max_index].priority && i < max_index) {
                max_index = i;
            }
        }

        QueueElement max_element = elements[max_index];

        elements.erase(elements.begin() + max_index);

        return max_element;
    }


    void Accelerate() {
        for (int i = 0; i < elements.size(); i++) {
            if (elements[i].priority == ElementPriority::LOW) {
                elements[i].priority = ElementPriority::HIGH;
            }
        }
        int normal_index = 0;
        int high_index = elements.size() - 1;
        while (normal_index <= high_index) {
            if (elements[normal_index].priority >= ElementPriority::NORMAL) {
                normal_index++;
            } else {
                std::swap(elements[normal_index], elements[high_index]);
                high_index--;
            }
        }
    }

    void PrintQueue() const {
        for (const auto& item : elements) {
            std::cout << "Element name: " << item.name << ", priority: " << static_cast<int>(item.priority) << std::endl;
        }
    }


};

int main() {
    QueueWithPriority queue;


    queue.PutElementToQueue({"Element 1", ElementPriority::NORMAL});
    queue.PutElementToQueue({"Element 2", ElementPriority::LOW});
    queue.PutElementToQueue({"Element 3", ElementPriority::HIGH});
    queue.PutElementToQueue({"Element 4", ElementPriority::NORMAL});
    queue.PutElementToQueue({"Element 5", ElementPriority::LOW});
    queue.PutElementToQueue({"Element 6", ElementPriority::HIGH});
    queue.PutElementToQueue({"Element 7", ElementPriority::NORMAL});

    std::cout << "Initial queue:\n";
    queue.PrintQueue();

  
    queue.Accelerate();


    std::cout << "\nQueue after acceleration:\n";
    queue.PrintQueue();

    std::cout << "\nGetting elements from queue:\n";

   /* while (!queue.elements.empty()) {
        QueueElement element = queue.GetElementFromQueue();
        std::cout << element.name << ", priority: " << static_cast<int>(element.priority) << std::endl;
    } */
    QueueElement element = queue.GetElementFromQueue();
    std::cout << element.name << ", priority: " << static_cast<int>(element.priority) << std::endl;

    return 0;
}
