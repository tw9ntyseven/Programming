//
//  main.cpp
//  30
//
//  Created by Admin on 27.12.2020.
//

#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <string>

struct Item;

typedef std::vector<Item> LootBox;

Item generateLoot();

struct Coin
{
    uint16_t count;

    Coin(uint16_t count) : count(count)
    {
    }
};

enum class Element { FIRE, WATER, EARTH, AIR };

struct Rune
{
    uint16_t level;
    Element element;
    
    Rune(uint16_t level, Element element) :
        level(level),
        element(element)
    {
    }
};

struct Weapon
{
    uint16_t damage;
    uint16_t critical;
    uint16_t durability;

    Weapon(uint16_t damage, uint16_t critical, uint16_t durability) :
        damage(damage),
        critical(critical),
        durability(durability)
    {
    }
};

struct Armor
{
    uint16_t guard;
    uint16_t durability;

    Armor(uint16_t guard, uint16_t durability) :
        guard(guard),
        durability(durability)
    {
    }
};

enum class ItemType {
    СOIN,
    RUNE,
    WEAPON,
    ARMOR
};

union itemType {
    Coin coin;
    Rune rune;
    Weapon weapon;
    Armor armor;

    itemType() {};
};

struct Item
{
    ItemType itemTypeEnum;
    itemType itemTypeUnion;

    Item& operator++()
    {
        Item tmp = generateLoot();
        this->itemTypeEnum = tmp.itemTypeEnum;
        this->itemTypeUnion = tmp.itemTypeUnion;
    }
};

std::ostream& operator<<(std::ostream& out, const Item& it)
{
    if (sizeof(Coin) == sizeof(it.itemTypeUnion))
    {
        out << it.itemTypeUnion.coin.count;
        return out;
    }

    if (sizeof(Rune) == sizeof(it.itemTypeUnion))
    {
        out << "Rune of ";

        if (it.itemTypeUnion.rune.element == Element::AIR)
            out << "air " << it.itemTypeUnion.rune.level;

        if (it.itemTypeUnion.rune.element == Element::EARTH)
            out << "earth " << it.itemTypeUnion.rune.level;

        if (it.itemTypeUnion.rune.element == Element::FIRE)
            out << "fire " << it.itemTypeUnion.rune.level;

        if (it.itemTypeUnion.rune.element == Element::WATER)
            out << "water " << it.itemTypeUnion.rune.level;
    
        out << " lvl";
    }

    if (sizeof(Weapon) == sizeof(it.itemTypeUnion))
    {
        if (it.itemTypeUnion.weapon.critical)
            out << "Demon Slayer";
        else
            out << "God Killer";

        return out;
    }

    if (sizeof(Armor) == sizeof(it.itemTypeUnion))
    {
        out << "Bronezhiletka";

        return out;
    }


    return out;
}

std::ostream& operator<<(std::ostream& out, const LootBox& boxes)
{
    for (auto box : boxes)
    {
        std::cout << box;
        std::cout << '\n';
    }
    return out;
}

LootBox& operator<<(LootBox lhs, Item rhs)
{
    lhs.push_back(rhs);
    return lhs;
}

Item generateLoot()
{
    const int countItems = 16;
    std::vector<Item> gen(countItems);
    std::vector<int> genChance(countItems);

    // 1
    gen[0].itemTypeEnum = ItemType::СOIN;
    gen[0].itemTypeUnion.coin = Coin(1000);
    
    genChance[0] = 50 * 100;

    // 2
    gen[1].itemTypeEnum = ItemType::RUNE;
    gen[1].itemTypeUnion.rune = Rune(1, Element::FIRE);
    
    genChance[1] = 6 * 100;

    // 3
    gen[2].itemTypeEnum = ItemType::RUNE;
    gen[2].itemTypeUnion.rune = Rune(1, Element::WATER);
    
    genChance[2] = 13 * 100;

    // 4
    gen[3].itemTypeEnum = ItemType::RUNE;
    gen[3].itemTypeUnion.rune = Rune(1, Element::EARTH);
    
    genChance[3] = 7 * 100;

    // 5
    gen[4].itemTypeEnum = ItemType::RUNE;
    gen[4].itemTypeUnion.rune = Rune(1, Element::AIR);
    
    genChance[4] = 14 * 100;

    // 6
    gen[5].itemTypeEnum = ItemType::RUNE;
    gen[5].itemTypeUnion.rune = Rune(5, Element::FIRE);
    
    genChance[5] = 0.6 * 100;

    // 7
    gen[6].itemTypeEnum = ItemType::RUNE;
    gen[6].itemTypeUnion.rune = Rune(5, Element::WATER);
    
    genChance[6] = 1.3 * 100;

    // 8
    gen[7].itemTypeEnum = ItemType::RUNE;
    gen[7].itemTypeUnion.rune = Rune(5, Element::EARTH);

    genChance[7] = 0.7 * 100;

    // 9
    gen[8].itemTypeEnum = ItemType::RUNE;
    gen[8].itemTypeUnion.rune = Rune(5, Element::AIR);

    genChance[8] = 1.4 * 100;

    // 10
    gen[9].itemTypeEnum = ItemType::RUNE;
    gen[9].itemTypeUnion.rune = Rune(10, Element::FIRE);
    
    genChance[9] = 0.06 * 100;

    // 11
    gen[10].itemTypeEnum = ItemType::RUNE;
    gen[10].itemTypeUnion.rune = Rune(10, Element::WATER);
    
    genChance[10] = 0.13 * 100;

    // 12
    gen[11].itemTypeEnum = ItemType::RUNE;
    gen[11].itemTypeUnion.rune = Rune(10, Element::EARTH);
    
    genChance[11] = 0.07 * 100;

    // 13
    gen[12].itemTypeEnum = ItemType::RUNE;
    gen[12].itemTypeUnion.rune = Rune(10, Element::AIR);
    
    genChance[12] = 0.14 * 100;

    // 14
    gen[13].itemTypeEnum = ItemType::WEAPON;
    gen[13].itemTypeUnion.weapon = Weapon(100, 0, 100);

    genChance[13] = 1.4 * 100;

    // 15
    gen[14].itemTypeEnum = ItemType::WEAPON;
    gen[14].itemTypeUnion.weapon = Weapon(75, 50, 100);

    genChance[14] = 1.4 * 100;

    // 16
    gen[15].itemTypeEnum = ItemType::ARMOR;
    gen[15].itemTypeUnion.armor = Armor(50, 100);

    genChance[15] = 2.8 * 100;


    int countCahnce = 100 * 100;

    int random = rand() % countCahnce;
    
    for (int i = 0; i < countItems; i++)
    {
        random -= genChance[i];
        if (random <= 0)
            return gen[i];
    }
    //return gen[0].first;
}

LootBox generateLootBox() {
    const int countLootBox = 3;
    
    LootBox box(countLootBox);
    for (int i = 0; i < countLootBox; i++)
    {
        box[i] = generateLoot();
    }
    
    return box;
}

int main()
{
    srand(time(NULL));

    std::cout << "Открыть лутбокс? Yes/No : ";
    std::string cin;

    do {
        std::cin >> cin;
        
        if (cin == "y" || cin == "Y" || cin == "yes" || cin == "Yes")
            std::cout << generateLootBox();
        
        if (cin == "n" || cin == "N" || cin == "no" || cin == "No")
            exit(1);
    } while (cin == "");
}
