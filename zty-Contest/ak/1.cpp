#include <stdio.h> 
int main() 
{ 
 const int SIZE = 100; 
 int n, i, j, a[SIZE], cur1, cur2, count1, count2, 
  ans_length, ans_start, ans_end;  //cur1, cur2 分别表示当前子序列中的两个不同整数  //count1, count2 分别表示 cur1, cur2 在当前子序列中出现的次数 
 scanf("%d", &n); 
 for (i = 1; i <= n; i++) 
  scanf("%d", &a[i]); 
 i = 1; 
 j = 1;  //i, j 分别表示当前子序列的首尾，并保证其中至多有两个不同整数 
 while ((j <= n) && (a[j] == a[i])) 
  j++; 
 cur1 = a[i]; 
 cur2 = a[j];  count1 =     (1)    ; //（3 分） 
 count2 = 1; 
 ans_length = j - i + 1; 
 while (j < n) { 
  j++; 
  if (a[j] == cur1) 
   count1++; 
  else if (a[j] == cur2) 
   count2++; 
  else {    if (a[j - 1] ==     (2)    ) { //（3 分） 
    while (count2 > 0) { 
     if (a[i] == cur1) 
      count1--; 
     else 
      count2--; 
     i++; 
    } 
    cur2 = a[j]; 
    count2 = 1; 
   } 
   else { 
    while (count1 > 0) { 
     if (a[i] == cur1)           (3)    ; //（2 分） 
     else           (4)    ; //（2 分） 
     i++;  
    }         (5)    ;   //（3 分） 
    count1 = 1; 
   } 
  } 
  if (ans_length < j - i + 1) { 
   ans_length = j - i + 1; 
   ans_start = i; 
   ans_end = j; 
  } 
 } 
 for (i = ans_start; i <= ans_end; i++) 
  printf("%d ", a[i]); 
 return 0; 
} 