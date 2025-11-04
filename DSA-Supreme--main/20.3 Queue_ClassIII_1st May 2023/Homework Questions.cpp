
/*
Approach and Problem List with Comments, Alternatives, and Dry Run

1) Implement stack using queue
   // Logic: Use two queues (or a single queue with rotation) to simulate LIFO behavior of stack.
   // Approach 1: Two Queues
   //   - Push: Enqueue to q2, dequeue all from q1 to q2, swap q1 and q2.
   //   - Pop: Dequeue from q1.
   // Approach 2: Single Queue (Optimized)
   //   - Push: Enqueue to q, then rotate the queue (dequeue and enqueue back n-1 times).
   //   - Pop: Dequeue from q.
   // Code for Single Queue Approach:
   /*
   class MyStack {
       queue<int> q;
   public:
       void push(int x) {
           q.push(x); // Insert new element
           for(int i = 0; i < q.size() - 1; ++i) {
               q.push(q.front()); // Move front to back
               q.pop();
           }
       }
       int pop() {
           int val = q.front();
           q.pop();
           return val;
       }
       int top() { return q.front(); }
       bool empty() { return q.empty(); }
   };
   */
   // Dry Run:
   // push(1): q = [1]
   // push(2): q = [2,1] (rotate once)
   // push(3): q = [3,2,1] (rotate twice)
   // pop(): returns 3, q = [2,1]

2) Implement queue using stack
   // Logic: Use two stacks to simulate FIFO behavior of queue.
   // Approach:
   //   - Enqueue: Push to stack1.
   //   - Dequeue: If stack2 is empty, pop all from stack1 to stack2, then pop from stack2.
   // Code:
   /*
   class MyQueue {
       stack<int> s1, s2;
   public:
       void enqueue(int x) { s1.push(x); }
       int dequeue() {
           if(s2.empty()) {
               while(!s1.empty()) {
                   s2.push(s1.top());
                   s1.pop();
               }
           }
           int val = s2.top();
           s2.pop();
           return val;
       }
       bool empty() { return s1.empty() && s2.empty(); }
   };
   */
   // Dry Run:
   // enqueue(1): s1=[1], s2=[]
   // enqueue(2): s1=[1,2], s2=[]
   // dequeue(): s2=[], move s1 to s2: s2=[2,1], s1=[], pop 1

3) K queues in array
   // Logic: Use a single array to implement k queues efficiently.
   // Approach:
   //   - Use arr[] for data, next[] for next free/queue link, front[]/rear[] for each queue, and a free pointer.
   //   - Enqueue: Use free spot, update next, front, rear.
   //   - Dequeue: Update front, next, and free.
   // Code:
   /*
   class KQueues {
       int *arr, *front, *rear, *next, n, k, free;
   public:
       KQueues(int k, int n) {
           this->k = k; this->n = n;
           arr = new int[n];
           front = new int[k];
           rear = new int[k];
           next = new int[n];
           for(int i=0;i<k;i++) front[i]=rear[i]=-1;
           for(int i=0;i<n-1;i++) next[i]=i+1;
           next[n-1]=-1;
           free=0;
       }
       void enqueue(int x, int qn) {
           if(free==-1) return; // Overflow
           int i=free;
           free=next[i];
           if(front[qn]==-1) front[qn]=i;
           else next[rear[qn]]=i;
           next[i]=-1;
           rear[qn]=i;
           arr[i]=x;
       }
       int dequeue(int qn) {
           if(front[qn]==-1) return -1; // Underflow
           int i=front[qn];
           front[qn]=next[i];
           next[i]=free;
           free=i;
           return arr[i];
       }
   };
   */
   // Dry Run:
   // k=2, n=5, enqueue(10,0), enqueue(15,1), enqueue(20,0), dequeue(0) returns 10

4) Maximum number of tasks you can assign
   // Logic: Given tasks and workers, assign as many tasks as possible.
   // Approach:
   //   - Sort tasks and workers.
   //   - Use two pointers: assign smallest task to smallest capable worker.
   //   - If worker can do task, assign and move both pointers; else, move worker pointer.
   // Code:
   /*
   int maxTasks(vector<int>& tasks, vector<int>& workers) {
       sort(tasks.begin(), tasks.end());
       sort(workers.begin(), workers.end());
       int i=0, j=0, count=0;
       while(i<tasks.size() && j<workers.size()) {
           if(workers[j]>=tasks[i]) { count++; i++; }
           j++;
       }
       return count;
   }
   */
   // Dry Run:
   // tasks=[1,3,5], workers=[2,4,6]
   // assign 1->2, 3->4, 5->6, count=3

5) Sum of minimum and maximum element of all subarray of size k
   // Logic: For each window of size k, find min and max, sum them up.
   // Approach 1: Brute Force O(n*k)
   //   - For each window, scan for min and max.
   // Approach 2: Deque (Optimized O(n))
   //   - Use two deques: one for min, one for max.
   //   - For each element, maintain deques for current window.
   //   - For each window, add front of both deques to sum.
   // Code:
   /*
   int sumOfMinAndMax(vector<int>& arr, int k) {
       int n = arr.size(), sum = 0;
       deque<int> minD, maxD;
       for(int i=0;i<n;i++) {
           // Remove out of window
           if(!minD.empty() && minD.front()<=i-k) minD.pop_front();
           if(!maxD.empty() && maxD.front()<=i-k) maxD.pop_front();
           // Remove useless elements
           while(!minD.empty() && arr[minD.back()]>=arr[i]) minD.pop_back();
           while(!maxD.empty() && arr[maxD.back()]<=arr[i]) maxD.pop_back();
           minD.push_back(i);
           maxD.push_back(i);
           if(i>=k-1) sum += arr[minD.front()] + arr[maxD.front()];
       }
       return sum;
   }
   */
   // Dry Run:
   // arr=[2,5,-1,7,-3,-1,-2], k=4
   // Windows: [2,5,-1,7], [5,-1,7,-3], ...
   // For each, sum min+max and accumulate.

