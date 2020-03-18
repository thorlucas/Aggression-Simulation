#pragma once

#include <Bromine/Server/RenderServer.h>
#include <Bromine/Trait/LogicTrait.h>
#include <vector>

using namespace BromineEngine;

class SimulationLogicTrait : public LogicTrait {
DECLARE_TRAIT(LogicServer)
private:
	bool dayIsDone;
	ResourceID bookTexture;

	void resetFood();

protected:
	SimulationLogicTrait(const NodeID _owner);
	void update(double delta) override;

	virtual void initialize() override;

public:
	~SimulationLogicTrait();

	std::vector<Node*> creatureNodes;
	std::vector<Node*> foodNodes;

	void eatFood(Node* foodNode);
};