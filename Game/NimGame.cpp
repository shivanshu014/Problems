#include<iostream>
#include<vector>
using namespace std;
int main(){
    int piles[] = {1,1, 3};
    int x_or = 0;
    for (int pile : piles)
        x_or ^= pile;
    cout<< (x_or != 0);
return 0;
}