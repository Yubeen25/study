//
//  main.cpp
//  조이스틱
//
//  Created by 진유빈 on 2023/02/20.
//

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(string name) {
    int answer = 0;
    int len= name.size();
    int count = len-1;

    for(int index=0 ; index < len ; index++){
        answer += min(name[index]-'A','Z'-name[index]+1);
        
        int next = index+1;
        while(next < len && name[next]=='A'){
            next++;
        }
        count = min(count, index+len-next+min(index,len-next));
    }
    
    answer += count;
    
    return answer;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
