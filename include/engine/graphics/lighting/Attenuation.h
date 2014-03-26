#ifndef ATTENUATION_H
#define ATTENUATION_H

struct Attenuation {
	float constant = 1.0;
	float linear = 0.0;
	float quadratic = 0.0;
};

#endif // ATTENUATION_H