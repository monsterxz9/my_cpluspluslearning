#include <stdio.h>

int main() {
int x,y,z;
x=y=z=0;
++x ||++y && ++z;
printf("%d",y);
}
