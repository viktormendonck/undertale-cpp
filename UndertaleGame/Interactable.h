#pragma once
#include "CollisionBox.h"


class Player;

class Interactable
{
public:
	Interactable() = delete;
	Interactable(const CollisionBox& collision, bool isSolid);
	virtual ~Interactable() = default;

	Interactable(const Interactable& other) = delete;
	Interactable& operator=(const Interactable& other) = delete;
	Interactable(Interactable&& other) = delete;
	Interactable& operator=(Interactable&& other) = delete;

	virtual void Update(float deltaTime, Player* player) = 0;
	virtual void Draw(const Vector2f& camera) const = 0;
	virtual void ButtonUpManager(const SDL_KeyboardEvent& e) = 0;

	bool IsActivated();

	std::vector<CollisionBox> GetCollisionBox() const;
	bool IsSolid() const;

protected:
	virtual void OnInteract() = 0;
	std::vector<CollisionBox> m_CollisionBoxes;
	bool m_IsSolid{};
	bool m_HasInteracted{};
	bool m_IsActivated{};
};

