#pragma once

#include <Bromine/Trait/LogicTrait.h>
#include <Bromine/Scene/Scene.h>
#include <glm/gtx/rotate_vector.hpp>
#include "SimulationLogicTrait.h"

using namespace BromineEngine;

class CreatureLogicTrait : public LogicTrait {
DECLARE_TRAIT(LogicServer)
private:
	Vec2f& ownerPosition;
	SimulationLogicTrait& simulation;
	Node* targetFood;
	Node* alertNode;

	bool rotating;
	bool rotatingDirection;
	Vec2f randomWalkDirection;

	float food;

protected:
	CreatureLogicTrait(const NodeID _owner, SimulationLogicTrait& simulation);
	void update(double delta) override;

	virtual void initialize() override;

public:
	~CreatureLogicTrait();
};