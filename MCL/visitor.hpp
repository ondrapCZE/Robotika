#ifndef VISITOR_H
#define VISITOR_H

namespace mcl{

template <class AdvancedParticle>
class Visitor{
public:
	virtual void visit(AdvancedParticle *particle) = 0;
};

}
#endif
