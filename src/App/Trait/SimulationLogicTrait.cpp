#include "SimulationLogicTrait.h"
#include <Bromine/Server/NodeServer.h>
#include <Bromine/Trait/SpriteRenderTrait.h>
#include <algorithm>

DEFINE_TRAIT(SimulationLogicTrait, LogicTrait)

SimulationLogicTrait::SimulationLogicTrait(const NodeID owner) : CONSTRUCT_TRAIT(SimulationLogicTrait, LogicTrait) {
	dayIsDone = false;
	bookTexture = Bromine::server<RenderServer>().loadTexture("Book.png");
}
SimulationLogicTrait::~SimulationLogicTrait() {}

void SimulationLogicTrait::initialize() {
	resetFood();
}

void SimulationLogicTrait::update(double delta) {}

void SimulationLogicTrait::resetFood() {
	int cap = 10 - foodNodes.size();

	for (int i = 0; i < cap; ++i) {
		Node& foodNode = Bromine::node()
			->position(Vec2f(rand() % windowWidth, rand() % windowHeight))
			->trait<SpriteRenderTrait>(bookTexture, Vec2f(2, 2))
	 	->create();

	 	owner().addChild(foodNode);
	 	foodNodes.push_back(&foodNode);
	}
	Bromine::log(Logger::INFO, "Size of food nodes: %lu", foodNodes.size());
}

void SimulationLogicTrait::eatFood(Node* foodNode) {
	foodNode->position() = Vec2f(-100, 0); // FOR NOW SINCE WE CANT REMOVE LOL
	// std::remove(foodNodes.begin(), foodNodes.end(), foodNode);
	foodNodes.erase(std::find(foodNodes.begin(), foodNodes.end(), foodNode));

	if (foodNodes.size() == 0) {
		resetFood();
	}
}