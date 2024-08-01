#include <iostream>
#include <stack>
#include <utility> // For std::pair

class StockSpanner {
private:
    std::stack<std::pair<int, int> > st; 

public:
    StockSpanner() {
        // Constructor doesn't need to do anything special
    }
    
    int next(int price) {
        int span = 1; // Start with a span of 1 for the current day
        
        // While the stack is not empty and the price at the top of the stack is less than or equal to the current price
        while (!st.empty() && st.top().first <= price) {
            span += st.top().second; // Add the span of the top element to the current span
            st.pop(); // Remove the top element from the stack
        }
        
        // Push the current price and its calculated span onto the stack
        st.push(std::make_pair(price, span));
        
        return span; 
    }
};

int main() {
    StockSpanner* stockSpanner = new StockSpanner();
    std::cout << stockSpanner->next(100) << std::endl; // Output: 1
    std::cout << stockSpanner->next(80) << std::endl;  // Output: 1
    std::cout << stockSpanner->next(60) << std::endl;  // Output: 1
    std::cout << stockSpanner->next(70) << std::endl;  // Output: 2
    std::cout << stockSpanner->next(60) << std::endl;  // Output: 1
    std::cout << stockSpanner->next(75) << std::endl;  // Output: 4
    std::cout << stockSpanner->next(85) << std::endl;  // Output: 6
    delete stockSpanner;
    return 0;
}

