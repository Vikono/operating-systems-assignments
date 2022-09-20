#include <stdio.h>
#include <math.h>
struct Point{
	double x, y;
};
double distance(struct Point p1, struct Point p2){
	return sqrt(pow((p1.x-p2.x),2)+pow((p1.y-p2.y),2));}
double area(struct Point p1, struct Point p2, struct Point p3){
	double ab=distance(p1,p2);
	double bc=distance(p2,p3);
	double ac=distance(p3,p1);
	double p=(ab+bc+ac)/2;
	return sqrt(p*(p-ac)*(p-bc)*(p-ab));
	}
int main(){
	struct Point A={.x=2.5, .y=6}, B={.x=1, .y=2.2}, C={.x=10, .y=6};
	double areaTr=area(A,B,C);
	double distanceAB=distance(A,B);
	printf("%f\n", distanceAB);
	printf("%f", areaTr);
}
