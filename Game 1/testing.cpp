#include <iostream>
#include <filesystem>
#include <SFML/Graphics.hpp>

int main()
{
    sf::RenderWindow window(sf::VideoMode({1920,1080}), "Testing Window");

    std::filesystem::path cwd = std::filesystem::current_path();
    std::string carurl = (cwd / "images/rectangleblue1.png").string();

    sf::Texture cartex;
    if (!cartex.loadFromFile(carurl))
    {
        std::cout << "Failed to load texture\n";
        return -1;
    }

    sf::Sprite carspr(cartex);

    window.setFramerateLimit(60);

   
carspr.rotate(sf::degrees(45.f));
carspr.rotate(sf::degrees(-45.f));
carspr.setPosition({400.f, 400.f});
sf::FloatRect bounds = carspr.getLocalBounds();

carspr.setOrigin({
    bounds.size.x / 2.f,
    bounds.size.y / 2.f
});
while (window.isOpen())
{
    

    while (const std::optional event = window.pollEvent())
    {
        if (event->is<sf::Event::Closed>())
            window.close();
    }

    window.clear();
    window.draw(carspr);
    window.display();
}



    return 0;
}