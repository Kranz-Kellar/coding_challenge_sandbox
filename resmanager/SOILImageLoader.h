#include "ImageLoader.h"
#include <SOIL/SOIL.h>
#include "../Logger.h"

namespace Erbium {

	class SOILImageLoader : public ImageLoader {

	public:
		SOILImageLoader() {};
		std::shared_ptr<Image> LoadImage(std::string path) override;
	};

}