#pragma once
#include "Interactable.h"
#include "Texture.h"
//TODO:: cmon, finish this shit you dumbass
class RockInteract final : public Interactable
{
public:
	RockInteract(const Rectf& collisionRect, Texture* pRockTexture,const Rectf& buttonRect,const CollisionBox& barrierRect,Texture* pBarierTexture);

	void Update(float deltaTime, Player* player);
	void Draw(const Vector2f& camera) const;
	void ButtonUpManager(const SDL_KeyboardEvent& e);

private:
	void OnInteract();
	void PushCollisionBox(CollisionBox collision);

	Texture* m_pRockTexture{};
	Texture* m_pBarrierTexture{};

	bool m_DeactivateBarrier{};

	CollisionBox m_BarrierRect{};
	Rectf m_buttonRect{};

	Rectf m_PlayerPushRect{};
	float m_RockMinX{};
	float m_RockMaxX{};
	float m_RockPushSpeed{50};



};

