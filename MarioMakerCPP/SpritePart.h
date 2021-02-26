#pragma once
#include "Sprite.h"
#include "SFML/System/Vector2.hpp"

namespace universal {
	class SpritePart {
	private:
		const Sprite& m_parent;

	public:
		SpritePart(const Sprite& parent);

		const Sprite& getSprite() const;
	};
}
