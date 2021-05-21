//
//  basicshape.h
//  196_7
//
//  Created by MacKenia on 2021/5/21.
//

#ifndef basicshape_h
#define basicshape_h

class basicshape
{
private:
    double area;
public:
    double &getarea(){return area;};
    virtual double calcarea()=0;
};

class circle:public basicshape
{
private:
    int centerx;
    int centery;
    double radius;
public:
    circle();
    int getcenterx(){return centerx;};
    int getcentery(){return centery;};
    double calcarea(){return  getarea()=3.14*radius*radius;};
};

class rectangle:public basicshape
{
private:
    long int width;
    long int length;
public:
    long int getwidth(){return width;};
    long int getlength(){return length;};
    double calcarea(){return getarea()=1.0*width*length;}
};

#endif /* basicshape_h */
