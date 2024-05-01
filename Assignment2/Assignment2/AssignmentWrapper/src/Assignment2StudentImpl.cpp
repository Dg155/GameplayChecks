#include "Assignment2StudentImpl.h"

// This function takes a 3D vector as input and checks if its magnitude is zero or not.
// It returns a boolean value indicating whether the magnitude of the vector is zero or not.
// Students are expected to implement the logic to calculate the magnitude of the given vector and compare it with zero.
bool Assignment2StudentImpl::IsVectorMagnitudeZero(const Vector3& vectorToTest) const
{
    // Only the only vector with magnitude of 0 is the origin
    return ((vectorToTest.x == 0) && (vectorToTest.y == 0) && (vectorToTest.z == 0));
}

// This function takes two circles as input, specified by their center points and radii, and checks if they are touching or not.
// It returns a boolean value indicating whether the circles are touching or not.
// Students are expected to implement the logic to check if the distance between the centers of the two circles touch or not.
bool Assignment2StudentImpl::DoCirclesTouch(const Vector3& centerA, float radiusA, const Vector3& centerB, float radiusB) const
{
    float squaredDistanceBetweenXCoordinate = (centerB.x - centerA.x) * (centerB.x - centerA.x);
    float squaredDistanceBetweenYCoordinate = (centerB.y - centerA.y) * (centerB.y - centerA.y);
    float squaredDistanceBetweenZCoordinate = (centerB.z - centerA.z) * (centerB.z - centerA.z);
    // Square the sum of radii so we can use the squared distance between the points
    float squaredSumOfRadii = (radiusA + radiusB) * (radiusA + radiusB);
    return (squaredDistanceBetweenXCoordinate + squaredDistanceBetweenYCoordinate + squaredDistanceBetweenZCoordinate) <= squaredSumOfRadii;
}

// This function takes in four 3D vectors as input: forward, up, right, and target.
// It determines whether the target point is above or below the calling object based on the orientation of the object.
// Students are expected to implement the logic to calculate the position of the target relative to the object based on its 
// forward, up, and right vectors.
// The function should return a boolean value indicating whether the target is above the object (true) or not (false).
bool Assignment2StudentImpl::IsTargetAboveMe(const Vector3& forward, const Vector3& up, const Vector3& right, const Vector3& target) const
{
    UNUSED_ARG(right);
    // By subtracting the forward vector from the targets vector, we get a vector that goes from the object towards the target
    Vector3 vectorTowardsTarget = { target.x - forward.x, target.y - forward.y, target.z - forward.z };

    // We want to check if this vector is going upwards, and we can do that with the dot product with the up vector
    float dotProduct = up.x * vectorTowardsTarget.x + up.y * vectorTowardsTarget.y + up.z * vectorTowardsTarget.z;

    // If the dot product is positive, the vector towards the target is going upward, which means target is above object 
    return dotProduct > 0;
}

// This function takes three 3D points as input that represent the vertices of a triangle and calculates the normal vector of the triangle.
// It returns a Vector3 object representing the normal vector of the triangle.
// Students are expected to implement the logic to calculate the normal vector of the triangle using the provided input points.
Vector3 Assignment2StudentImpl::GetTriangleNormal(const Vector3& ptA, const Vector3& ptB, const Vector3& ptC) const
{
    UNUSED_ARG(ptA);
    UNUSED_ARG(ptB);
    UNUSED_ARG(ptC);
    return {};
}

// This function takes three points forming a triangle and a target point as input.
// It calculates and returns the minimum distance between the target point and the triangle.
// Students are expected to implement the logic to calculate the distance between the target point and the triangle using 
// the provided input.
float Assignment2StudentImpl::GetDistanceFromTriangle(const Vector3& ptA, const Vector3& ptB, const Vector3& ptC, const Vector3& target) const
{
    UNUSED_ARG(ptA);
    UNUSED_ARG(ptB);
    UNUSED_ARG(ptC);
    UNUSED_ARG(target);
    return 0;
}

// This function takes two 3D vectors as input: planeNormal and vectorToReflect.
// It calculates the reflection of vectorToReflect about the plane with planeNormal as its normal.
// The function returns a new vector which is the reflected vector.
// Students are expected to implement the logic to calculate the reflection of the given vector about the plane with 
// the given normal vector.
Vector3 Assignment2StudentImpl::Reflect(const Vector3& planeNormal, const Vector3& vectorToReflect) const
{
    UNUSED_ARG(planeNormal);
    UNUSED_ARG(vectorToReflect);
    return {};
}

// This function takes a point on a plane, a normal vector to the plane, a center point of a sphere and its radius as input.
// It checks if the sphere is completely inside the plane or not.
// Students are expected to implement the logic to check if all points on the surface of the sphere lie on the same side of the plane.
// If all points lie on the same side of the plane, the function should return true, otherwise false.
bool Assignment2StudentImpl::IsSphereInsidePlane(const Vector3& ptOnPlane, const Vector3& planeNormal, const Vector3& circleCenter, float circleRadius) const
{
    UNUSED_ARG(ptOnPlane);
    UNUSED_ARG(planeNormal);
    UNUSED_ARG(circleCenter);
    UNUSED_ARG(circleRadius);
    return false;
}
