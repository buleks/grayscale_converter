#ifndef IMAGEJPG_H
#define IMAGEJPG_H

#include <string>
#include "ImageBuilder.h"

class ImageJPG : public ImageBuilder {
	public:
	virtual void save(std::string name);
};

#endif
