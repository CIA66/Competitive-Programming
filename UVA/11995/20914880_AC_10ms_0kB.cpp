#include<stdio.h>
#include<stack>
#include<queue>

using namespace std;

int main(){
	
	int n;
	
	while(scanf("%d", &n) != EOF){
		
		int cmd, num;
		int validStack = 1, validQueue = 1, validPQ = 1;
		
		stack <int> myStack;
		queue <int> myQueue;
		priority_queue <int> myPQ;
		
		for(int a=0; a<n; a++){
			
			scanf("%d %d", &cmd, &num);
			
			if(cmd == 1){
				myStack.push(num);
				myQueue.push(num);
				myPQ.push(num);
				
			}
			else if(cmd == 2){
				
				if(myStack.empty() || myStack.top() != num) {
					validStack = 0;
				}
				else{
					myStack.pop();
				}
				
				if(myQueue.empty() || myQueue.front() != num){
					validQueue = 0;
				}
				else{
					myQueue.pop();
				}
				
				if(myPQ.empty() || myPQ.top() != num){
					validPQ = 0;
				}
				else{
					myPQ.pop();
				}

			}
			
		}
		
		int total = validPQ + validQueue + validStack;
		if(!validStack && !validQueue && !validPQ) printf("impossible\n");
		else if(total > 1) printf("not sure\n");
		else if(validStack) printf("stack\n");
		else if(validQueue) printf("queue\n");
		else if(validPQ) printf("priority queue\n");
		
		
//		printf("Stack : \n");
		while(!myStack.empty()){
//			printf("%d\n", myStack.top());
			myStack.pop();
		}
//		
//		printf("Queue : \n");
		while(!myQueue.empty()){
//			printf("%d\n", myQueue.front());
			myQueue.pop();
		}
//		
//		printf("PQ : \n");
		while(!myPQ.empty()){
//			printf("%d\n", myPQ.top());
			myPQ.pop();
		}
	}
	
	
	return 0;
}