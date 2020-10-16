#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

#define loop(s,n) for(long i=0;i<n;i++)
#define rloopi(s,n) for(long i=s-1;i>=n;i--)
#define rloopj(s,n) for(long j=s-1;j>=n;j--)

class BigInteger {
public:
    // string bigint;
    // BigInteger(string num) {
    //     bigint = num;
    // }
    BigInteger() {
        // bigint = num;
    }
    string add(string n1, string n2) {
        char cry = '0';
        string res = "";
        if(n1.length() < n2.length())
            n1.insert(0,n2.length()-n1.length(),'0');
        else
            n2.insert(0,n1.length()-n2.length(),'0');

        rloopi(n1.length(),0) {
            int a = (n1[i]-'0')+(n2[i]-'0')+(cry-'0');
            res.insert(0,1,(a%10)+'0');
            cry = (a/10)+'0';
        }
        if(cry>'0')
            res.insert(0,1,cry);
        return res;
    }
    string multiply(string n1, string n2) {
        string res="", imr="";
        char cry='0';
        if(n1.length() > n2.length())
            n1.swap(n2);
        long k=0;
        rloopi(n1.length(),0) {
            rloopj(n2.length(),0) {
                int m = (n1[i]-'0')*(n2[j]-'0')+(cry-'0');
                imr.insert(0,1,(m%10)+'0');
                cry = (m/10)+'0';
            }
            if(cry>'0')
                imr.insert(0,1,cry);
            imr.insert(imr.length(),k,'0');
            res = add(res,imr);
            imr = "";
            cry = '0';
            k++;
        }
        return res;
    }
     string factorial(long n) {
         if(n==1)
             return "1";
         long k=2;
         unsigned long long int res=1;
         string fact = "";
         while(k<=n && k<=20) {
             res = res*k;
             k++;
         }
         if(k<=n) {
             fact = to_string(res);
             while(k<=n) {
                 fact = multiply(fact,to_string(k));
                 k++;
             }
             cout <<fact;
             return fact;
         }
         return to_string(res);
     }
     string exponentian(string base, long power) {
         string res = "1";
         if(power==0)
             return res;
         if(power==1)
             return base;
         string spow = to_string(power);
         while(power>0) {
             if(power%2) {
                 res = multiply(res,base);

             }
             power = power >> 1;
             if(power>0) {
                 base = multiply(base,base);
             }
         }
         return res;
     }
     string gcd_s(string n1, string n2) {
        if(n1=="1" or n2=="1")
            return "1";
        while(str_compare(n1,n2)!=0) {
            if (str_compare(n1,n2) > 0)
                n1 = subtract(n1,n2);
            else
                n2 = subtract(n2,n1);
        }
        return n1;
     }
    string gcd_b(string n1, string n2) {
        int l = n2.compare(n1);
        if(l==0)
            return n1;
        else if(l==1)
            n1.swap(n2);
        string rem = "";
        while(n1 != "" && n1.compare("0")>0) {
            rem = modulus(n1,n2);
            n1 = n2;
            n2 = rem;
        }
        return n2;
    }
    string gcd(string n1, string n2) {
        long l1=n1.length(), l2=n2.length();
        int df = abs(l1-l2);
        int lg = (l1>l2)?l1:l2;
        if(df > (int)lg/2)
            return gcd_b(n1,n2);
        else
            return gcd_s(n1,n2);
    }
    string modulus(string n1, string n2) {
        if(n2.compare(n1)==0)
            return "0";
        if(n1=="1" || n2=="1")
            return "1";
        string low="", high=n1, med="", mul="", sub="";
        while(str_compare(low,high)<0) {
            if (low.empty()) {
                med = divide(high, 2);
            } else {
                med = divide(add(high, low), 2);
            }
            mul = multiply(med, n2);
            if (str_compare(subtract(n1, mul),n2)>=0)
                low = add(med, "1");
            else {
                high = med;
            }
        }
        med = subtract(n1,multiply(low,n2));
        return med;
    }
    string subtract(string n1, string n2) {
        string res = "";
        if(str_compare(n1,n2)<=0)
            return "0";
        n2.insert(0,n1.length()-n2.length(),'0');
        char a;
        int f=-1;
        rloopi(n2.length(),0) {
            a = (((n1[i]-'0')+10)-(n2[i]-'0'))%10+'0';
            res.insert(0,1,a);
            if(n1[i]<n2[i]) {
                n1[i-1] = ((n1[i-1]-'0')-1)+'0';
            }
            if(a=='0' && f==-1)
                f = i;
            else if(a!='0')
                f = -1;
        }
        if(f>-1)
            res = res.substr(f+1,res.length()-1);
        return res;
    }
    string divide(string n1,long n2) {
        string dv = to_string(n2);
        string res = "";
        long rm=0;
        int f=-1, g=-1;
        char c;
        loop(0,n1.length()) {
            rm = (n1[i]-'0') + rm*10;
            c = rm/n2 + '0';
            res.push_back(c);
            rm %= n2;
            if(c=='0' && g>-2)
                f = i;
            else if(c!='0')
                g = -2;
        }
        if(f>-1)
            res = res.substr(f+1,res.length());
        return res;
    }
    int str_compare(string s1, string s2) {
        if(s1.length()>s2.length())
            return 1;
        if(s1.length()<s2.length())
            return -1;
        for(long i=0;i<s1.length();i++) {
            if(s1[i] > s2[i])
                return 1;
            else if(s1[i] < s2[i])
                return -1;
        }
        return 0;
    }
};

int main(void){
    BigInteger bg;
    int n, q;
    string s1, s2;
    cin >> n;
    long x;
    while(n--) {
        //1:expo  2:gcd  3:fact
        cin >> q;
        if(q==1) {
            cin >> s1;
            cin >> x;
            cout << bg.exponentian(s1,x) << endl;
        }
        else if(q==2) {
            cin >> s1;
            cin >> s2;
            cout << bg.gcd(s1,s2) << endl;
        }
        else if(q==3) {
            cin >> x;
            cout << bg.factorial(x) << endl;
        }
    }
    return 0;
}
