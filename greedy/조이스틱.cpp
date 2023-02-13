#include <string>
#include <vector>
#include <iostream>
// using namespace std;
void printv(std::vector<int> &a) {
    std::cout << "vector : ";
    for(auto k : a) {
        std::cout << k << " ";
    }
    std::cout <<  std::endl;
}
int solution(std::string name) {
    int answer = 0;
    //  일단 변경해야하는 count 아스키 코드로 빼서 배열 만들고 
    //  좌우 움직이는거 처리는 index로 처리 근데 000  으로 변경 안 해도 되는건 어떻게 처리?? 
    std::vector<int> ivec;
    std::cout << 'N'-'A' << std::endl;
    for(auto k : name) {
        if(k > 'N')
            ivec.push_back(26-(k-'A'));
        else
            ivec.push_back(k-'A');   
    }
    printv(ivec);
    int sum=0;
    for(auto k : ivec) {
        sum += k;
    }
    return sum+name.length()-1;
}