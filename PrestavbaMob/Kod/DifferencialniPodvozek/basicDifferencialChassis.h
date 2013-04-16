#ifndef BASIC_DIFFERENCIAL_CHASSIS_H
#define BASIC_DIFFERENCIAL_CHASSIS_H

#include <stdint.h>
#include "../../../obecne/basic.h"

/*!
 * struct Speed serve for storage speed on the left and right wheels.
 */
struct Speed{
	double left;
	double right;

	Speed(double left=0, double right=0) : left(left), right(right){};

	Speed operator-(Speed ob2){
		Speed temp(left - ob2.left, right - ob2.right);
		return temp;
	};
};

/*!
 * struct DifferencialChassisParameters serve for setting basic parameters.
 */
struct DifferencialChassisParameters{
	double wheelbase;
	double wheelRadius;
	unsigned int wheelTics;
};

struct Encoders{
	long int left;
	long int right;

	Encoders(long int left = 0, long  int right = 0) : left(left), right(right) {};

	Encoders operator+(Encoders ob2){
		Encoders temp(left + ob2.left, right + ob2.right);
		return temp;
	};
	
	Encoders operator-(Encoders ob2){
		Encoders temp(left - ob2.left, right - ob2.right);
		return temp;
	};
}; 

struct PIValue{
	int P;
	int I;

	double integralPartLeft;
	double integralPartRight;

	PIValue(int P=90, int I=0): P(P), I(I), integralPartLeft(0), integralPartRight(0)  {};
};

/*!
 * struct DifferencialChassis is virtual class which is necessary to define.
 */
class BasicDifferencialChassis{
public:
	//! A pure virtual member.
    /*!
		\param differencialChassisParameters an struct DifferencialChassisParameters argument.
    */
	virtual void setDifferencialChassisParameters(DifferencialChassisParameters differencialChassisParameters)=0;
	//! A pure virtual member.
    /*!
		\param speed an struct Speed argument.
    */
	virtual void setSpeed(Speed speed)=0;
	//! A pure virtual member.
    /*!
		\return actual state of the chassis
	*/
	virtual State getState()=0;
};

#endif
