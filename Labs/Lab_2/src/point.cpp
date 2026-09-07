#include "../include/point.hpp"
#include <cmath>

//Constructor
points::Point::Point(int X, int Y, points::Point* closestPoint)
{
    this->x = X;
    this->y = Y;
    this->nearestPoint = closestPoint;
}
//Destructor
points::Point::~Point()
{
}

//Getters
int points::Point::getX()
{
    return this->x;
}

int points::Point::getY()
{
    return this->y;
}

points::Point* points::Point::getNearestPoint()
{
    return this->nearestPoint;
}

points::Point* points::Point::calcNearestPoint(Point* pointList[], unsigned long arrSize)
{
    double maxDist = 283; // Distance between (-100, -100) and (100, 100), roughly
    double currDist;
    Point* nearest;
    for (int i = 0; i < arrSize; i++)
    {
        currDist = this->distPoints(*pointList[i]);
        if (currDist <= maxDist)
        {
            nearest = pointList[i];
            maxDist = currDist; // Limit to prevent getting further away
        }
        else
            continue;
    }
    return nearest;
}

//Setters
void points::Point::setX(int newVal)
{
    this->x = newVal;
}

void points::Point::setY(int newVal)
{
    this->y = newVal;
}

void points::Point::setNearestPoint(Point* newNearestPoint)
{
    this->nearestPoint = newNearestPoint;
}

double points::Point::distPoints(Point& point)
{
    return sqrt(pow((point.x - this->x), 2) + pow((point.y - this->y), 2));
}