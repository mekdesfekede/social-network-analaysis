#include <iostream>
#include <vector>
#include <algorithm>

int main() {
  // Example 1: Basic output and input
  std::cout << "Enter your name: ";
  std::string name;
  std::getline(std::cin, name); // Reads a line of input, including spaces
  std::cout << "Hello, " << name << "!" << std::endl;

  // Example 2: Working with vectors
  std::vector<int> numbers = {5, 2, 8, 1, 9};

  std::cout << "Original vector: ";
  for (int num : numbers) {
    std::cout << num << " ";
  }
  std::cout << std::endl;

  std::sort(numbers.begin(), numbers.end()); // Sort the vector

  std::cout << "Sorted vector: ";
  for (int num : numbers) {
    std::cout << num << " ";
  }
  std::cout << std::endl;

  // Example 3: Simple function
  auto add = [](int a, int b) { // Lambda function for addition.
    return a + b;
  };

  int sum = add(10, 20);
  std::cout << "10 + 20 = " << sum << std::endl;

  //Example 4: simple conditional.
  int age = 25;
  if(age >= 18){
    std::cout << "You are an adult" << std::endl;
  } else {
    std::cout << "You are a minor" << std::endl;
  }

  //Example 5: a simple for loop.
  for(int i = 0; i < 5; ++i){
    std::cout << "Iteration: " << i << std::endl;
  }

  return 0;
}