#ifndef IMAGEPNG_H
#define IMAGEPNG_H

#include <string>
#include "ImageBuilder.h"

class ImagePNG : public ImageBuilder {
	void save(std::string name);
};

#endif
