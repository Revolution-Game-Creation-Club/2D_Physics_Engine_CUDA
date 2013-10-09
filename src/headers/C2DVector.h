#ifndef C2DVECTOR_H
#define C2DVECTOR_H

#include <iostream>

/**
* C2DVector manages two-dimensional vectors of floats and defines all the common Vector operations.
*/
class C2DVector
{
public:
	C2DVector():x(0.0f),y(0.0f){}
	C2DVector( float _x, float _y ):x(_x),y(_y){}
	C2DVector( const C2DVector& _vec );

	C2DVector& operator=( const C2DVector& rhs);
	C2DVector& operator*=( const float k );
	C2DVector& operator+=( const C2DVector& rhs);
	C2DVector& operator-=( const C2DVector& rhs);

	float GetSquaredLength() const;
	float GetLenght() const;
	float GetApproxInverseSqrt() const;
	float ScalarProduct( const C2DVector& ) const;

	friend C2DVector operator*( const float k, const C2DVector& _vec );
	friend C2DVector operator*( const C2DVector& _vec, const float k );

	friend C2DVector operator+( const C2DVector& _first, const C2DVector& _second);
	friend C2DVector operator-( const C2DVector& _first, const C2DVector& _second);

	friend std::ostream& operator<< ( std::ostream& out, const C2DVector& vec);

	float x;
	float y;

private:
	//Helper function crazy inverse square root approximation...see http://en.wikipedia.org/wiki/Fast_inverse_square_root
	float Q_rsqrt( float number ) const;
};
#endif