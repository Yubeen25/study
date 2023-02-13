//
//  main.cpp
//  study
//
//  Created by 진유빈 on 2023/02/13.
//

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int k, vector<vector<int>> dungeons) {
    int answer = -1;
    
    sort(dungeons.begin(), dungeons.end());
    
    while(next_permutation(dungeons.begin(), dungeons.end())){
        int count = 0;
        int energy = k;
        
        for(auto dungeon: dungeons){
            if(energy >= dungeon[0]){
                energy -= dungeon[1];
                count++;
            }
            else{
                break;
            }
        }
        if(answer<count){
            answer=count;
        }
    }
    
    return answer;
}

int main(int argc, const char * argv[]) {
    std::cout << "Hello, World!\n";
    return 0;
}
