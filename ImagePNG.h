#ifndef IMAGEPNG_H
#define IMAGEPNG_H

#include <string>
#include "ImageBuilder.h"

class ImagePNG : public ImageBuilder {
	public:
	virtual void save(std::string name);
};

#endif
