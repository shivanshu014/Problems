#include<bits/stdc++.h>
using namespace std;
class ListNode{
public: 
	int val; 
	ListNode* next;
	ListNode(int val) {
		this->val = val;
		this->next = NULL;
	}
};

ListNode* reverse(ListNode* head, int k){
	ListNode* prev=NULL, *curr = head, *next = head;
	while(k-- and curr) {
		next = curr->next;
		curr->next = prev;
		prev = curr;
		curr = next;
	}
	return prev;
}

ListNode* reverseKGroupElement(ListNode* head, int k) {
	ListNode* temp = head;
	int cnt = 0;
    while(temp && cnt<k) {
        temp = temp->next;
        cnt++;
    }
    if (cnt < k) return head;
	ListNode* newhead = reverse(head, k);
	head->next = reverseKGroupElement(temp, k);
return newhead;
}

ListNode* reverseKGroupElement(ListNode* head, int k) {
	ListNode* curr = head;
	ListNode* ans = NULL;
	while(curr) {
		ListNode* tail = curr;
		int cnt = 0;
		ListNode* temp = curr;
		while(temp and cnt<k){
			temp = temp->next;
			cnt++;
		}
		if(cnt<k) return ans;
		ListNode* next = temp->next;
		ListNode* revHead = reverse(tail, k);
		if(ans==NULL) {
			ans = revHead;
		}else{
			tail->next = next;
		}
		curr = temp;
	}
	
return ans;
}

int main() {
	ListNode* head = new ListNode(1);
	head->next = new ListNode(2);
	head->next->next = new ListNode(3);
	head->next->next->next = new ListNode(4);
	head->next->next->next->next = new ListNode(5);
	head->next->next->next->next->next = new ListNode(6);
	head->next->next->next->next->next->next = new ListNode(7);
	head = reverseKGroupElement(head, 3);

    ListNode* temp = head;
    while (temp) {
        cout << temp->val << " ";
        temp = temp->next;
    }
    cout << endl;
return 0;
}


class Solution {
public:
    void reverse(ListNode* head) {
        ListNode* prev=NULL, *curr = head, *next = head;

        while(curr) {
            next = curr->next;
            curr->next = prev; 
            prev = curr;
            curr = next;
        }
    }

    ListNode* getKthNode(ListNode* temp, int k) {
        k-=1;
        while(temp and k>0) {
            temp = temp->next;
            k--;
        }
        return temp;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* temp = head, preLast = NULL;
        while(temp!=NULL) {
            ListNode* KthNode = getKthNode(temp, k);
            if(KthNode==NULL) {
                if(preLast) preLast->next = temp;
                break;
            }
            ListNode* nextListNode = KthNode->next;
            KthNode->next = NULL;
            reverse(temp);
            if(temp==head) {
                head = KthNode;
            }else{
                preLast->next = KthNode;
            }
            preLast = temp;
            temp = nextListNode;
        }
    }
};





