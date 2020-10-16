#include <iostream>
#include <cmath>
using namespace std;

#define dt double;
#define loop(s,n) for(long i=s;i<n;i++)
#define init_cap 512


template <class gt>
class mydeque {
private:
    gt *dq = NULL;
    gt *arr;
    long ft = -1;
    long bk = -1;
    long sz = 0;
    long capacity = 0; 
public:
    mydeque<gt>() {
        grow(init_cap);
    }
    mydeque<gt>(long nwsz, gt x) {
        resize(nwsz,x);
    }
    void push_back(gt x) {
        if(full()) {
            grow(capacity+init_cap);
        }
        if(ft==-1) {
            ft = 0;
            bk = 0;
        }
        else 
            bk = (bk+1)%capacity;
        dq[bk] = x;
        sz++;
    }
    void pop_back() {
        if(!empty()) {
            if(ft==bk) {
                ft = -1;
                bk = -1;
            }
            else if(bk==0) 
                bk = capacity-1;
            else 
                bk -= 1;
            sz--;
        }
    }
    void push_front(gt x) {
        if(full()) {
            grow(capacity+init_cap);
           
        }
        if(ft==-1) {
            ft = 0;
            bk = capacity-1;
        }
        if(ft==0)
            ft = capacity-1;
        else
            ft -= 1;
        dq[ft] = x;
        sz++;
    }
    void pop_front() {
        if(!empty()) {
            if(ft==bk) {
                ft = -1;
                bk = -1;
            }
            else
                ft = (ft+1)%capacity;
            sz--;
        }
    }
    gt front() {
        if(empty())
             return 0;
        return dq[ft];
    }
    gt back() {
        if(empty())
             return 0;
        return dq[bk];
    }
    bool empty() {
        if(ft==-1)
            return true;
        return false;
    }
    int full() {
        if((bk+1)%capacity == ft)
            return 1;
        return 0;
    }
    long size() {
        return sz;
    }
    void resize(long nwsz, gt x) {  //only for user.......  defalut value for queue contents
        if(nwsz > capacity) {
            arr = new gt[nwsz+init_cap];
            if(!empty()) {
                long k=0;
                if(!empty()) {
                    long j = ft;
                    while(j!=bk) {
                        arr[k++] = dq[j];
                        j = (j+1)%capacity;
                    }
                    arr[k] = dq[bk];
                }
                loop(k+1,nwsz) {
                    arr[i] = x;
                }
            }
            else {
                loop(0,nwsz) {
                    arr[i] = x;
                }
            }
            delete[] dq;
            dq = arr;
            sz = nwsz;
            capacity = nwsz+init_cap;
            ft = 0;
            bk = nwsz-1;
        }
        else if(nwsz <= capacity) {
            long s = sz;
            if(nwsz > sz) {
                loop(s,nwsz) {
                    push_back(x);
                }
            }
            else if(nwsz < sz) {
                loop(nwsz,s) {
                    pop_back();
                }
            }
        }
    }
    void grow(long nwcap) {
        arr = new gt[nwcap];
        if(!empty()) {
            long k=0;
            long j = ft;
            while(j!=bk) {
                arr[k++] = dq[j];
                j = (j+1)%capacity;
            }
            arr[k] = dq[bk];
            ft = 0;
            bk = sz-1;
        }
        capacity = nwcap;
        delete[] dq;
        dq = arr;
    }
    void clear() {
        ft = -1;
        bk = -1;
        sz = 0;
        delete[] dq;
        dq = new gt[capacity];
    }
    long getCap() {
        return capacity;
    }
    void info() {
        cout << "ft" << ft << " bk" << bk << " sz" << sz << " cap" << capacity << endl;
        // cout << "at-ft" << front() << " at-bk" << back() << endl;
    }
    void display() {
        long st = ft;
        while(st!=bk) {
            cout << dq[st] << " ";
            st = (st+1)%capacity;
        }
        cout << dq[bk] << endl;
    }
    gt operator[](long index) { 
        if (index >= capacity) { 
            cout << "Out of capacity!" << endl;
        }
        if(ft==-1) {
            return gt();
        }
        return dq[(ft+index)%capacity]; 
    } 
};

int main() {
    mydeque<string> *q;
    long n, x;
    int a;
    string s;
    cin >> n;
    while(n--) {
        cin >> a;
        // cout << "(" << a << ") ";
        switch(a) {
            case 1: //push_front
                cin >> s;
                q->push_front(s);
                q->display();
                break;
            case 2: //pop_front
                q->pop_front();
                q->display();
                break;
            case 3: //push_back
                cin >> s;
                q->push_back(s);
                q->display();
                break;
            case 4: //pop_back
                q->pop_back();
                q->display();
                break;
            case 5: //deque()
                q = new mydeque<string>();
                break;
            case 6: //deque(n,d)
                cin >> x;
                cin >> s;
                q = new mydeque<string>(x,s);
                q->display();
                break;
            case 7: //front
                cout << q->front() << endl;
                break;
            case 8: //back
                cout << q->back() << endl;
                break;
            case 9: //empty
                // cout << q->empty() << endl;
                cout << (q->empty()?"true":"false") << endl;
                break;
            case 10: //size
                cout << q->size() << endl;
                break;
            case 11: //resize
                cin >> x;
                cin >> s;
                q->resize(x,s);
                q->display();
                break;
            case 12: //clear
                q->clear();
                q->display();
                break;
            case 13: //d[n]
                cin >> x;
                cout << (*q)[x] << endl;
                break;
            case 14: //display
                q->display();
                break;
        }
        // q->info();
    }
    delete q;
    return 0;
}
