#include<iostream>
#include<vector>
using namespace std;

void merage(vector<int>&arr, int low, int mid, int high) {
    vector<int>temp;
    int left = low;
    int right = mid+1;

    while(left<=mid and right<=high) {
        if(arr[left]<arr[right]) {
            temp.push_back(arr[left++]);
        }else {
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
}
void mergeSort(vector<int>&arr, int low, int high) {
    if(low>=high) return ;
        int mid = (low+high)/2;
        mergeSort(arr, 0, mid);
        mergeSort(arr, mid+1, high);
        merage(arr, low, mid, high);
    
}
int main() {

    vector<int> arr = {5, 4, 3, 2, 1}  ;
    int n = 5;

    cout << "Before Sorting Array: " << endl;
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " "  ;
    }
    cout << endl;
    mergeSort(arr, 0, n - 1);
    cout << "After Sorting Array: " << endl;
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " "  ;
    }
    cout << endl;
    return 0 ;
}