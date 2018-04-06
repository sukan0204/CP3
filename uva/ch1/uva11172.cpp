// supereasy
// relational operators

#include <iostream>

using namespace std;

int main()
{
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        int a, b;
        scanf("%d %d", &a, &b);
        if(a==b)
            printf("=\n");
        if(a<b)
            printf("<\n");
        if(a>b)
            printf(">\n");
    }
   
   return 0;
}