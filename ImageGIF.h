#ifndef IMAGEGIF_H
#define IMAGEGIF_H

#include <string>
#include "ImageBuilder.h"

class ImageGIF : public ImageBuilder {
	public:
	virtual void save(std::string name);
};

#endif
