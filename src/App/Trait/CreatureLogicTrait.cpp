#include "CreatureLogicTrait.h"

DEFINE_TRAIT(CreatureLogicTrait, LogicTrait)

CreatureLogicTrait::CreatureLogicTrait(const NodeID owner, SimulationLogicTrait& simulation) : CONSTRUCT_TRAIT(CreatureLogicTrait, LogicTrait),
	ownerPosition(CreatureLogicTrait::owner().position()),
	simulation(simulation) {
	targetFood = nullptr;
}
CreatureLogicTrait::~CreatureLogicTrait() {}

void CreatureLogicTrait::initialize() {}

void CreatureLogicTrait::update(double delta) {
	if (targetFood == nullptr || std::find(simulation.foodNodes.begin(), simulation.foodNodes.end(), targetFood) == simulation.foodNodes.end()) {
		if (simulation.foodNodes.size() > 0)
			targetFood = simulation.foodNodes.at(rand() % (simulation.foodNodes.size()));
		else
			return;
	}

	Vec2f distVec = targetFood->position() - Vec2f(0, 32) - ownerPosition;
	Vec2f direction = static_cast<float>(delta * 50.f) * glm::normalize(distVec);
	if (glm::length(distVec) < glm::length(direction)) {
		simulation.eatFood(targetFood);
		targetFood = nullptr;
	} else {
		ownerPosition += direction;
	}
}
