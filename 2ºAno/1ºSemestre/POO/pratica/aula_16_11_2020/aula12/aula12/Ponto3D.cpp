#include "ponto3D.h"

ostream& operator<<(ostream& os, const Ponto3D &p) {
	os << "(" << p.getX() << ", " << p.getY() << ", " << p.getZ() << ")";

	return os;
}
