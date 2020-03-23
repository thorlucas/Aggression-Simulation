#include "CreatureLogicTrait.h"
#include <Bromine/Server/NodeServer.h>
#include <Bromine/Trait/SpriteRenderTrait.h>

DEFINE_TRAIT(CreatureLogicTrait, LogicTrait)

CreatureLogicTrait::CreatureLogicTrait(const NodeID owner, SimulationLogicTrait& simulation) : CONSTRUCT_TRAIT(CreatureLogicTrait, LogicTrait),
	ownerPosition(CreatureLogicTrait::owner().position()),
	simulation(simulation) {
	targetFood = nullptr;
	randomWalkDirection = glm::rotate(Vec2f(1.0, 0.0), static_cast<float>((rand() % static_cast<int>(2.0 * 100.0 * M_PI)) / 100.0));

	Node& n = Bromine::node()
		.trait<SpriteRenderTrait>(Bromine::instance().renderServer.loadTexture("Alert.png"), Vec2f(0.6, 0.6))
		.position(Vec2f(0, 0))
	.create();
	alertNode = &n;
	alertNode->disable();

	CreatureLogicTrait::owner().addChild(n);

	food = 100.f;
}
CreatureLogicTrait::~CreatureLogicTrait() {}

void CreatureLogicTrait::initialize() {}

void CreatureLogicTrait::update(double delta) {
	food -= 10.f * delta;
	if (food <= 0) {
		owner().destroy();
		return;
	}

	if (targetFood != nullptr) {
		if (std::find(simulation.foodNodes.begin(), simulation.foodNodes.end(), targetFood) == simulation.foodNodes.end()) {
			alertNode->disable();
			targetFood = nullptr;
		}
	}

	if (targetFood == nullptr) {
		std::vector<Node*> viableFoodNodes;
		for (auto& foodNode : simulation.foodNodes) {
			if (glm::length(foodNode->position() - Vec2f(0, 32) - ownerPosition) < 200.f) {
				viableFoodNodes.push_back(foodNode);
			}
		}

		if (viableFoodNodes.size() != 0) {
			targetFood = viableFoodNodes.at(rand() % viableFoodNodes.size());
			alertNode->enable();
		}
	}

	if (targetFood == nullptr) {
		if (!rotating) {
			if (rand() % 60 == 0) {
				rotating = true;
				rotatingDirection = rand() % 2;
			}
		} else {
			if (rand() % 20 == 0) rotating = false;
		}

		if (rotating) {
			float angle = static_cast<float>(M_PI * delta) * (rotatingDirection ? 1.0 : -1.0);
			randomWalkDirection = glm::normalize(glm::rotate(randomWalkDirection, angle));
		}

		ownerPosition += randomWalkDirection * static_cast<float>(delta * 50.f);
	} else {
		Vec2f distVec = targetFood->position() - Vec2f(0, 32) - ownerPosition;
		Vec2f direction = static_cast<float>(delta * 100.f) * glm::normalize(distVec);
		if (glm::length(distVec) < glm::length(direction)) {
			simulation.eatFood(targetFood);
			targetFood = nullptr;
			food += 100.f;
			alertNode->disable();
		} else {
			ownerPosition += direction;
		}
	}

	if (ownerPosition.x < 0 || ownerPosition.x > windowWidth - 32 || ownerPosition.y < -64 || ownerPosition.y > windowHeight - 64) {
		randomWalkDirection *= -1.f;
		if (ownerPosition.x < 0) ownerPosition.x = 1.f;
		if (ownerPosition.y < -64) ownerPosition.y = -63.f;
		if (ownerPosition.x > windowWidth - 32) ownerPosition.x = windowWidth - 1.f - 32;
		if (ownerPosition.y > windowHeight - 64) ownerPosition.y = windowHeight - 1.f - 64;
	}

	if (food > 200)
	
}
