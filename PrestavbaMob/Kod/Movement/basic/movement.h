#ifndef MOVEMENT_H
#define MOVEMENT_H

#include "../../DifferencialniPodvozek/mobDifferencialChassis.h"

//! Robot rotation Direction
enum Direction{
	LEFT,
	RIGHT
};

//! Straight line and rotation on spot movement for differential chassis.
/*!	All calls are blocking. It means that function will hold execution until robot ends desire movement.
 */
class Movement {
private:
	BasicDifferentialChassis* chassis;
	State finalState;
public:
	//! Set differential chassis
	Movement(BasicDifferentialChassis* chassis);

	//! Chassis will follow circle which is specified by input parameters.
	/*!
	 * \param diameter circle diameter in meters
	 * \param angle robot will move length on circle according to this angle in rad and diameter (d = angle*diameter)
	 * \param circleDirection robot will follow circle on RIGHT or LEFT
	 */
	void moveCircle(const double &diameter, const double &angle, 
	const Direction &circleDirection);
	
	//! Robot will drive straight line with length equal meter in meters
	/*!
	 * \param meter straight line length
	 */
	void moveStraight(const double &meter);

	//! Rotate on spot
	/*!
	 * \param angle rotation size. Use right handed rotation.
	 */
	void rotate(const double &angle);
};

#endif
