#include "Menu.hpp"

Menu::Menu(sf::Vector2i* s):
_background("backgroundMenu.png")
{
    _window_size=s;
}

Menu::~Menu()
{
   delete _window_size;
}
void Menu::onEvent(sf::Event& event){
    for(unsigned int i=0;i<obs.size();i++)
        obs[i]->onEvent(event);
}
void Menu::update(sf::Time& tps){
    updateObs(tps);
}

void Menu::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    target.draw(_background);
    for(unsigned int i=0;i<obs.size();i++)
       target.draw(*obs[i],states);
}


void Menu::updateObs(sf::Time& tps){
    for(unsigned int i=0;i<obs.size();i++)
        obs[i]->update();
}
