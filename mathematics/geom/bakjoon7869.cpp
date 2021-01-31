#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
struct circle{
    double x,y;
    double radius;
};
class cross_area{
private:
    circle c1,c2;
    double circle_dis;
public:
    cross_area(){
        std::cin >> c1.x >> c1.y >> c1.radius;
        std::cin >> c2.x >> c2.y >> c2.radius;
        circle_dis=hypot(c2.x-c1.x,c2.y-c1.y);
    }
    /*
    제2 코사인 법칙 a*a+b*b-2ab*cosC=c*c
    (a*a+b*b-c*c)/2a*b=cosC
    */
    double cal_double_angle(double& a,double& b,double& c){
        double cos=(a*a+b*b-c*c)/(2*a*b);
        double sin=sqrt(1-cos*cos);
        return 2*sin*cos;
    }
    void cal_triangle(){
        if(circle_dis>=c1.radius+c2.radius){
            printf("%.3lf",0.0);
            return ;
        }
        else if(fabs(c1.radius-c2.radius)>=circle_dis){
            double m = min(c1.radius,c2.radius);
            double PI= acos(-1);
            double sol=  m*m*PI;
            printf("%.3lf",sol);
            return ;
        }
        double tri1=c1.radius*c1.radius*cal_double_angle(c1.radius,circle_dis,c2.radius)/2.0;
        double tri2=c2.radius*c2.radius*cal_double_angle(c2.radius,circle_dis,c1.radius)/2.0;
        double th1=acos((c1.radius*c1.radius+circle_dis*circle_dis-c2.radius*c2.radius)/(2*c1.radius*circle_dis));
        double th2=acos((c2.radius*c2.radius+circle_dis*circle_dis-c1.radius*c1.radius)/(2*c2.radius*circle_dis));

        double sol = c1.radius*c1.radius*th1+c2.radius*c2.radius*th2-tri1-tri2; 

        printf("%.3lf",sol);

    }

};
int main(){
    cross_area ca;
    ca.cal_triangle();

    return 0;
}