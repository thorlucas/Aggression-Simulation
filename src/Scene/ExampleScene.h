#ifndef _EXAMPLE_SCENE_H_
#define _EXAMPLE_SCENE_H_

#include "Scene.h"

namespace BromineEngine {

class ExampleScene : public Scene {
public:
	ExampleScene();
	~ExampleScene();

	void loadScene();
};

}

#endif // _EXAMPLE_SCENE_H_