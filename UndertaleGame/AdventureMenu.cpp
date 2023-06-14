#include "pch.h"
#include "AdventureMenu.h"

#include "Inventory.h"
#include "SoundManager.h"
#include "ResourceManager.h"

AdventureMenu::AdventureMenu(FightPlayer* pFightPlayer, ResourceManager* pResourceManager)
	:
	m_pPlayer(pFightPlayer),
	m_pResourceManager(pResourceManager)
{
}

AdventureMenu::~AdventureMenu()
{

}


void AdventureMenu::Draw()
{
    switch (m_MenuState)
    {
    case(MenuState::menu):
        m_pResourceManager->m_MiscTextures[3]->Draw();
        glPushMatrix();
        glScalef(0.7f, 0.7f, 1);
        m_pResourceManager->m_TextTextures[1]->Draw(Point2f(60, 380));
        m_pResourceManager->m_TextTextures[0]->Draw(Point2f(60, 560));
    	glPopMatrix();
    	break;
    case(MenuState::inventory):

        m_pResourceManager->m_InteractableTextTextures[0]->Draw();
        for (int y{}; y < m_AmountOfTextLocations; ++y)
        {
            int pageStartIndex = m_CurrentItemPage * m_AmountOfTextLocations;
            m_pPlayer->GetInv()->GetItemText(pageStartIndex + y)->Draw(m_TextLocations[y].ToPoint2f());
        }
        m_pResourceManager->m_MiscTextures[0]->Draw((m_TextLocations[m_CurrentSelectedOption] - Vector2f{ 15, -5 }).ToPoint2f());
        break;
    }
}

MenuState AdventureMenu::GetMenuState()
{
    return m_MenuState;
}

void AdventureMenu::SetMenuState(MenuState menuState)
{
    m_MenuState = menuState;
}

void AdventureMenu::OnButtonUp(const SDL_KeyboardEvent& e)
{
    switch (m_MenuState)
    {
    case (MenuState::menu):
        switch (e.keysym.sym)
        {
        case (SDLK_ESCAPE):
        case(SDLK_x):
            SoundManager::GetInstance().PlaySoundEffect("select");
            break;
        case (SDLK_RETURN):
        case(SDLK_z):
            m_MenuState = MenuState::inventory;
            SoundManager::GetInstance().PlaySoundEffect("select");
            break;
        }
        break;
    case(MenuState::inventory):
            switch (e.keysym.sym)
            {
            case (SDLK_ESCAPE):
            case(SDLK_x):
                SoundManager::GetInstance().PlaySoundEffect("select");
                m_MenuState = MenuState::menu;
                break;

            case (SDLK_w):
            case (SDLK_UP):
                if (m_CurrentSelectedOption >= 2)
                {
                    m_CurrentSelectedOption -= 2;

                    SoundManager::GetInstance().PlaySoundEffect("changeSelection");
                }
                break;
            case (SDLK_s):
            case (SDLK_DOWN):
                if (m_CurrentSelectedOption <= 1)
                {
                    m_CurrentSelectedOption += 2;

                    SoundManager::GetInstance().PlaySoundEffect("changeSelection");
                }
                break;
            case (SDLK_a):
            case (SDLK_LEFT):
                if (m_CurrentSelectedOption > 0)
                {
                    --m_CurrentSelectedOption;

                    SoundManager::GetInstance().PlaySoundEffect("changeSelection");
                }
                else if (m_CurrentItemPage > 0)
                {
                    m_CurrentSelectedOption = 0;
                    m_CurrentItemPage--;

                    SoundManager::GetInstance().PlaySoundEffect("changeSelection");
                }
                break;
            case (SDLK_d):
            case (SDLK_RIGHT):
                if (m_CurrentSelectedOption < m_AmountOfTextLocations)
                {
                    ++m_CurrentSelectedOption;

                    SoundManager::GetInstance().PlaySoundEffect("changeSelection");
                }
                if (m_CurrentSelectedOption == m_AmountOfTextLocations && m_CurrentItemPage < (m_pPlayer->GetInv()->GetCurrentItemAmount() - 1) / 4) {
                    m_CurrentSelectedOption = 0;
                    m_CurrentItemPage++;

                    SoundManager::GetInstance().PlaySoundEffect("changeSelection");
                }
                else if (m_CurrentSelectedOption == m_AmountOfTextLocations)
                {
                    --m_CurrentSelectedOption;

                    SoundManager::GetInstance().PlaySoundEffect("changeSelection");
                }
                break;
            case (SDLK_RETURN):
            case(SDLK_z):
                if (m_pPlayer->GetHealth() != m_pPlayer->GetMaxHealth()) {
                    const int selectedItemItteration{ m_CurrentItemPage * m_AmountOfTextLocations + m_CurrentSelectedOption };
                    m_pPlayer->Damage(-(m_pPlayer->GetInv()->GetItemValue(selectedItemItteration)));
                    if (m_pPlayer->GetHealth() > m_pPlayer->GetMaxHealth())
                    {
                        m_pPlayer->Damage(m_pPlayer->GetMaxHealth() - m_pPlayer->GetHealth());
                    }
                    m_pPlayer->GetInv()->DeleteItem(selectedItemItteration);
                    SoundManager::GetInstance().PlaySoundEffect("heal");
                }
                break;
            }
            break;
    }
}
