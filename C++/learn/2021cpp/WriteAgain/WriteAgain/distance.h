//
//  distance.hpp
//  WriteAgain
//
//  Created by MacKenia on 2021/4/23.
//

#ifndef distance_h
#define distance_h

class Point
{
private:
     int xPos, yPos;
public:
    friend double distance(Point&,Point&);
    Point(int = 0, int = 0);
};
#endif /* distance_hpp */


