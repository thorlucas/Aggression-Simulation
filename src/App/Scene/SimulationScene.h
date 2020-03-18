#pragma once

#include <Bromine/Scene/Scene.h>
#include <vector>

using namespace BromineEngine;

class SimulationScene : public Scene {
public:
	SimulationScene();
	~SimulationScene();

	void loadScene();
};