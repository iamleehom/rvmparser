#include "LinAlg.h"


Mat3f inverse(const Mat3f& M)
{
  const auto & c0 = M.cols[0];
  const auto & c1 = M.cols[1];
  const auto & c2 = M.cols[2];

  auto r0 = cross(c1, c2);
  auto r1 = cross(c2, c0);
  auto r2 = cross(c0, c1);

  auto invDet = 1.f / dot(r2, c2);

  return Mat3f(invDet * r0.x, invDet * r0.y, invDet*r0.z,
               invDet * r1.x, invDet * r1.y, invDet*r1.z,
               invDet * r2.x, invDet * r2.y, invDet*r2.z);
}

Mat3f mul(const Mat3f& A, const Mat3f& B)
{
  auto A00 = A.cols[0].x;  auto A10 = A.cols[0].y;  auto A20 = A.cols[0].z;
  auto A01 = A.cols[1].x;  auto A11 = A.cols[1].y;  auto A21 = A.cols[1].z;
  auto A02 = A.cols[2].x;  auto A12 = A.cols[2].y;  auto A22 = A.cols[2].z;

  auto B00 = B.cols[0].x;  auto B10 = B.cols[0].y;  auto B20 = B.cols[0].z;
  auto B01 = B.cols[1].x;  auto B11 = B.cols[1].y;  auto B21 = B.cols[1].z;
  auto B02 = B.cols[2].x;  auto B12 = B.cols[2].y;  auto B22 = B.cols[2].z;

  return Mat3f(A00 * B00 + A01 * B10 + A02 * B20,
               A00 * B01 + A01 * B11 + A02 * B21,
               A00 * B02 + A01 * B12 + A02 * B22,

               A10 * B00 + A11 * B10 + A12 * B20,
               A10 * B01 + A11 * B11 + A12 * B21,
               A10 * B02 + A11 * B12 + A12 * B22,

               A20 * B00 + A21 * B10 + A22 * B20,
               A20 * B01 + A21 * B11 + A22 * B21,
               A20 * B02 + A21 * B12 + A22 * B22);
}
