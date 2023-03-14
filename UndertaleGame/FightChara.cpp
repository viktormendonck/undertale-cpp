#include "pch.h"
#include "FightChara.h"

#include "AnimatedSprite.h"
#include "Texture.h"

FightChara::FightChara(Texture* heartTexture, AnimatedSprite* heartAnims, float speed, int startHealth, Vector2f pos)
	:
	m_pHeartTexture{ heartTexture },
	m_pHeartAnims{ heartAnims },
	m_Hp{ startHealth },
	m_Speed{ speed },
	m_pos{ pos }
{
}

void FightChara::Draw()
{
	switch (m_State)
	{
	case (FightCharaState::base):
		m_pHeartTexture->Draw(m_pos.ToPoint2f());
		break;
	case (FightCharaState::running):
		m_pHeartAnims->SetAnimation("flee");
		m_pHeartAnims->Draw(m_pos);

		break;
	case (FightCharaState::dying):
		m_pHeartAnims->SetAnimation("dying");
		m_pHeartAnims->Draw(m_pos);
		break;
	}
}

void FightChara::Update(float deltaTime)
{

}

void FightChara::DamageChara(int damage)
{
	m_Hp -= damage;
}

void FightChara::SetFightCharaState(FightCharaState state)
{
	m_State = state;
}

void FightChara::StartFight(Fight* pFight)
{
	m_pFight = pFight;
}

void FightChara::ButtonDownManager(const SDL_KeyboardEvent& e)
{
	switch (e.keysym.sym)
	{
	case (SDLK_w):
		m_Velocity.y = m_Speed;
		break;
	case (SDLK_a):
		m_Velocity.x = -m_Speed;
		break;
	case (SDLK_s):
		m_Velocity.y = -m_Speed;
		break;
	case (SDLK_d):
		m_Velocity.x = m_Speed;
		break;
	}
}

void FightChara::ButtonUpManager(const SDL_KeyboardEvent& e)
{
	switch (e.keysym.sym)
	{
	case (SDLK_w):
		m_Velocity.y = 0;
		break;
	case (SDLK_a):
		m_Velocity.x = 0;
		break;
	case (SDLK_s):
		m_Velocity.y = 0;
		break;
	case (SDLK_d):
		m_Velocity.x = 0;
		break;
	}
}



