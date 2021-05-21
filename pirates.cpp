#include "pirates.h"
#include <string>
#include <fstream>
#include <list>
#include <sstream>

Pirates::Pirates()
{
    std::fstream file("../init_files/pirates.txt", std::ios::in);
    std::string one_pirate;
    if (!file)
            std::cout<< "kek";

    int x, y;
    for (int i = 0; i < 9; i++)
    {
        std::list<Vector> List;
        std::getline(file, one_pirate);
        
        //std::cout << one_pirate;
        int j;

        std::stringstream ss;
        ss << one_pirate;
        
        for (j = 0; j < 10; j += 2)
        {
            ss >> x;
            ss >> y;
            //Vector(double(x), double(y)).print_vector();
            /*x = one_pirate[j];
            y = one_pirate[j+1];*/
            List.push_back(Vector(double(x), double(y)));
        }

        trajectories[i] = List;
        head_costs[i] = one_pirate[j];
        x = one_pirate[j+1];
        y = one_pirate[j+2];
        velocities[i] = Vector(x, y);
        x = one_pirate[j+3];
        y = one_pirate[j+4];
        radius_vectors[i] = Vector(x, y);
    }
    
    file.close();
    
    for (int i = 0; i < 9; i++)
    {
        DrawPirateShip dps(trajectories[i], head_costs[i], velocities[i], radius_vectors[i]);
        pirateships[i] = dps;
        
    }
    
    //sf::Texture pirateTexture;
    //pirateTexture.loadFromFile("../images/ships/ship2.png");

    pirateTexture.loadFromFile("../images/ships/ship2.png");
    sf::Sprite pirateSprite(pirateTexture);
        
    for (int i = 0; i < 9; i++)
    {
        sprites[i] = pirateSprite;
    }
    
}

void Pirates::Draw(sf::RenderWindow& window, double time, double constant, double x, double y)
{
    for (int i = 0; i < 9; i++)
    {
        Vector start;
        
        /*for (auto it = trajectories[i].begin(); it != trajectories[i].end(); ++it)
        {
            it->print_vector();
        }*/
        (pirateships[i]).MoveShip(time, constant);
        sprites[i].setPosition((pirateships[i]).GetRect().left, (pirateships[i].GetRect().top));

        if ((pirateships[i].GetRect().left > (x - 840) || pirateships[i].GetRect().left < (x + 840)) && (pirateships[i].GetRect().top > (y - 525) || pirateships[i].GetRect().top < (y + 525)) && pirateships[i].IsAlive())
            window.draw(sprites[i]);
    }
}
