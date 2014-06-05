#ifndef PARTICLE_2D_MAP_H
#define PARTICLE_2D_MAP_H

#include "particle2D.hpp"
#include "../../Map/OccupancyMap/occupancy_map.hpp"

namespace mcl {

template<class Map, class Updater>
class Particle2DMap: public Particle2D {
	Map map_;
public:
	Particle2DMap(const double &x = 0, const double &y = 0,
			const double &theta = 0, const Map &map = Map());

	Particle2DMap(const Particle2DMap& particle);
	Particle2DMap& operator=(const Particle2DMap& particle);

	map::MapInterface& map();
	void updateMap(Updater& updater);
	void accept(Visitor<Particle2DMap> &visitor);
};

template<class Map, class Updater>
Particle2DMap<Map, Updater>::Particle2DMap(const double &x, const double &y,
		const double &theta, const Map &map) :
		Particle2D(x, y, theta), map_(map) {
}

template<class Map, class Updater>
Particle2DMap<Map, Updater>::Particle2DMap(const Particle2DMap& particle) :
		Particle2D(particle), map_(particle.map_) {

}

template<class Map, class Updater>
Particle2DMap<Map,Updater>& Particle2DMap<Map, Updater>::operator=(
		const Particle2DMap& particle) {

	Particle2D::operator=(particle);
	map_ = particle.map_;
	return *this;
}

template<class Map, class Updater>
map::MapInterface& Particle2DMap<Map, Updater>::map() {
	return map_;
}

template<class Map, class Updater>
void Particle2DMap<Map, Updater>::updateMap(Updater& updater) {
	updater.update(map_);
}

template<class Map, class Updater>
void Particle2DMap<Map, Updater>::accept(Visitor<Particle2DMap> &visitor) {
	visitor.visit(this);
}

}

#endif
