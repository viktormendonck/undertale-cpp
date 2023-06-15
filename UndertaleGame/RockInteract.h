#pragma once
#include "Interactable.h"
#include "Texture.h"

class RockInteract final : public Interactable
{
public:
	RockInteract(const Rectf& collisionRect, Texture* pRockTexture,const Rectf& buttonRect,const CollisionBox& barrierRect,Texture* pBarrierTexture);

	void Update(float deltaTime, Player* player);
	void Draw(const Vector2f& camera) const;
	void ButtonUpManager(const SDL_KeyboardEvent& e);

private:
	void OnInteract();
	void PushCollisionBox(CollisionBox collision);

	const Texture* m_pRockTexture{};
	const Texture* m_pBarrierTexture{};

	bool m_DeactivateBarrier{};

	CollisionBox m_BarrierRect{};
	const Rectf m_ButtonRect{};

	Rectf m_PlayerPushRect{};
	const float m_RockMinX{};
	const float m_RockMaxX{};
	const float m_RockPushSpeed{50};



};

