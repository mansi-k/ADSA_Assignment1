#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

#define dt double;

template <class gt>
struct SNode {
    SNode<gt> *next;
    gt num;
};

template <class gt>
class MyStack {
private:
    SNode<gt> *topNode;
    long size;
public:
    MyStack<gt>() {
        topNode = NULL;
        size = 0;
    }
    int isEmpty() {
        if(topNode == NULL)
            return 1;
        return 0;
    }
    void push(gt x) {
        SNode<gt> *node = new SNode<gt>;
        node->num = x;
        node->next = topNode;
        topNode = node;
        size++;
    }
    void pop() {
        if(!isEmpty()) {
            topNode = topNode->next;
            size--;
        }
    }
    int getSize() {
        return size;
    }
    gt getTop() {
        if(!isEmpty())
             return topNode->num;
        return (gt)NULL;
    }
};

MyStack<char> opt_stack;
MyStack<double> num_stack;

void calculate(char x) {
    double b = num_stack.getTop();
    num_stack.pop();
    double a = num_stack.getTop();
    num_stack.pop();
    if(x=='+')
        num_stack.push(a+b);
    else if(x=='-')
        num_stack.push(a-b);
    else if(x=='*')
        num_stack.push(a*b);
    else if(x=='/')
        num_stack.push((double)a/b);
    else if(x=='%')
        num_stack.push((double)fmod(a,b));
    else if(x=='^')
        num_stack.push(pow(a,b));
}

int priority(char p) {
    if(p=='+' || p=='-')
        return 1;
    if(p=='*' || p=='/' || '%')
        return 2;
    if(p=='^')
        return 3;
    return 0;
}

int main() { 
    string str, temp="";
    cin >> str;
    long i=0;
    while(i < (long)str.length()) {
        if(isdigit(str[i])) {
            while (isdigit(str[i]) || str[i] == '.') {
                temp += str[i];
                i++;
            }
            if (temp != "") {
                num_stack.push(stod(temp));
                temp = "";
            }
        }
        else if(str[i]=='(') {
            opt_stack.push(str[i]);
            i++;
        }
        else if(str[i]==')') {
            while(opt_stack.getSize()>0 && opt_stack.getTop()!='(') {
                calculate(opt_stack.getTop());
                opt_stack.pop();
            }
            opt_stack.pop();
            i++;
        }
        else {
            if(opt_stack.getSize()==0 || opt_stack.getTop()=='(')
                opt_stack.push(str[i]);
            else if((opt_stack.getTop()=='^' && str[i]=='^' ) || (priority(str[i]) > priority(opt_stack.getTop()))) {
                opt_stack.push(str[i]);
            }
            else {
                while(!opt_stack.isEmpty() && (priority(opt_stack.getTop()) >= priority(str[i])) && opt_stack.getTop()!='(') {
                    calculate(opt_stack.getTop());
                    opt_stack.pop();
                }
                opt_stack.push(str[i]);
            }
            i++;
        }
    }
    while(!opt_stack.isEmpty()) {
        calculate(opt_stack.getTop());
        opt_stack.pop();   
    }
    cout << fixed << setprecision(5) << num_stack.getTop() << endl; 
    return 0;

}
