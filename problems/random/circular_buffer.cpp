#include<bits/stdc++.h>
using namespace std;

class circular_buffer {
    public:
    int head;
    int tail;
    int *buffer;
    int buf_size;
    circular_buffer(int total_size) {
        head=0;
        tail=0;
        buffer=new int(total_size+1);
        buf_size=total_size;
        
    }
    void push(int val) {
        if(!isFull()){
            tail = (tail+1)%(buf_size+1);
            buffer[tail]=val;
        }
    }
    int pop(void) {
        if(!isEmpty()){
            head=(head+1)%(buf_size+1);
            int val=buffer[head];
            return val;
        }
        return -1;
    }
    bool isFull(void){
        return (head == (tail+1)%(buf_size+1));
    }
    bool isEmpty(void){
        return (head == tail);
    }
};


int main(void)
{
    circular_buffer *mybuff = new circular_buffer(4);
    for(int i = 1; i <= 10; i++) {
        mybuff->push(10*i+1);
        mybuff->push(10*i+2);
        mybuff->push(10*i+3);
        mybuff->push(10*i+4);
        mybuff->push(10*i+5);
        cout << mybuff->pop()<< " ";
        cout << mybuff->pop()<< " ";
        cout << mybuff->pop()<< " ";
        cout << mybuff->pop()<< " ";
        cout << mybuff->pop()<<endl;
    }
    return 0;
}

