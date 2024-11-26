#include<bits/stdc++.h>
using namespace std;

class Human{
    int x;
    Human (int x) {
        x = 2;
    }
    public:
    int set(int y) {
        return  23;
    }

};

class Bhattu : public Human{
    int y;
    Bhattu{
        y = 4;
    };
    public:
    int get(int e) {
        return set(2);
    }

};


int main() {
    Bhattu bt = new Bhattu();
    cout<<bt.get(2)<<endl;
    return 0;

}