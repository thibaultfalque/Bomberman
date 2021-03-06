#ifndef PERSONNAGE_HPP
#define PERSONNAGE_HPP
#include "BonusMalus/BonusMalus.hpp"
#include "header.hpp"
#include "General.hpp"
#include "Game/Map.hpp"
#include "BombManager.hpp"
class BonusMalus;
class Map;
class BombManager;
class Personnage : public sf::Drawable
{
    public:
        Personnage(sf::Vector2f position,int numPersonnage, Map & __map,BombManager & bm);

        virtual ~Personnage();
        void setVitesse(float vitesse);
        bool setnbBombeMax(int nbBombeMax);
        void setnbBombe(int nb);
        void addBombe();
        void removeBombe();
        void setdegatsBombes(int degatsBombes);
        void setLauncher(bool launcher);
        void setPusher(bool pusher);
        sf::Vector2f getPos();
        float getVitesse();
        int getnbBombeMax();
        int getnbBombe();
        int getdegatsBombes();
        void addBonusMalus(BonusMalus b);
        virtual void update(sf::Time& tps);
        virtual void onEvent(sf::Event & event);
        void moveTo(sf::Vector2f newPos);
        bool canMoveTo(sf::Vector2i newPos);
        virtual void putBomb();
        sf::FloatRect getHitBox(sf::Vector2f newPos);
        sf::FloatRect getHitBox(sf::Vector2i newPos);
        sf::FloatRect getHitBox();
        int getType();

    protected:

        virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
        void graphicUpdate(sf::Time& tps);
        sf::Vector2f pos, vitesse;
        int nbBombeMax, nbBombe, degatsBombes;
        vector<BonusMalus> bonusMalus;
        //vector<Bomb*> _bomb;
        bool launcher, pusher;

        int etapePas;
        int direction;
        //sf::Clock timerPas;
        //sf::Clock deltaUpdate;

        float tempsTotalPas;
        float tempsTotalDelta;

        sf::Sprite _sprites[4][9];
        Map & _map;

        BombManager& _bombeManager;

        int numType;

        float pixelParSecondes;

};

#endif // PERSONNAGE_H
