#include "Assignment2StudentImpl.h"
#include <iostream>

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
    Vector3 vectorTowardsTarget = target - forward;

    // We want to check if this vector is going upwards, and we can do that with the dot product with the up vector
    float dotProduct = CalculateDotProduct(up, target);

    // If the dot product is positive, the vector towards the target is going upward, which means target is above object 
    return dotProduct > 0;
}

// This function takes three 3D points as input that represent the vertices of a triangle and calculates the normal vector of the triangle.
// It returns a Vector3 object representing the normal vector of the triangle.
// Students are expected to implement the logic to calculate the normal vector of the triangle using the provided input points.
Vector3 Assignment2StudentImpl::GetTriangleNormal(const Vector3& ptA, const Vector3& ptB, const Vector3& ptC) const
{
    // To get the normal vector of the triangle, we just need to calculate the vectors of any 2 edges of the triangle and find its normalized cross product
    Vector3 firstEdge = ptB - ptA;
    Vector3 secondEdge = ptC - ptA;

    // Calculating cross product without trig
    Vector3 crossVector = CalculateCrossProduct(firstEdge, secondEdge);

    // Normalize
    float vectorMagnitude = sqrt(CalculateVectorSquaredMagnitude(crossVector));
    if (vectorMagnitude)
        crossVector = MultiplyVectorAndScalar(crossVector, 1 / vectorMagnitude);

    return crossVector;
}

// This function takes three points forming a triangle and a target point as input.
// It calculates and returns the minimum distance between the target point and the triangle.
// Students are expected to implement the logic to calculate the distance between the target point and the triangle using 
// the provided input.
float Assignment2StudentImpl::GetDistanceFromTriangle(const Vector3& ptA, const Vector3& ptB, const Vector3& ptC, const Vector3& target) const
{
    // Calculate the triangles normal vector
    Vector3 triangleNormalVector = GetTriangleNormal(ptA, ptB, ptC);

    // Get the distance from the target to a point of the triangle
    Vector3 triangleToTarget = target - ptA;

    // The dot product between that distance and the triangle normal returns minimum distance
    float projectionDistance = CalculateDotProduct(triangleToTarget, triangleNormalVector);

    // Return abs value of projection because we cannot have negative distance
    return fabs(projectionDistance);
}

// This function takes two 3D vectors as input: planeNormal and vectorToReflect.
// It calculates the reflection of vectorToReflect about the plane with planeNormal as its normal.
// The function returns a new vector which is the reflected vector.
// Students are expected to implement the logic to calculate the reflection of the given vector about the plane with 
// the given normal vector.
Vector3 Assignment2StudentImpl::Reflect(const Vector3& planeNormal, const Vector3& vectorToReflect) const
{
    // We will be utilizing the reflection formula r = d - 2(d*n)n where d*n is the dot product between d and n

    // Calculate the dot product of the vectorToReflect and the planeNormal, then multiply by 2
    float dotProduct = CalculateDotProduct(planeNormal, vectorToReflect) * 2.0f;

    Vector3 multipliedVector = MultiplyVectorAndScalar(planeNormal, dotProduct);

    return vectorToReflect - multipliedVector;
}

// This function takes a point on a plane, a normal vector to the plane, a center point of a sphere and its radius as input.
// It checks if the sphere is completely inside the plane or not.
// Students are expected to implement the logic to check if all points on the surface of the sphere lie on the same side of the plane.
// If all points lie on the same side of the plane, the function should return true, otherwise false.
bool Assignment2StudentImpl::IsSphereInsidePlane(const Vector3& ptOnPlane, const Vector3& planeNormal, const Vector3& circleCenter, float circleRadius) const
{
    // Get the vector from the point on the plane to the center of the circle
    Vector3 vectorFromPointToCircle = circleCenter - ptOnPlane;

    // This projection distance tells us where the center of the circle is in respect to the plane
    float planeProjection = CalculateDotProduct(planeNormal, vectorFromPointToCircle);

    // We add the circle radius to the projection to check if circle is within the plane
    // If sum is 0, that means the circle is on the plane, and also within in
    // If sum is positive, circle is above, and therefore inside the plane
    // If sum is negative, the circle is below/outside of the plane
    return planeProjection + circleRadius >= 0;
}

float Assignment2StudentImpl::CalculateVectorSquaredMagnitude(const Vector3& vector) const
{
    return (vector.x * vector.x) + (vector.y * vector.y) + (vector.z * vector.z);
}

float Assignment2StudentImpl::CalculateDotProduct(const Vector3& vectorOne, const Vector3& vectorTwo) const
{
    return vectorOne.x * vectorTwo.x + vectorOne.y * vectorTwo.y + vectorOne.z * vectorTwo.z;
}

Vector3 Assignment2StudentImpl::CalculateCrossProduct(const Vector3& vectorOne, const Vector3& vectorTwo) const
{
    return { (vectorOne.y * vectorTwo.z) - (vectorOne.z * vectorTwo.y), (vectorOne.z * vectorTwo.x) - (vectorOne.x * vectorTwo.z), (vectorOne.x * vectorTwo.y) - (vectorOne.y * vectorTwo.x) };
}

Vector3 Assignment2StudentImpl::MultiplyVectorAndScalar(const Vector3& vector, const float scalar) const
{
    return { vector.x * scalar, vector.y * scalar, vector.z * scalar };
}
