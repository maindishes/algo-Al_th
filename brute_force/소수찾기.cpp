#include <iostream>
#include <vector>

void combination(std::vector<int> &arr, std::vector<int> &data, int start, int end, int index) {
  if (index == data.size()) {
    // Print the current combination
    for (int i = 0; i < data.size(); i++) {
      std::cout << data[i] << " ";
    }
    std::cout << std::endl;
    return;
  }
  for (int i = start; i <= end && end - i + 1 >= data.size() - index; i++) {
    data[index] = arr[i];
    combination(arr, data, i + 1, end, index + 1);
  }
}

int main() {
  std::vector<int> arr;
  arr.push_back(1);
  arr.push_back(2);
  arr.push_back(3);
  arr.push_back(4);
  int n = arr.size();
  int k = 2;
  std::vector<int> data(k);
  combination(arr, data, 0, n - 1, 0);
  return 0;
}




