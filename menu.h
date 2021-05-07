void menu(sf::RenderWindow& window)
{
    sf::Texture menuTexture1, menuTexture2, menuTexture3, manualTexture, menuBackground;
    menuTexture1.loadFromFile("../images/menu/newgame.png");
    menuTexture2.loadFromFile("../images/menu/exit.png");
    menuTexture3.loadFromFile("../images/menu/loadgame.png");
    manualTexture.loadFromFile("../images/menu/manual.png");
    menuBackground.loadFromFile("../images/menu/menu.png");

    sf::Sprite menu1(menuTexture1), menu2(menuTexture2), menu3(menuTexture3), manual(manualTexture), background(menuBackground);

    bool isMenu = 1;
    int menuNum = 0;

    background.setPosition(0, 0);
    menu1.setPosition(0, 0);
    menu2.setPosition(0, 0);
    menu3.setPosition(0, 0);
    manual.setPosition(0, 0);

    while (isMenu)
    {
        menu1.setColor(sf::Color::White);
        menu2.setColor(sf::Color::White);
        menuNum = 0;
        window.clear();

        if (sf::IntRect(630, 590, 439, 109).contains(sf::Mouse::getPosition(window)))
         {
             menu1.setColor(sf::Color::Red);
             menuNum = 1;
         }
         if (sf::IntRect(630, 870, 439, 109).contains(sf::Mouse::getPosition(window)))
         {
             menu2.setColor(sf::Color::Red);
             menuNum = 2;
         }
         
         if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
         {
             if (menuNum == 1)
             {
                 isMenu = false;
             }
             if (menuNum == 2)
             {
                 window.close();
                 isMenu = false;
             }
         }

         window.draw(background);
         window.draw(menu1);
         window.draw(menu2);
         window.draw(menu3);
         window.draw(manual);
         window.display();
    }
}
