//
//  main.cpp
//  study
//
//  Created by 진유빈 on 2023/01/31.
//

#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

struct cmp {
    bool operator()(vector<int> a, vector<int> b) {
        return a[1] > b[1];
    }
};

int solution(vector<vector<int>> jobs) {
    int answer = 0;
    int time = 0, index = 0;
    
    sort(jobs.begin(),jobs.end());
    priority_queue<vector<int>, vector<vector<int>>, cmp> pq;
    
    while(!pq.empty() || index < jobs.size()){
        if(index < jobs.size() && jobs[index][0] <= time){
            pq.push(jobs[index]);
            index++;
            continue;
        }
        
        if(!pq.empty()){
            time += pq.top()[1];
            answer += time - pq.top()[0];
            pq.pop();
        }
        else{
            time = jobs[index][0];
        }
    }

    return answer/jobs.size();
}

int main(void) {
    vector<vector<int>> jobs = {{0, 3}, {1, 9}, {2, 6}};
    int result = solution(jobs);
    cout<< result <<endl;
}
