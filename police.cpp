#include "police.h"
#include <string>
#include <sstream>
#include <fstream>

Police::Police()
{
    std::fstream file("../init_files/police.txt", std::ios::in);
    std::string one_cop;
    if (!file)
        std::cout<<"kek";

    int x, y;
    for (int i = 0; i < 9; i++)
    {
        std::getline(file, one_cop);
        std::stringstream ss;
        ss << one_cop;

        ss >> x;
        ss >> y;

        radius_vectors[i] = Vector(double(x),double(y));
    }

    file.close();

    for (int i = 0; i < 9; i ++)
    {
        DrawPoliceShip dpl(radius_vectors[i], 0, 0);
        policeships[i] = dpl;
    }

    policeTexture.loadFromFile("../images/ships/police.png");
    sf::Sprite policeSprite(policeTexture);

    for (int i = 0; i < 9; i++)
    {
        sprites[i] = policeSprite;
    }
    
    for (int i = 0; i < 9; i ++)
    {
        sprites[i].setPosition(radius_vectors[i].x_pos(), radius_vectors[i].y_pos());
    }
}

void Police::Draw(sf::RenderWindow& window, double x, double y)
{
    for (int i = 0; i < 9; i ++)
    {
        if ( (radius_vectors[i].x_pos() > (x - 840) || radius_vectors[i].x_pos() < (x +840)) || (radius_vectors[i].y_pos() > (y - 525) || radius_vectors[i].y_pos() < (y + 525)))
            window.draw(sprites[i]);
    } 
}

