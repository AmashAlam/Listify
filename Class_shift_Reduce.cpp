///////////////////////////////////////////////////
/// Author :Muhammad Amash Alam                 ///
/// Roll# 20B-073-CS(A)                         ///
/// Task: Class SR parser                       ///
/// Lab: 9                                      ///
/// Date: june 2nd, 2023                        ///
/// Section: A                                  ///
/// Semester: 6th, Spring2023                   ///
///                                             ///
///////////////////////////////////////////////////
#include<stdio.h>
#include<string.h>
class Shift_Reduce{
	public:
		int k=0;
		int z=0;
		int i=0;
		int j=0;
		int c=0;
		char a[16];
		char ac[20];
		char stk[15];
		char act[10];
	void check();
	void Grammar();
};
void Shift_Reduce::Grammar()
   {

      puts("GRAMMAR is \nS->E\nE->F\nE->E+F\nF->F*T\nF->T\nT->int\nT->(E)");
      puts("enter input string ");
      gets(a);
      c=strlen(a);
      strcpy(act,"SHIFT->");
      puts("stack \t input \t action");
      for(k=0,i=0; j<c; k++,i++,j++)
       {
         if(a[j]=='i' && a[j+1]=='d')
           {
              stk[i]=a[j];
              stk[i+1]=a[j+1];
              stk[i+2]='\0';
              a[j]=' ';
              a[j+1]=' ';
              printf("\n$%s\t%s$\t%sid",stk,a,act);
              check();
           }
         else
           {
              stk[i]=a[j];
              stk[i+1]='\0';
              a[j]=' ';
              printf("\n$%s\t%s$\t%ssymbols",stk,a,act);
              check();
           }
       }

   }
void Shift_Reduce::check()
   {
     strcpy(ac,"REDUCE TO E");
     for(z=0; z<c; z++)
       if(stk[z]=='i' && stk[z+1]=='d')
         {
           stk[z]='E';
           stk[z+1]='\0';
           printf("\n$%s\t%s$\t%s",stk,a,ac);
           j++;
         }
     for(z=0; z<c; z++)
       if(stk[z]=='E' && stk[z+1]=='+' && stk[z+2]=='E')
         {A
           stk[z]='E';
           stk[z+1]='\0';
           stk[z+2]='\0';
           printf("\n$%s\t%s$\t%s",stk,a,ac);
           i=i-2;
         }
     for(z=0; z<c; z++)
       if(stk[z]=='E' && stk[z+1]=='*' && stk[z+2]=='E')
         {
           stk[z]='E';
           stk[z+1]='\0';
           stk[z+1]='\0';
           printf("\n$%s\t%s$\t%s",stk,a,ac);
           i=i-2;
         }
     for(z=0; z<c; z++)
       if(stk[z]=='(' && stk[z+1]=='E' && stk[z+2]==')')
         {
           stk[z]='E';
           stk[z+1]='\0';
           stk[z+1]='\0';
           printf("\n$%s\t%s$\t%s",stk,a,ac);
           i=i-2;
         }
   }
int main(){
	// create object of Room class
    Shift_Reduce SR;
    SR.Grammar();
    SR.check();
	return 0;
}
