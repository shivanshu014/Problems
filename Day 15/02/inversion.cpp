#include<iostream>
#include<vector>
using namespace std;

void merage(vector<int>&arr, int low, int mid, int high) {
    // int cnt = 0;
    vector<int>temp;
    int left = low;
    int right = mid+1;

    while(left<=mid and right<=high) {
        if(arr[left]<arr[right]) {
            temp.push_back(arr[left++]);
        }else {
            // cnt+=(mid-left+1);
            temp.push_back(arr[right++]);
        }
    }
    while(left<=mid) {
        temp.push_back(arr[left++]);
    }
    while(right<=high) {
        temp.push_back(arr[right++]);
    }

    for(int i=low; i<=high; i++) {
        arr[i] = temp[i-low];
    }
    return ;
}
int cntReg(vector<int>&arr, int low, int mid, int high) {
    int cnt = 0; 
    int right = mid+1;
    for(int i=low; i<=mid; i++) {
        while(right<=high && arr[i]>2*arr[right]) right++;
        cnt+=(right-(mid+1));
    }
    return cnt;
}
int mergeSort(vector<int>&arr, int low, int high) {
    int cnt = 0;
    if(low>=high) return 0;
        int mid = (low+high)/2;
        cnt+=mergeSort(arr, 0, mid);
        cnt+=mergeSort(arr, mid+1, high);
        cnt+=cntReg(arr, low, mid, high);
        merage(arr, low, mid, high);
    return cnt;
}
int main() {

    vector<int> arr = {4, 1, 2, 3, 1}  ;
    int n = 5;

    cout << "Before Sorting Array: " << endl;
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " "  ;
    }
    cout << endl;
    cout<<mergeSort(arr, 0, n - 1);
    cout << "After Sorting Array: " << endl;
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " "  ;
    }
    cout << endl;
    return 0 ;
}