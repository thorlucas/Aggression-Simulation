#pragma once

#include <Bromine/Trait/LogicTrait.h>
#include <Bromine/Scene/Scene.h>
#include "SimulationLogicTrait.h"

using namespace BromineEngine;

class CreatureLogicTrait : public LogicTrait {
DECLARE_TRAIT(LogicServer)
private:
	Vec2f& ownerPosition;
	SimulationLogicTrait& simulation;
	Node* targetFood;

protected:
	CreatureLogicTrait(const NodeID _owner, SimulationLogicTrait& simulation);
	void update(double delta) override;

	virtual void initialize() override;

public:
	~CreatureLogicTrait();
};