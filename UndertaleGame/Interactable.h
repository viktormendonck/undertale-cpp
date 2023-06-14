#pragma once
#include "CollisionBox.h"


class Player;

class Interactable
{
public:
	Interactable() = delete;
	Interactable(const CollisionBox& collision, bool isSollid);
	virtual ~Interactable() =default;


	virtual void Update(float deltaTime, Player* player) = 0;
	virtual void Draw(const Vector2f& camera) const = 0;
	virtual void ButtonUpManager(const SDL_KeyboardEvent& e) = 0;

	bool IsActivated();

	std::vector<CollisionBox> GetCollisionBox() const;
	bool IsSollid() const;

protected:
	virtual void OnInteract() = 0;
	std::vector<CollisionBox> m_CollisionBoxes;
	bool m_IsSollid{};
	bool m_HasInteracted{};
	bool m_IsActivated{};
};

