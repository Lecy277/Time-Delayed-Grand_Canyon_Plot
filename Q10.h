#ifndef TRIANGLES_H_INCLUDED
#define TRIANGLES_H_INCLUDED

using namespace std;
class Triangle
{
private:
    double PointXL, PointYL, PointZ, PointYLL;
    double PointXL2, PointYL2, PointZ2, PointYLL2;
    double PointXR, PointYR, PointRZ, PointYRR;
    double PointXR2, PointYR2, PointRZ2, PointYRR2;
public:
    ///default constructor and destructor to set initialization values
    Triangle(){PointXL=0.0; PointYL=0.00; PointZ=75.00;PointYLL=15.0;
               PointXL2=15.00; PointYL2=0.00; PointZ2=75.00; PointYLL2=15.0;
               PointXR=75.0; PointYR=0.00; PointRZ=75.00;PointYRR=15.0;
               PointXR2=60.00; PointYR2=0.00; PointRZ2=75.00; PointYRR2=15.0;}
    ~Triangle(){}
    double XL(){return PointXL;}
    double YL(){return PointYL;}
    double Z(){return PointZ;}
    double YLL(){return PointYLL;}
    double XL2(){return PointXL2;}
    double YL2(){return PointYL2;}
    double Z2(){return PointZ2;}
    double YLL2(){return PointYLL2;}
    double XR(){return PointXR;}
    double YR(){return PointYR;}
    double RZ(){return PointRZ;}
    double YRR(){return PointYRR;}
    double XR2(){return PointXR2;}
    double YR2(){return PointYR2;}
    double RZ2(){return PointRZ2;}
    double YRR2(){return PointYRR2;}

};

#endif // TRIANGLES_H_INCLUDED

