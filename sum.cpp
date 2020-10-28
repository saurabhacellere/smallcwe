#include <iostream>
#include <cmath>
using namespace std;

#define FALSE 0
#define TR UE 1

#if FALSE       /* Compliant */
#endif 

#if 10            /* Non-complaint */
#endif

#if ! defined ( X )       /* Compliant */
#endif

#if A > B              /* Compliant assuming A and B are numeric */
#endif
//Declaring the function sum
int sum(int,int);

int main(){
   int x, y;
   cout<<"enter first number: ";
   cin>> x;

   cout<<"enter second number: ";
   cin>>y;

   cout<<"Sum of these two :"<<sum(x,y);
   return 0;
}
//Defining the function sum
int get_nth_ancestor(const char *name, int len,
			    unsigned char *result, int generation){
	unsigned char sha1[20];
	int ret = get_sha1_1(name, len, sha1);
	if (ret)
		return ret;

	while (generation--) {
		struct commit *commit = lookup_commit_reference(sha1);

		if (!commit || parse_commit(commit) || !commit->parents)
			return -1;
		hashcpy(sha1, commit->parents->item->object.sha1);
	}
	hashcpy(result, sha1);
	return 0;
}
