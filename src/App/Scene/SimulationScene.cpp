#include "SimulationScene.h"

#include <App/Trait/CreatureLogicTrait.h>
#include <App/Trait/SimulationLogicTrait.h>
#include <Bromine/Trait/SpriteRenderTrait.h>
#include <Bromine/Node/Node.h>
#include <Bromine/Server/NodeServer.h>
#include <Bromine/Server/RenderServer.h>
#include <Bromine/Bromine.h>

SimulationScene::SimulationScene() {
	Node& rootNodeRef = Bromine::node(rootNode);

	Node& simulationNode = Bromine::node()
		->trait<SimulationLogicTrait>()
	->create();
	rootNodeRef.addChild(simulationNode);

	SimulationLogicTrait& simulation = simulationNode.getTrait<SimulationLogicTrait>();

	ResourceID slimeTexture = Bromine::server<RenderServer>().loadTexture("Slime.png");
	
	for (int i = 0; i < 10; ++i) {
		Node& creatureNode = Bromine::node()
			->position(Vec2f(rand() % windowWidth, rand() % windowHeight))
			->trait<SpriteRenderTrait>(slimeTexture, Vec2f(2, 2))
			->trait<CreatureLogicTrait>(simulation)
		->create();

		simulation.creatureNodes.push_back(&creatureNode);
		rootNodeRef.addChild(creatureNode);
	}
	
	Bromine::log(Logger::DEBUG, "Creating simulation scene: %p", this);
}

SimulationScene::~SimulationScene() {}

void SimulationScene::loadScene() {
	Scene::loadScene();
}