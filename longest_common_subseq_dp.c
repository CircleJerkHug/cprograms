#include<stdio.h>
#include<string.h>
#define maxn 100100
int max(int a,int b)
{
        return (a>b)?a:b;
}
void LongestCommonSubsequence(char S[],char T[],int m,int n)
{
    /* Starting the index from 1 for our convinience (avoids handling special cases for negative indices) */
        int L[m+1][n+1]; 
  
   /* Following steps build L[m+1][n+1] in bottom up fashion. Note 
      that L[i][j] contains length of LCS of X[0..i-1] and Y[0..j-1] */
   for (int i=0; i<=m; i++) 
   { 
     for (int j=0; j<=n; j++) 
     { 
       if (i == 0 || j == 0) 
         L[i][j] = 0; 
       else if (S[i-1] == T[j-1]) 
         L[i][j] = L[i-1][j-1] + 1; 
       else
         L[i][j] = max(L[i-1][j], L[i][j-1]); 
     } 
   } 
        
	   int index = L[m][n]; 
	  
	   // Create a character array to store the lcs string 
	   char lcs[index+1]; 
	   lcs[index] = ' '; // Set the terminating character 
	  
	   // Start from the right-most-bottom-most corner and 
	   // one by one store characters in lcs[] 
	    int i = m, j = n; 
	   while (i > 0 && j > 0) 
	   { 
	      // If current character in X[] and Y are same, then 
	      // current character is part of LCS 
	      if (S[i-1] == T[j-1]) 
	      { 
	          lcs[index-1] = S[i-1]; // Put current character in result 
	          i--; j--; index--;     // reduce values of i, j and index 
	      } 
	  
	      // If not same, then find the larger of two and 
	      // go in the direction of larger value 
	      else if (L[i-1][j] > L[i][j-1]) 
	         i--; 
	      else
	         j--; 
   } 		
  
   // Print the lcs 
   printf("%s\n",lcs);
   printf("%d\n",L[m][n]);

}
int main()
{
        char S[maxn],T[maxn];/* S,T are two strings for which we have to find the longest common sub sequence. */
		int m,n;
        printf("Enter the first string:\n");
        scanf("%s",S); 
        m=strlen(S);
        printf("Enter the second string:\n");
        scanf("%s",T);
        n=strlen(T);
        LongestCommonSubsequence(S,T,m,n);
        return 0;
}