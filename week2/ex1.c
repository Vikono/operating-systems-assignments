#include <stdio.h>
#include <limits.h>
#include <float.h>
int main(){
	int a;
	unsigned short int b;
	long int c;
	float d;
	double e;
	a=INT_MAX;
	b=USHRT_MAX;
	c=LONG_MAX;
	d=FLT_MAX;
	e=DBL_MAX;
	printf("%s%ld%s%d\n", "Parameters of INT: size = ", sizeof(a), ", value = ", a);
	printf("%s%ld%s%d\n", "Parameters of UNSIGNED SHORT INT: size = ", sizeof(b), ", value = ", b);
	printf("%s%ld%s%ld\n", "Parameters of LONG INT: size = ", sizeof(c), ", value = ", c);
	printf("%s%ld%s%f\n", "Parameters of FLOAT: size = ", sizeof(d), ", value = ", d);
	printf("%s%ld%s%f", "Parameters of DOUBLE: size = ", sizeof(e), ", value = ", e);
}
	
