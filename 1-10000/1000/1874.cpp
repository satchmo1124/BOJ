#include <iostream>
#include <stack>
#include <queue>
#include <vector>
#include <string>
using namespace std;



void prefix(){
    stack<int>s;
    int element = 0;
    s.push(element++);

    element = 0;
    s.push(++element);

    element = 0;
    cout << "element : " << element << '\n';
    cout << "pre-increment (s.push(++element)): " << s.top() << '\n';
    s.pop();
    cout << "post-increment (s.push(element++)): " << s.top() << '\n';
    s.pop();
    return;
}

int main(){
    int N;
    int tmp;
    cin >> N;

    vector<char>state;


    
    queue<int>goal; // input sequence

    for (int i=0;i<N;i++){
        cin >> tmp;
        goal.push(tmp);
    }

    int element = 1;


    stack<int>stack; // stack seq we'll make

    int input,stack_top,element_top;


    while(!goal.empty()){ 
        
        input = goal.front();
        goal.pop();

        if (stack.empty()){ 
            if (element > N ){ // 스택도 비어있고 더 추가할 원소도 없는 경우
                printf("NO");
                return 0;
            }
            stack.push(element++); 

            state.push_back('+');
        }
        
        while(stack.top() != input){

            if (element > N){ 
                printf("NO");
                return 0;
            }

            stack.push(element++);
            state.push_back('+');
        }
        stack.pop();
        state.push_back('-');
    }
        // Now we look at stack  
    if (!stack.empty()){
        cout << "NO";
        return 0;
    }  

    for (vector<char>::iterator it = state.begin();it!=state.end();it++){
        cout << *it << '\n';
    }
}

