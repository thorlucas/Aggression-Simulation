#include "SimulationLogicTrait.h"
#include <Bromine/Server/NodeServer.h>
#include <Bromine/Trait/SpriteRenderTrait.h>
#include <algorithm>

DEFINE_TRAIT(SimulationLogicTrait, LogicTrait)

SimulationLogicTrait::SimulationLogicTrait(const NodeID owner) : CONSTRUCT_TRAIT(SimulationLogicTrait, LogicTrait) {
	dayIsDone = false;
	bookTexture = Bromine::server<RenderServer>().loadTexture("Book.png");
	foodTimer = 0;
}
SimulationLogicTrait::~SimulationLogicTrait() {}

void SimulationLogicTrait::initialize() {
	for (int i = 0; i < 10; ++i) {
		addFood();
	}
}

void SimulationLogicTrait::update(double delta) {
	foodTimer += delta;

	if (foodTimer >= 0.2f) {
		if (rand() % 8 == 0) {
			addFood();
		}
		foodTimer = 0.0f;
	}
}

void SimulationLogicTrait::addFood() {
	Node& foodNode = Bromine::node()
		.position(Vec2f(rand() % (windowWidth - 128) + 64, rand() % (windowHeight - 128) + 64))
		.trait<SpriteRenderTrait>(bookTexture, Vec2f(2, 2))
 	.create();

 	owner().addChild(foodNode);
 	foodNodes.push_back(&foodNode);
	Bromine::log(Logger::INFO, "Size of food nodes: %lu", foodNodes.size());
}

void SimulationLogicTrait::eatFood(Node* foodNode) {
	foodNode->destroy();
	foodNodes.erase(std::find(foodNodes.begin(), foodNodes.end(), foodNode));
}