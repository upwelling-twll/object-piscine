#ifndef COURSEBLUEPRINT_HPP
#define COURSEBLUEPRINT_HPP

struct CourseBlueprint {
    std::string name;
    int classesToGraduate;
    int maxStudents;
};

    static const std::vector<CourseBlueprint> HogwartsCourses = {
        
        {"Transfiguration", 30, 20},
        {"Charms", 28, 25},
        {"Potions", 32, 15}, // Snape prefers smaller, safer groups!
        {"History of Magic", 20, 50}, // Large lecture hall style
        {"Defence Against the Dark Arts", 30, 22},
        {"Astronomy", 15, 15}, // Limited by tower space and telescopes
        {"Herbology", 25, 20},
        {"Flying", 10, 20},
        {"Arithmancy", 24, 15},
        {"Muggle Studies", 20, 30},
        {"Divination", 22, 12}, // Trelawney's attic is quite small
        {"Study of Ancient Runes", 26, 15},
        {"Care of Magical Creatures", 25, 25},
        {"Alchemy", 35, 8}, // Highly specialized, very small group
        {"Apparition", 12, 30},
        {"Ancient Studies", 20, 15},
        {"Ghoul Studies", 18, 15},
        {"Magical Theory", 22, 20}
    };

#endif