#include <string>
#include <vector>
#include <iostream>

// using namespace std;
void  printv(std::vector<int> &a){
    std::cout << "print vector : ";
    for(auto k: a) {
        std::cout << k << " ";
    }
    std::cout << std::endl;
}
int solution(int n, std::vector<int> lost, std::vector<int> reserve) {
    int answer = 0;
    // 1,2,3,4 ... 배열 마들기
    std::vector<int> s_list;
    // 0:1,1:1, ...  4:1
    for(int i =0; i< n; ++i)
    {
        s_list.push_back(1);
    }
    // 가져온 index +1
    for(auto a:reserve) {
        s_list[a-1] += 1;
    }
    //  안가져온 index -1
    for (auto a: lost) {
        s_list[a-1] -= 1;
    }
    printv(s_list);
    // 0인 학생 기준으로 좌우 만 탐색. 처음과 끝부분 처리 어떻게 할것인가.
    // 총 3가지 경우로 처리하자 0, 끝, 중간
    for(int i =0; i< s_list.size(); ++i) {
        if(s_list[i] != 0)
            continue;
        if(s_list[i] == 0) {
            if(i == 0) {
                if(s_list[i+1] > 1){
                    s_list[i] +=1;
                    s_list[i+1] -=1;
                    continue;
                }
            }
            else if(i==s_list.size()-1)
            {
                if(s_list[i-1] > 1) {
                    s_list[i] +=1;
                    s_list[i-1] -=1;
                    continue;
                }
            }
            else {                
                if(s_list[i-1] > 1) {
                    s_list[i] +=1;
                    s_list[i-1] -=1;
                    continue;
                }
                else if(s_list[i+1] > 1){
                    s_list[i] +=1;
                    s_list[i+1] -=1;
                }
            }
        }
    }
    int cnt = 0;
    printv(s_list);
    for(auto a : s_list) {
        if( a >=1)
            ++cnt;
    }
    
    // 마지막 1 이상인 학생 return
    
    return cnt;
}