/*!
*  \brief     Encoder reader class
*  \author    Ondrej Pilat (pilat.ondrej@seznam.cz, ondrap.cz)
*  \version   0.1
*  \date      2013
*/

#ifndef ENCODER_H
#define ENCODER_H

//! Values from encoder counters
struct Encoders{
	int left;
	int right;
};

//! Describe general encoder reader for encoders on two wheels.
/*! Used as separation layer for communication with encoders unit.
 */
class EncoderReader {
public:
	//! Virtual destructor can be overwritten by derived class.
	virtual ~EncoderReader(){};
	//! Return encoder resolution (number of ticks for one turn).
	virtual unsigned int getEncodersResolution()=0;
	//! Return actual ticks count on encoders.
	virtual Encoders getEncodersState()=0;
	//! Return ticks count difference between last call and actual.
	virtual Encoders getChangeOfEncoders()=0;
};

#endif
