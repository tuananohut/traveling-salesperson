#include <iostream>
#include <random>
#include <vector>

#include <SFML/Graphics.hpp>

float generateRandomNumber(float min, float max);

void swap(std::vector<sf::Vector2f>& cities, int i, int j);
sf::Vector2f calcDistance(std::vector<sf::Vector2f>& cities);

int main()
{
    sf::ContextSettings settings;
    settings.antialiasingLevel = 10;
    sf::RenderWindow window(sf::VideoMode(800, 600), "Traveling Salesperson", sf::Style::Default, settings);
    window.setFramerateLimit(60);

    std::vector<sf::Vector2f> cities = {};
    sf::Vector2f v;

    std::vector<sf::CircleShape> circles;

    int totalCities = 4;

    sf::Vector2f recordDistance;

    std::vector<sf::Vector2f> bestEver;

    for (int i = 0; i < totalCities; i++)
    {
        v = { generateRandomNumber(0.f, 800.f), generateRandomNumber(0.f, 600.f) };
        cities.push_back(v);
    }

    auto d = calcDistance(cities);
    recordDistance = d;
    bestEver = cities;

    for (int i = 0; i < cities.size(); i++)
    {
        circles.push_back(sf::CircleShape(10));
        circles[i].setPosition(cities[i].x, cities[i].y);
    }

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }
        }

        window.clear();

        float i = generateRandomNumber(0, cities.size());
        float j = generateRandomNumber(0, cities.size());


        for (int i = 0; i < cities.size(); i++)
        {
            circles[i].setPosition(cities[i].x, cities[i].y);
            window.draw(circles[i]);
        }

        for (int i = 0; i < cities.size() - 1; i++)
        {
            sf::Vertex line[] =
            {
                sf::Vertex(sf::Vector2f(circles[i].getPosition().x + circles[i].getRadius(), circles[i].getPosition().y + circles[i].getRadius())),
                sf::Vertex(sf::Vector2f(circles[i + 1].getPosition().x + circles[i].getRadius(), circles[i + 1].getPosition().y + circles[i].getRadius()))
            };

            window.draw(line, 2, sf::Lines);
        }

        for (int i = 0; i < cities.size() - 1; i++)
        {
            sf::Vertex line[] =
            {
                sf::Vertex(sf::Vector2f(bestEver[i].x + circles[i].getRadius(), bestEver[i].y + circles[i].getRadius())),
                sf::Vertex(sf::Vector2f(bestEver[i + 1].x + circles[i].getRadius(), bestEver[i + 1].y + circles[i].getRadius()))
            };

            line->color = sf::Color::Red;

            window.draw(line, 2, sf::Lines);
        }

        swap(cities, i, j);

        d = calcDistance(cities);
        if (d.x < recordDistance.x && d.y < recordDistance.y)
        {
            recordDistance = d;
            bestEver = cities;
            std::cout << recordDistance.x << " " << recordDistance.y << std::endl;
        }

        window.display();
    }

    return 0;
}

float generateRandomNumber(float min, float max)
{
    static std::random_device rd;
    static std::mt19937 gen(rd());
    std::uniform_real_distribution<float> dis(min, max);
    return dis(gen);
}

void swap(std::vector<sf::Vector2f>& cities, int i, int j)
{
    auto temp = cities[i];
    cities[i] = cities[j];
    cities[j] = temp;
}

sf::Vector2f calcDistance(std::vector<sf::Vector2f>& cities)
{
    sf::Vector2f sum = { 0,0 };

    for (int i = 0; i < cities.size() - 1; i++)
    {
        sf::Vector2f d = { cities[i].x - cities[i + 1].x, cities[i].y - cities[i + 1].y };
        sum += d;
    }

    return sum;
}