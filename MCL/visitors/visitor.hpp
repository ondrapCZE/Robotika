#ifndef VISITOR_H
#define VISITOR_H

namespace mcl{

//! Basic particle visitor
template <class AdvancedParticle>
class Visitor{
public:
	//! Virtual destructor can be overwritten in derived class
    virtual ~Visitor(){};
    //! Visit particle
	virtual void visit(AdvancedParticle *particle) = 0;
};

}
#endif
