# include <math.h>

#define PI 3.14159265

void uqFromXqref(float x, float y, float z, float dx, float dy, float dz,
					float ox, float oy, float oz, float dox float doy, float doz,
					float xref, float yref, float zref, float dxref, float dyref, float dzref,
					float oxref, float oyref, float ozref, float doxref, float doyref, float dozref,
					float *omegas) {
	
	// Get desired pitch and roll angles based on position
	oyref = K1oy*(xref - x - K2oy*dx);
	oxref = K1ox*(yref - y - K2ox*dy);
	
	// Thrust and Torque controllers
	thrust = (Kpz*(zref - z) + Kdz*(dzref - dz) + M*g)/(cos(ox)*cos(oy));
	torquex = Kpox*(oxref - ox) + Kdox*(doxref - dox);
	torquey = Kpoy*(oyref - oy) + Kdoy*(doyref - doy);
	torquez = Kpoz*(ozref - oz) + Kdoz*(dozref - doz);
	
	/*
	[T tx ty tz]' = A*[w1sq w2sq w3sq w4sq]'
	A = 
	[    b,   b,   b,    b]
	[    0, b*l,   0, -b*l]
	[ -b*l,   0, b*l,    0]
	[    k,  -k,   k,   -k]
	
	[w1sq w2sq w3sq w4sq]' = inv(A)*[T tx ty tz]'
	inv(A) =
	[ 1/(4*b),          0, -1/(2*b*l),  1/(4*k)]
	[ 1/(4*b),  1/(2*b*l),          0, -1/(4*k)]
	[ 1/(4*b),          0,  1/(2*b*l),  1/(4*k)]
	[ 1/(4*b), -1/(2*b*l),          0, -1/(4*k)]
	*/
	// Finds omega squared values
	groundfactor = (1 - (pow(Rrotor,2)/(16*pow(z,2))));
	omega1sq = groundfactor*((thrust/(4*b)) - (torquey/(2*b*L)) + (torquez/(4*k)));
	omega2sq = groundfactor*((thrust/(4*b)) + (torquex/(2*b*L)) - (torquez/(4*k)));
	omega3sq = groundfactor*((thrust/(4*b)) + (torquey/(2*b*L)) + (torquez/(4*k)));
	omega4sq = groundfactor*((thrust/(4*b)) - (torquex/(2*b*L)) - (torquez/(4*k)));
	
	omega1 = sqrt(abs(omega1sq));
	omega2 = sqrt(abs(omega2sq));
	omega3 = sqrt(abs(omega3sq));
	omega4 = sqrt(abs(oemga4sq));
	omegas[0] = omega1;
	omegas[1] = omega2;
	omegas[2] = omega3;
	omegas[3] = omega4;
}





