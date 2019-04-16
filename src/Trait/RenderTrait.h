#ifndef _TRAIT_RENDER_H_
#define _TRAIT_RENDER_H_

#include <SDL2/SDL.h>

#include "Trait.h"
#include "../Server/RenderServer.h"

#include "../Vec.h"

namespace BromineEngine {

class RenderTrait : public Trait<RenderTrait, RenderServer> {
friend class RenderServer;
protected:
	Vec2f _position;

public:
	RenderTrait(const NodeID owner);
	RenderTrait(const NodeID owner, const Vec2f& position);
	
	~RenderTrait();

	Vec2f& position();
	virtual void render();
};

}

#endif // _TRAIT_RENDER_H_