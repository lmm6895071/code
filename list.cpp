
struct ListNode {
    int val;
   ListNode *next;
   ListNode(int x) : val(x), next(NULL) {}
 };
 ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
	    ListNode * ls,*head;
		ls=head=new ListNode(0);
	    int r=0;
        while(l1!=NULL & l2!=NULL){
			int s=l1->val+l2->val;
			ListNode * l3=new ListNode((r+s)%10);
			r=(r+s)/10;
			head->next=l3;
			l1=l1->next;
			l2=l2->next;
			head=head->next;
		}
		ListNode * lss=NULL;
		if(l1==NULL & l2!=NULL)
			lss=l2;
		else if(l1!=NULL &&l2==NULL)
			lss=l1;
		while(lss!=NULL){
			ListNode * l3=new ListNode((r+lss->val)%10);
			r=(r+lss->val)/10;
			head->next=l3;
			lss=lss->next;
			head=head->next;
		}
		if(r>0)
			head->next=new ListNode(r);
		return ls->next;
    }
 void  pirnt(ListNode * l){
	 while(l!=NULL){
		 cout<<l->val<<" ";
		 l=l->next;
	 }
	 cout<<endl;
 }
int test()
{
	ListNode* l1=new ListNode(1);
	
	pirnt(l1);
	ListNode* l11=new ListNode(9);
	ListNode* l12=new ListNode(9);
	ListNode * l13=new ListNode(9);
	l11->next=l12;
	l12->next=l13;
	pirnt(l11);
	ListNode * l=addTwoNumbers(l1,l11);
	pirnt(l);

}