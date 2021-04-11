//
//  Float.h
//  114_3.cpp
//
//  Created by MacKenia on 2021/4/7.
//

#ifndef Float_h
#define Float_h
class Float
{
private:
    float *p;
    int Count;
public:
    Float(int count);
    ~Float();
    void insert();
    void check();
};

#endif /* Float_h */
